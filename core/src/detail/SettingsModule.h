#include "IEnvironment.h"
#include "ISettingsModule.h"

#include <memory>
#include <string>

namespace opt::core {

class SettingsModule : public ISettingsModule {
public:
  explicit SettingsModule(std::shared_ptr<IEnvironment> env);

  std::string getData() const override;

  void setData(const std::string &data) override;

private:
  std::shared_ptr<IEnvironment> m_env;
  std::string m_data;
};

}; // namespace opt::core