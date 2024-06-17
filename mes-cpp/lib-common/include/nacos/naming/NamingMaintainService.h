#ifndef __NAM_MAINTN_SVC_H_
#define __NAM_MAINTN_SVC_H_

#include <list>
#include "Instance.h"
#include "ServiceInfo2.h"
#include "../NacosString.h"
#include "../NacosExceptions.h"
#include "ListView.h"
#include "../Compatibility.h"

namespace nacos{
class NamingMaintainService {
public:
    virtual bool updateInstance(const NacosString &serviceName, const NacosString & groupName, const Instance &instance) NACOS_THROW(NacosException) = 0;
    virtual ServiceInfo2 queryService(const NacosString &serviceName, const NacosString &groupName) NACOS_THROW(NacosException) = 0;
    virtual bool createService(const ServiceInfo2 &service, naming::Selector *selector) NACOS_THROW(NacosException) = 0;
    virtual bool deleteService(const NacosString &serviceName, const NacosString &groupName) NACOS_THROW(NacosException) = 0;
    virtual bool updateService(const ServiceInfo2 &service, naming::Selector *selector) NACOS_THROW(NacosException) = 0;
    virtual ~NamingMaintainService() {};
};
}//namespace nacos

#endif