#pragma once

#include <string_view>
#include <variant>

constexpr enum ParameterId : size_t {
  Torque = 0,
  StageCount,
  Password,
  Flag,
  ParameterIdCount
};

constexpr enum ParameterRole : size_t { User = 0, Machine };

using ParameterValueT = std::variant<bool, int, double, std::string_view>;