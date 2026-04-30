#pragma once

#include "ILogger.h"

#include <memory>

namespace opt::core {

class IEnvironment {
public:
  virtual ~IEnvironment() = default;
  virtual std::shared_ptr<ILogger> logger() const = 0;
};

}; // namespace opt::core