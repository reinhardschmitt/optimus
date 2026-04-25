#include "detail/ConfigModule.h"

namespace opt::core {

ConfigModule::ConfigModule(std::shared_ptr<ICore> core)
    : m_core(std::move(core)), m_data("Config") {}

std::string ConfigModule::getData() const { return m_data; }

void ConfigModule::setData(const std::string &data) { m_data = data; }

}; // namespace opt::core