#pragma once

#include "ParameterCatalogue.h"

#include <vector>

namespace opt::core {

class Parameter {
public:
  Parameter(const ParameterCatalogueItem &item)
      : id(item), userValue(item.defaultValue),
        machineValue(item.defaultValue) {};
  const ParameterCatalogueItem &id;
  ParameterValueT userValue;
  ParameterValueT machineValue;
};

std::vector<Parameter> parameterMapFactory();

}; // namespace opt::core
