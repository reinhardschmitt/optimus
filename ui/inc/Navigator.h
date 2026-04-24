#pragma once

#include "ICore.h"
#include "Pages.h"

#include <QObject>

namespace opt::ui {

class Navigator : public QObject {
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("Wird in C++ erstellt und injiziert")
  Q_PROPERTY(
      opt::ui::Page currentPage READ currentPage NOTIFY currentPageChanged)

public:
  explicit Navigator(std::shared_ptr<opt::core::ICore> core,
                     QObject *parent = nullptr);

  opt::ui::Page currentPage() const { return m_currentPage; }

  Q_INVOKABLE void navigateTo(Page p);

signals:
  void currentPageChanged();

private:
  std::shared_ptr<opt::core::ICore> m_core;
  opt::ui::Page m_currentPage = opt::ui::Page::Home;
};

}; // namespace opt::ui
