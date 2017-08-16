#include "LogModule.h"
#include "Modules/ModuleMgr.h"
#include "log/CsvLogConfig.h"
#include "Modules/Config/ConfigModule.h"

enum ELoggerType
{
	ELoggerType_Invalid = 0,
	ELoggerType_Stderr,
	ELoggerType_Stdout,
	ELoggerType_Common,
	ELoggerType_Rotating,
	ELoggerType_Daily,
	ELoggerType_Max,
};

LogModule::LogModule(std::shared_ptr<ModuleMgr> module_mgr) : ILogModule(module_mgr)
{

}

LogModule::~LogModule() 
{

}

EModuleRetCode LogModule::Init(void *param)
{
	if (EModuleState_Error == m_state)
		return EModuleRetCode_Failed;
	if (EModuleState_Inited == m_state)
		return EModuleRetCode_Succ;

	bool ret = true;
	do 
	{
		Config::CsvLogConfigSet cfg_set;
		std::string *file_path = (std::string *)param;
		ret = cfg_set.Load(*file_path);
		if (!ret || cfg_set.cfg_vec.size() < 2)
		{
			ret = false;
			break;
		}
		
		std::map<int, Config::CsvLogConfig *> cfg_map = cfg_set.id_to_key;
		int max_log_id = -1;
		Config::CsvLogConfig *stderr_cfg;
		Config::CsvLogConfig *stdout_cfg;
		for (auto kv_pair : cfg_map)
		{
			int logger_id = kv_pair.first;
			if (logger_id == LOGGER_ID_STDERR)
				stderr_cfg = kv_pair.second;
			if (logger_id == LOGGER_ID_STDOUT)
				stdout_cfg = kv_pair.second;
			if (logger_id > max_log_id)
				max_log_id = logger_id;
		}
		if (max_log_id < LOGGER_ID_STDERR || max_log_id < LOGGER_ID_STDOUT
			|| nullptr == stderr_cfg || nullptr == stdout_cfg)
		{
			ret = false;
			break;
		}

		// static const int QUEUE_SIZE = 1024 * 64;
		static const int QUEUE_SIZE = 32;
		spdlog::set_async_mode(QUEUE_SIZE);
		spdlog::set_level(spdlog::level::debug);

		m_logger_num = max_log_id + 1;
		m_log_datas = new LogData[m_logger_num];
		m_loggers = new std::shared_ptr<spdlog::logger>[m_logger_num];
		{
			m_loggers[LOGGER_ID_STDERR] = spdlog::stderr_color_mt(stderr_cfg->name);
			m_loggers[LOGGER_ID_STDERR]->set_level((spdlog::level::level_enum)stderr_cfg->log_level);
			m_log_datas[LOGGER_ID_STDERR].log_level = (ELogLevel)stderr_cfg->log_level;
		}
		{
			m_loggers[LOGGER_ID_STDOUT] = spdlog::stderr_color_mt(stdout_cfg->name);
			m_loggers[LOGGER_ID_STDOUT]->set_level((spdlog::level::level_enum)stdout_cfg->log_level);
			m_log_datas[LOGGER_ID_STDOUT].log_level = (ELogLevel)stdout_cfg->log_level;
		}

		for (auto kv_pair : cfg_map)
		{
			int logger_id = kv_pair.first;
			Config::CsvLogConfig *cfg = kv_pair.second;

			if (LOGGER_ID_STDERR == logger_id || LOGGER_ID_STDOUT == logger_id)
				continue;

			std::shared_ptr<spdlog::logger> logger = nullptr;
			switch (cfg->logger_type)
			{
			case ELoggerType_Stderr:
			{
				logger = spdlog::stderr_color_mt(cfg->name);
			}
			break;
			case ELoggerType_Stdout:
			{
				logger = spdlog::stdout_color_mt(cfg->name);
			}
			break;
			case ELoggerType_Common:
			{
				logger = spdlog::basic_logger_mt(cfg->name, cfg->save_file, false);
			}
			break;
			case ELoggerType_Rotating:
			{
				logger = spdlog::rotating_logger_mt(cfg->name,
					cfg->save_file, cfg->rorating_max_size, cfg->rorating_max_files);
			}
			break;
			case ELoggerType_Daily:
			{
				logger = spdlog::daily_logger_mt(cfg->name,
					cfg->save_file, cfg->daily_hour, cfg->daily_min);
			}
			break;
			}
			if (nullptr == logger)
			{
				ret = false;
				break;
			}
			logger->set_level((spdlog::level::level_enum)cfg->log_level);
			m_loggers[logger_id] = logger;
			m_log_datas[logger_id].log_level = (ELogLevel)cfg->log_level;
		}

		for (int i = 0; i < m_logger_num; ++i)
		{
			LogData &data = m_log_datas[i];
			data.log_id = i;
			std::shared_ptr<spdlog::logger> logger = m_loggers[i];
			if (nullptr == logger)
				continue;
			data.write_loggers.insert(logger);
			for (auto kv_pair : cfg_map)
			{
				int logger_id = kv_pair.first;
				Config::CsvLogConfig *cfg = kv_pair.second;
				if (logger_id == data.log_id)
					continue;
				std::shared_ptr<spdlog::logger> tmp_logger = m_loggers[logger_id];
				if (nullptr == tmp_logger)
					continue;
				for (int writer_id : cfg->alsoWritetoMe)
				{
					if (-1 == writer_id || data.log_id == writer_id)
					{
						// 写到标准错误的内容不要同时写到标准输出
						if (data.log_id == LOGGER_ID_STDERR && cfg->id == LOGGER_ID_STDOUT)
							continue;
						// 写到标准输出的内容不要同时写到标准错误
						if (data.log_id == LOGGER_ID_STDOUT && cfg->id == LOGGER_ID_STDERR)
							continue;
						data.write_loggers.insert(tmp_logger);
						break;
					}
				}
			}
		}
	} while (false);

	m_state = ret ? EModuleState_Inited : EModuleState_Error;
	return ret ? EModuleRetCode_Succ : EModuleRetCode_Failed;
}

EModuleRetCode LogModule::Awake()
{
	return EModuleRetCode_Succ;
}

EModuleRetCode LogModule::Update()
{
	return EModuleRetCode_Succ;
}

EModuleRetCode LogModule::Release()
{
	return EModuleRetCode_Succ;
}

EModuleRetCode LogModule::Destroy()
{
	delete[]m_log_datas; m_log_datas = nullptr;
	for (int i = 0; i < m_logger_num; ++i)
	{
		m_loggers[i] = nullptr;
	}
	m_logger_num = 0;
	delete[]m_loggers; m_loggers = nullptr;
	spdlog::drop_all();
	return EModuleRetCode_Succ;
}
