/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/20 16:28:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "pch.h"
#include "IpUtil.h"
#include <cstdlib>
#include <stdexcept>
#include <array>

#ifndef LINUX
#include <winsock2.h>
#include <ws2ipdef.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#else
#include <unistd.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#endif

size_t IpUtil::getLocalIpAddress(std::vector<std::string>* addresses)
{
#ifndef LINUX
	PIP_ADAPTER_ADDRESSES adapter_addresses = nullptr;
	ULONG buffer_size = 0;
	if (GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, nullptr, nullptr, &buffer_size) == ERROR_BUFFER_OVERFLOW) {
		adapter_addresses = static_cast<PIP_ADAPTER_ADDRESSES>(malloc(buffer_size));
		if (adapter_addresses == nullptr) {
			throw std::runtime_error("Failed to allocate memory for adapter addresses.");
		}
		if (GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, nullptr, adapter_addresses, &buffer_size) == NO_ERROR) {
			for (auto adapter = adapter_addresses; adapter != nullptr; adapter = adapter->Next) {
				for (auto unicast = adapter->FirstUnicastAddress; unicast != nullptr; unicast = unicast->Next) {
					sockaddr* address = unicast->Address.lpSockaddr;
					if (address->sa_family == AF_INET) {
						char ip_buffer[INET_ADDRSTRLEN];
						if (inet_ntop(AF_INET, &reinterpret_cast<sockaddr_in*>(address)->sin_addr, ip_buffer, sizeof(ip_buffer))) {
							addresses->emplace_back(ip_buffer);
						}
					}
					else if (address->sa_family == AF_INET6) {
						char ip_buffer[INET6_ADDRSTRLEN];
						if (inet_ntop(AF_INET6, &reinterpret_cast<sockaddr_in6*>(address)->sin6_addr, ip_buffer, sizeof(ip_buffer))) {
							addresses->emplace_back(ip_buffer);
						}
					}
				}
			}
		}
		free(adapter_addresses);
	}
#else
	struct ifaddrs* ifap;
	if (getifaddrs(&ifap) == 0) {
		for (struct ifaddrs* ifa = ifap; ifa != nullptr; ifa = ifa->ifa_next) {
			if (ifa->ifa_addr != nullptr) {
				if (ifa->ifa_addr->sa_family == AF_INET) {
					struct sockaddr_in* sa = reinterpret_cast<struct sockaddr_in*>(ifa->ifa_addr);
					char ip_buffer[INET_ADDRSTRLEN];
					if (inet_ntop(AF_INET, &(sa->sin_addr), ip_buffer, sizeof(ip_buffer))) {
						addresses->emplace_back(ip_buffer);
					}
				}
				else if (ifa->ifa_addr->sa_family == AF_INET6) {
					struct sockaddr_in6* sa = reinterpret_cast<struct sockaddr_in6*>(ifa->ifa_addr);
					char ip_buffer[INET6_ADDRSTRLEN];
					if (inet_ntop(AF_INET6, &(sa->sin6_addr), ip_buffer, sizeof(ip_buffer))) {
						addresses->emplace_back(ip_buffer);
					}
				}
			}
		}
		freeifaddrs(ifap);
	}
#endif
	return addresses->size();
}
