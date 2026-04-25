#include "navigator.h"
#include "detail/ConfigViewModel.h"
#include "detail/HomeViewModel.h"
#include "detail/SettingsViewModel.h"

namespace opt::ui {

Navigator::Navigator(std::shared_ptr<opt::core::ICore> core, QObject *parent)
    : QObject(parent), m_core(std::move(core)), m_currentViewModel(nullptr) {}

IViewModel *Navigator::currentViewModel() const {
  return m_currentViewModel.get();
}

void Navigator::navigateToHome() {
  auto homeModule = m_core->homeModule();
  m_currentViewModel = std::make_unique<HomeViewModel>(homeModule, this);
  emit currentViewModelChanged();
}

void Navigator::navigateToConfig() {
  auto configModule = m_core->configModule();
  m_currentViewModel = std::make_unique<ConfigViewModel>(configModule, this);
  emit currentViewModelChanged();
}

void Navigator::navigateToSettings() {
  auto settingsModule = m_core->settingsModule();
  m_currentViewModel =
      std::make_unique<SettingsViewModel>(settingsModule, this);
  emit currentViewModelChanged();
}

} // namespace opt::ui
