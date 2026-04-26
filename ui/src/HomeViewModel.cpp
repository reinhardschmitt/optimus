#include "detail/HomeViewModel.h"

namespace opt::ui {

HomeViewModel::HomeViewModel(std::shared_ptr<opt::core::IHomeModule> module,
                             QObject *parent)
    : m_module(module) {}

QString HomeViewModel::data() const {
  return QString::fromStdString(m_module->getData());
}

void HomeViewModel::setData(const QString &msg) {
  m_module->setData(msg.toStdString());
  emit dataChanged();
}

} // namespace opt::ui
