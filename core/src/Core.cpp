#include "detail/Core.h"

#include <memory>

namespace opt::core {

std::string Core::version() const { return "1.0.0"; }

std::shared_ptr<IHomeModule> Core::homeModule() {
  if (!m_homeModule) {
    m_homeModule = std::make_shared<HomeModule>(std::shared_ptr<ICore>(this));
  }
  return m_homeModule;
}

std::shared_ptr<IConfigModule> Core::configModule() {
  if (!m_configModule) {
    m_configModule =
        std::make_shared<ConfigModule>(std::shared_ptr<ICore>(this));
  }
  return m_configModule;
}

std::shared_ptr<ISettingsModule> Core::settingsModule() {
  if (!m_settingsModule) {
    m_settingsModule =
        std::make_shared<SettingsModule>(std::shared_ptr<ICore>(this));
  }
  return m_settingsModule;
}

}; // namespace opt::core