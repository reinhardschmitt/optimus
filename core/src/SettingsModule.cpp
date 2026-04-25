#include "detail/SettingsModule.h"

namespace opt::core {

SettingsModule::SettingsModule(std::shared_ptr<ICore> core)
    : m_core(std::move(core)), m_data("Settings") {}

std::string SettingsModule::getData() const { return m_data; }

void SettingsModule::setData(const std::string &data) { m_data = data; }

}; // namespace opt::core