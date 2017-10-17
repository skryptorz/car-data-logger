/*
* Copyright (C) 2017, IVIS
*
* This file is part of GENIVI Project CDL - Car Data Logger.
*
* This Source Code Form is subject to the terms of the
* Mozilla Public License (MPL), v. 2.0.
* If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/.
*
* For further information see http://www.genivi.org/.
*/

/*!
* \author Seok-Heum Choi <seokheum.choi@ivisolution.com>
*
* \copyright Copyright (c) 2017, IVIS \n
* License MPL-2.0: Mozilla Public License version 2.0 http://mozilla.org/MPL/2.0/.
*
*/

#include "on_board_provider_dbus_service.hpp"

OnBoardProviderDBusService::OnBoardProviderDBusService(OnBoardProviderService *onBoardProviderService)
    :m_onBoardProviderService(onBoardProviderService)
{

}

OnBoardProviderDBusService::~OnBoardProviderDBusService()
{

}

void OnBoardProviderDBusService::registerClient(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _key, registerClientReply_t _reply)
{
    ClientAPITypes::Handle handleOut;
    ClientAPITypes::ResultCode result;

    m_onBoardProviderService->registerClient(RunTimeType::RUNTIME_DBUS, _client, _key, handleOut, result);

    _reply(handleOut, result);
}

void OnBoardProviderDBusService::setListenData(const std::shared_ptr<CommonAPI::ClientId> _client, ClientAPITypes::Handle _handle, std::vector<std::string> _signalNameList, ClientAPITypes::NotifyType _type, setListenDataReply_t _reply)
{
    ClientAPITypes::ResultCode result;

    m_onBoardProviderService->setListenData(_client, _handle, _signalNameList, _type, result);

    _reply(result);
}

void OnBoardProviderDBusService::getData(const std::shared_ptr<CommonAPI::ClientId> _client, ClientAPITypes::Handle _handle, string _signalName, ClientAPIStub::getDataReply_t _reply)
{
    ClientAPITypes::ResultCode result;

    m_onBoardProviderService->getData(_client, _handle, _signalName, result);

    _reply(result);
}