#pragma once

#include <string>

namespace opt::core {

class ICore {
public:
  virtual ~ICore() = default;

  virtual std::string version() const = 0;
};

}; // namespace opt::core
