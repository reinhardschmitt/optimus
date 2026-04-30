#include "IEnvironment.h"
#include "ILogger.h"

namespace opt::core {

class Environment : public IEnvironment {
public:
  Environment(std::shared_ptr<ILogger> logger);
  ~Environment();

  virtual std::shared_ptr<ILogger> logger() const override;

private:
  std::shared_ptr<ILogger> m_logger;
};

}; // namespace opt::core