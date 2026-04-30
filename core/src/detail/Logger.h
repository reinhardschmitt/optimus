#include "ILogger.h"

namespace opt::core {

class Logger : public ILogger {
public:
  Logger();
  ~Logger();

  virtual void log(const std::string &message) override;
};

}; // namespace opt::core