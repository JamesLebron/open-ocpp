/*
Copyright (c) 2020 Cedric Jimenez
This file is part of OpenOCPP.

OpenOCPP is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenOCPP is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OpenOCPP. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include "ISecurityManager.h"
#include "SecurityLogsDatabase.h"

namespace ocpp
{
// Forward declarations
namespace config
{
class IChargePointConfig;
} // namespace config
namespace messages
{
class IRequestFifo;
class GenericMessageSender;
} // namespace messages

// Main namespace
namespace chargepoint
{

/** @brief Handle security operations for the charge point */
class SecurityManager : public ISecurityManager
{
  public:
    /** @brief Constructor */
    SecurityManager(const ocpp::config::IChargePointConfig& stack_config,
                    ocpp::database::Database&               database,
                    ocpp::messages::GenericMessageSender&   msg_sender,
                    ocpp::messages::IRequestFifo&           requests_fifo);

    /** @brief Destructor */
    virtual ~SecurityManager();

    // ISecurityManager interface

    /** @copydoc bool ISecurityManager::logSecurityEvent(const std::string&, const std::string&, bool) */
    bool logSecurityEvent(const std::string& type, const std::string& message, bool critical = false) override;

    /** @copydoc bool ISecurityManager::clearSecurityEvents() */
    bool clearSecurityEvents() override;

    /** bool ISecurityManager::exportSecurityEvents(const std::string&,
                                                    const ocpp::types::Optional<ocpp::types::DateTime>&,
                                                    const ocpp::types::Optional<ocpp::types::DateTime>&) */
    bool exportSecurityEvents(const std::string&                                  filepath,
                              const ocpp::types::Optional<ocpp::types::DateTime>& start_time,
                              const ocpp::types::Optional<ocpp::types::DateTime>& stop_time) override;

  private:
    /** @brief Stack configuration */
    const ocpp::config::IChargePointConfig& m_stack_config;
    /** @brief Message sender */
    ocpp::messages::GenericMessageSender& m_msg_sender;
    /** @brief Transaction related requests FIFO */
    ocpp::messages::IRequestFifo& m_requests_fifo;

    /** @brief Security logs database */
    SecurityLogsDatabase m_security_logs_db;
};

} // namespace chargepoint
} // namespace ocpp

#endif // SECURITYMANAGER_H