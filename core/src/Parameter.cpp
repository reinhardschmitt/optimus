#include "detail/Parameter.h"

namespace opt::core {

std::vector<Parameter> parameterMapFactory() {
  std::vector<Parameter> instances;
  for (const auto &item : ParameterCatalogue) {
    instances.emplace_back(item);
  }
  return instances;
}

}; // namespace opt::core