#include "navigator.h"

namespace opt::ui {

Navigator::Navigator(std::shared_ptr<opt::core::ICore> core, QObject *parent)
    : QObject(parent), m_core(std::move(core)), m_currentViewModel(nullptr) {}

IViewModel *Navigator::currentViewModel() const {
  return m_currentViewModel.get();
}

void Navigator::navigateToHome() {
  auto homeModule = m_core->homeModule();
  m_currentViewModel = nullptr;
  emit currentViewModelChanged();
}

void Navigator::navigateToConfig() {
  m_currentViewModel = nullptr;
  emit currentViewModelChanged();
}

void Navigator::navigateToSettings() {
  m_currentViewModel = nullptr;
  emit currentViewModelChanged();
}

} // namespace opt::ui
