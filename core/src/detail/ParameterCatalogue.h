#pragma once

#include <array>
#include <string_view>
#include <variant>

namespace opt::core {

using ParameterValueT = std::variant<bool, int, double, std::string_view>;

struct ParameterCatalogueItem {
  enum Id : int { Torque = 0, StageCount, Password, Flag, ParameterIdCount };

  Id id;
  std::string_view nameToken;
  std::string_view categoryToken;
  std::string_view descriptionToken;
  ParameterValueT defaultValue;
};

// clang-format off

static const constexpr std::array<ParameterCatalogueItem, ParameterCatalogueItem::ParameterIdCount> ParameterCatalogue = {{
    {ParameterCatalogueItem::Torque,     "StrIdTorque",     "Motor",    "StrIdTorqueDescr"   , 0.0},
    {ParameterCatalogueItem::StageCount, "StrIdStageCount", "Motor",    "StrIdtageCountDescr", 1},
    {ParameterCatalogueItem::Password,   "StrIdPassword",   "Security", "StrIdPasswordDescr" , "default"},
    {ParameterCatalogueItem::Flag,       "StrIdFlag",       "General",  "StrIdFlagDescr"     , false}
}};

// clang-format on

} // namespace opt::core
