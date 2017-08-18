#pragma once

#include "ServerLogics/ServerLogic.h"

class GameServerLogic : public ServerLogic
{
public:
	GameServerLogic();
	virtual ~GameServerLogic();
	virtual void SetInitParams(void *params);

protected:
	virtual void SetupModules();
	virtual void ClearInitParams();

	std::shared_ptr<ITimerModule> m_timer_module = nullptr;
};