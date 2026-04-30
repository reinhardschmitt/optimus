#include "ConfigModule.h"
#include "HomeModule.h"
#include "ICore.h"
#include "ICoreModule.h"
#include "IEnvironment.h"
#include "SettingsModule.h"

namespace opt::core {

class Core : public ICore {
public:
  Core(std::shared_ptr<IEnvironment> env);

  std::string version() const override;

  std::shared_ptr<IHomeModule> homeModule() override;
  std::shared_ptr<IConfigModule> configModule() override;
  std::shared_ptr<ISettingsModule> settingsModule() override;

private:
  std::shared_ptr<IEnvironment> m_env;

  std::shared_ptr<HomeModule> m_homeModule;
  std::shared_ptr<ConfigModule> m_configModule;
  std::shared_ptr<SettingsModule> m_settingsModule;
};

}; // namespace opt::core