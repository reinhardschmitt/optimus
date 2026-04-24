#include "CoreFactory.h"
#include "detail/Core.h"

namespace opt::core {

std::shared_ptr<ICore> createCore() {
  auto core = std::make_unique<Core>();
  return core;
};

}; // namespace opt::core