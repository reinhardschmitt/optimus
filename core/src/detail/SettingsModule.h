#include "ICore.h"
#include "ISettingsModule.h"

#include <memory>
#include <string>

namespace opt::core {

class SettingsModule : public ISettingsModule {
public:
  explicit SettingsModule(std::shared_ptr<ICore> core);

  std::string getData() const override;

  void setData(const std::string &data) override;

private:
  std::shared_ptr<ICore> m_core;
  std::string m_data;
};

}; // namespace opt::core