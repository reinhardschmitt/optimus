#include "detail/HomeModule.h"

#include <sstream>

namespace opt::core {

HomeModule::HomeModule(std::shared_ptr<IEnvironment> env)
    : m_env(env), m_data("Home") {}

std::string HomeModule::getData() const { return m_data; }

void HomeModule::setData(const std::string &data) {
  std::stringstream logMessage;
  logMessage << "HomeModule: Setting data to '" << data << "'";
  m_env->logger()->log(logMessage.str());
  m_data = data;
}

}; // namespace opt::core