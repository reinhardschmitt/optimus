#pragma once

#include <string>

namespace opt::core {

class ILogger {
public:
  virtual ~ILogger() = default;
  virtual void log(const std::string &message) = 0;
};

}; // namespace opt::core