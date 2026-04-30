#include "detail/Logger.h"

#include <iostream>

namespace opt::core {

Logger::Logger() {}

Logger::~Logger() {}

void Logger::log(const std::string &message) {
  std::cout << "[LOG] " << message << std::endl;
}

}; // namespace opt::core