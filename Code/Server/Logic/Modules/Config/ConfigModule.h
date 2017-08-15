#pragma once

#include "IConfigModule.h"

class ConfigModule : public IConfigModule
{
public:
	ConfigModule(std::shared_ptr<ModuleMgr> module_mgr);
	virtual ~ConfigModule();
	virtual EModuleRetCode Init(void *param);
	virtual EModuleRetCode Awake(void *param);
	virtual EModuleRetCode Update(void *param);
	virtual EModuleRetCode Release(void *param);
	virtual EModuleRetCode Destroy(void *param);
};