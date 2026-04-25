#include "detail/HomeModule.h"

namespace opt::core {

HomeModule::HomeModule(std::shared_ptr<ICore> core)
    : m_core(std::move(core)), m_data("Home") {}

std::string HomeModule::getData() const { return m_data; }

void HomeModule::setData(const std::string &data) { m_data = data; }

}; // namespace opt::core