#include "navigator.h"
#include "detail/ConfigViewModel.h"
#include "detail/HomeViewModel.h"
#include "detail/SettingsViewModel.h"

namespace opt::ui {

Navigator::Navigator(std::shared_ptr<opt::core::ICore> core, QObject *parent)
    : QObject(parent), m_core(std::move(core)) {}

IViewModel *Navigator::currentViewModel() const {
  return m_page.viewModel.get();
}

QString Navigator::currentQml() const { return m_page.qml; }

void Navigator::initialize() { navigateToHome(); }

void Navigator::navigateToHome() {
  m_page.change(std::make_unique<HomeViewModel>(m_core->homeModule()),
                "Home.qml");
  emit currentPageChanged();
}

void Navigator::navigateToConfig() {
  m_page.change(std::make_unique<ConfigViewModel>(m_core->configModule()),
                "Config.qml");
  emit currentPageChanged();
}

void Navigator::navigateToSettings() {
  m_page.change(std::make_unique<SettingsViewModel>(m_core->settingsModule()),
                "Settings.qml");
  emit currentPageChanged();
}

} // namespace opt::ui
