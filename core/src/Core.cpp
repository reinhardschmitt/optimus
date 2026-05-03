#include "detail/Core.h"
#include "detail/ParameterService.h"

#include <memory>

namespace opt::core {

Core::Core(std::shared_ptr<IEnvironment> env,
           std::shared_ptr<IParameterService> parameterService)
    : m_env(env), m_parameterService(parameterService) {}

std::string Core::version() const { return "1.0.0"; }

std::shared_ptr<IHomeModule> Core::homeModule() {
  if (!m_homeModule) {
    m_homeModule = std::make_shared<HomeModule>(m_env);
  }
  return m_homeModule;
}

std::shared_ptr<IConfigModule> Core::configModule() {
  if (!m_configModule) {
    m_configModule = std::make_shared<ConfigModule>(m_env);
  }
  return m_configModule;
}

std::shared_ptr<ISettingsModule> Core::settingsModule() {
  if (!m_settingsModule) {
    m_settingsModule = std::make_shared<SettingsModule>(m_env);
  }
  return m_settingsModule;
}

}; // namespace opt::core