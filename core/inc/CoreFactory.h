#include "ICore.h"
#include "IEnvironment.h"
#include "ILogger.h"

#include <memory>

namespace opt::core {

std::shared_ptr<ICore> createCore(std::shared_ptr<IEnvironment> env);

std::shared_ptr<IEnvironment> createEnvironment(std::shared_ptr<ILogger> log);

std::shared_ptr<ILogger> createLogger();

} // namespace opt::core