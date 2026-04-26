#include "detail/ConfigViewModel.h"

namespace opt::ui {

ConfigViewModel::ConfigViewModel(
    std::shared_ptr<opt::core::IConfigModule> module, QObject *parent)
    : m_module(module) {}

QString ConfigViewModel::data() const {
  return QString::fromStdString(m_module->getData());
}

void ConfigViewModel::setData(const QString &msg) {
  m_module->setData(msg.toStdString());
  emit dataChanged();
}

} // namespace opt::ui
