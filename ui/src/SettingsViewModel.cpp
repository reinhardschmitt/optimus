#include "detail/SettingsViewModel.h"

namespace opt::ui {

SettingsViewModel::SettingsViewModel(
    std::shared_ptr<opt::core::ISettingsModule> module, QObject *parent)
    : m_module(module) {}

QString SettingsViewModel::data() const {
  return QString::fromStdString(m_module->getData());
}

void SettingsViewModel::setData(const QString &msg) {
  m_module->setData(msg.toStdString());
  emit dataChanged();
}

} // namespace opt::ui
