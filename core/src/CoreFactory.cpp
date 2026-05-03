#include "CoreFactory.h"
#include "detail/Core.h"
#include "detail/Environment.h"
#include "detail/Logger.h"
#include "detail/ParameterService.h"

namespace opt::core {

std::shared_ptr<ICore> createCore(std::shared_ptr<IEnvironment> env) {
  auto parameterService = std::make_shared<ParameterService>();
  auto core = std::make_unique<Core>(env, parameterService);
  return core;
};

std::shared_ptr<IEnvironment> createEnvironment(std::shared_ptr<ILogger> log) {
  auto env = std::make_unique<Environment>(log);
  return env;
}

std::shared_ptr<ILogger> createLogger() {
  auto logger = std::make_unique<Logger>();
  return logger;
}

}; // namespace opt::core