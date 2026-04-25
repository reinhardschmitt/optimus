#include "IConfigModule.h"
#include "ICore.h"

#include <memory>
#include <string>

namespace opt::core {

class ConfigModule : public IConfigModule {
public:
  explicit ConfigModule(std::shared_ptr<ICore> core);

  std::string getData() const override;

  void setData(const std::string &data) override;

private:
  std::shared_ptr<ICore> m_core;
  std::string m_data;
};

}; // namespace opt::core