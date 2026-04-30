#include "detail/Environment.h"

#include <memory>

namespace opt::core {

Environment::Environment(std::shared_ptr<ILogger> logger) : m_logger(logger) {}

Environment::~Environment() {}

std::shared_ptr<ILogger> Environment::logger() const { return m_logger; }

}; // namespace opt::core