#include "ICore.h"
#include "IHomeModule.h"

#include <memory>
#include <string>

namespace opt::core {

class HomeModule : public IHomeModule {
public:
  explicit HomeModule(std::shared_ptr<ICore> core);

  std::string getData() const;

  void setData(const std::string &data);

private:
  std::shared_ptr<ICore> m_core;
  std::string m_data;
};

}; // namespace opt::core