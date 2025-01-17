/*
Copyright (c) 2020 Cedric Jimenez
This file is part of OpenOCPP.

OpenOCPP is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

OpenOCPP is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OpenOCPP. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPENOCPP_ICENTRALSYSTEMEVENTSHANDLER_H
#define OPENOCPP_ICENTRALSYSTEMEVENTSHANDLER_H

#include "ICentralSystem.h"

namespace ocpp
{
namespace centralsystem
{

/** @brief Interface for central system event handlers implementations */
class ICentralSystemEventsHandler
{
  public:
    /** @brief Destructor */
    virtual ~ICentralSystemEventsHandler() { }

    /**
     * @brief Called to accept an incoming connection
     * @param ip_address IP address of the client
     * @return true if the incoming connection must be accepted, false otherwise
     */
    virtual bool acceptConnection(const char* ip_address) = 0;

    /**
     * @brief Called to check the charge point credentials for HTTP basic authentication
     * @param chargepoint_id Charge Point identifier
     * @param password Password
     * @return true if the credentials are valid, false otherwise
     */
    virtual bool checkCredentials(const std::string& chargepoint_id, const std::string& password) = 0;

    /**
     * @brief Called when a charge point is connected
     * @param chargepoint Charge point connection
     */
    virtual void chargePointConnected(std::shared_ptr<ICentralSystem::IChargePoint> chargepoint) = 0;
};

} // namespace centralsystem
} // namespace ocpp

#endif // OPENOCPP_ICENTRALSYSTEMEVENTSHANDLER_H
