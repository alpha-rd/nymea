/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright 2013 - 2020, nymea GmbH
* Contact: contact@nymea.io
*
* This file is part of nymea.
* This project including source code and documentation is protected by
* copyright law, and remains the property of nymea GmbH. All rights, including
* reproduction, publication, editing and translation, are reserved. The use of
* this project is subject to the terms of a license agreement to be concluded
* with nymea GmbH in accordance with the terms of use of nymea GmbH, available
* under https://nymea.io/license
*
* GNU General Public License Usage
* Alternatively, this project may be redistributed and/or modified under the
* terms of the GNU General Public License as published by the Free Software
* Foundation, GNU version 3. This project is distributed in the hope that it
* will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* this project. If not, see <https://www.gnu.org/licenses/>.
*
* For any further details and any questions please contact us under
* contact@nymea.io or see our FAQ/Licensing Information on
* https://nymea.io/license/faq
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*!
    \class nymeaserver::TokenInfo
    \brief This class holds information about an authentication token.

    \ingroup user
    \inmodule core

    The TokenInfo class holds information about a token used for authentication in the \l{nymeaserver::UserManager}{UserManager}.

    \sa TokenInfo, PushButtonDBusService
*/

#include "tokeninfo.h"

#include <QVariant>

namespace nymeaserver {

TokenInfo::TokenInfo()
{

}

/*! Constructs a new token info with the given \a id, \a username, \a creationTime and \a deviceName. */
TokenInfo::TokenInfo(const QUuid &id, const QString &username, const QDateTime &creationTime, const QString &deviceName):
    m_id(id),
    m_username(username),
    m_creationTime(creationTime),
    m_deviceName(deviceName)
{

}

/*! Returns the id of this TokenInfo. */
QUuid TokenInfo::id() const
{
    return m_id;
}

/*! Returns the userename of this TokenInfo. */
QString TokenInfo::username() const
{
    return m_username;
}

/*! Returns the creation time of this TokenInfo. */
QDateTime TokenInfo::creationTime() const
{
    return m_creationTime;
}

/*! Returns the device name of this TokenInfo. */
QString TokenInfo::deviceName() const
{
    return m_deviceName;
}

QVariant TokenInfoList::get(int index) const
{
    return QVariant::fromValue(at(index));
}

void TokenInfoList::put(const QVariant &variant)
{
    append(variant.value<TokenInfo>());
}

}
