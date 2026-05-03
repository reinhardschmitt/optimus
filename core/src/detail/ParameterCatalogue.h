#pragma once

#include "ParameterTypes.h"

#include <array>

namespace opt::core {

struct ParameterCatalogueItem {
  ParameterId id;
  std::string_view nameToken;
  std::string_view categoryToken;
  std::string_view descriptionToken;
  ParameterValueT defaultValue;
};

struct Parameter {
  Parameter(const ParameterCatalogueItem &item)
      : info(item), userValue(item.defaultValue),
        machineValue(item.defaultValue) {};

  const ParameterCatalogueItem &info;
  ParameterValueT userValue;
  ParameterValueT machineValue;
};

// clang-format off

static const constexpr std::array<ParameterCatalogueItem, ParameterId::ParameterIdCount> ParameterCatalogue = {{
    {ParameterId::Torque,     "StrIdTorque",     "Motor",    "StrIdTorqueDescr"   , 0.0},
    {ParameterId::StageCount, "StrIdStageCount", "Motor",    "StrIdtageCountDescr", 1},
    {ParameterId::Password,   "StrIdPassword",   "Security", "StrIdPasswordDescr" , "default"},
    {ParameterId::Flag,       "StrIdFlag",       "General",  "StrIdFlagDescr"     , false}
}};

// clang-format on

} // namespace opt::core
