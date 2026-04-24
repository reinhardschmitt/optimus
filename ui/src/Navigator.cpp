#include "navigator.h"

namespace opt::ui {

Navigator::Navigator(std::shared_ptr<opt::core::ICore> core, QObject *parent)
    : QObject(parent), m_core(std::move(core)) // Dependency Injection des Cores
      ,
      m_currentPage(opt::ui::Page::Home) {}

void Navigator::navigateTo(Page p) {
  if (m_currentPage == p) {
    return;
  }

  m_currentPage = p;
  emit currentPageChanged();
}

} // namespace opt::ui
