#include "navigator.h"
#include "detail/ConfigViewModel.h"
#include "detail/HomeViewModel.h"
#include "detail/SettingsViewModel.h"

namespace opt::ui {

Navigator::Navigator(std::shared_ptr<opt::core::ICore> core, QObject *parent)
    : QObject(parent), m_core(std::move(core)) {
  navigateToHome();
}

IViewModel *Navigator::currentViewModel() const { return m_currentViewModel; }

QString Navigator::currentQml() const { return m_currentQml; }

void Navigator::navigateToHome() {
  auto homeModule = m_core->homeModule();

  m_currentViewModel = new HomeViewModel(homeModule, this);
  emit currentViewModelChanged();

  m_currentQml = "Home.qml";
  emit currentQmlChanged();
}

void Navigator::navigateToConfig() {
  auto configModule = m_core->configModule();

  m_currentViewModel = new ConfigViewModel(configModule, this);
  emit currentViewModelChanged();

  m_currentQml = "Config.qml";
  emit currentQmlChanged();
}

void Navigator::navigateToSettings() {
  auto settingsModule = m_core->settingsModule();

  m_currentViewModel = new SettingsViewModel(settingsModule, this);
  emit currentViewModelChanged();

  m_currentQml = "Settings.qml";
  emit currentQmlChanged();
}

} // namespace opt::ui
