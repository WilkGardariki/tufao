/*  This file is part of the Tufão project
    Copyright (C) 2011 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any
    later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TUFAO_SERVER_H
#define TUFAO_SERVER_H

#include <QtCore/QObject>
#include <QtNetwork/QHostAddress>
#include "tufao_global.h"

class QAbstractSocket;

namespace Tufao {

class HttpServerRequest;
class HttpServerResponse;

class TUFAOSHARED_EXPORT HttpServer : public QObject
{
    Q_OBJECT
public:
    explicit HttpServer(QObject *parent = 0);

    bool listen(const QHostAddress &address = QHostAddress::Any,
                quint16 port = 0);

signals:
    void request(HttpServerRequest *request, HttpServerResponse *response);

public slots:
    void close();

protected:
    virtual void upgrade(HttpServerRequest *request, QAbstractSocket *socket,
                         const QByteArray &head);
};

} // namespace Tufao

#endif // TUFAO_SERVER_H
