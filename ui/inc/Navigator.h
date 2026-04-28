#pragma once

#include "ICore.h"
#include "IViewModel.h"

#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace opt::ui {

class Navigator : public QObject {
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("Create in C++")

  Q_PROPERTY(IViewModel *currentViewModel READ currentViewModel NOTIFY
                 currentPageChanged)
  Q_PROPERTY(QString currentQml READ currentQml NOTIFY currentPageChanged)

public:
  explicit Navigator(std::shared_ptr<opt::core::ICore> core,
                     QObject *parent = nullptr);

  IViewModel *currentViewModel() const;
  QString currentQml() const;
  Q_INVOKABLE void initialize();
  Q_INVOKABLE void navigateToHome();
  Q_INVOKABLE void navigateToConfig();
  Q_INVOKABLE void navigateToSettings();

signals:
  void currentPageChanged();

private:
  struct Page {
    std::unique_ptr<IViewModel> viewModel = nullptr;
    QString qml;
    void change(std::unique_ptr<IViewModel> newViewModel,
                const QString &newQml) {
      viewModel = std::move(newViewModel);
      qml = newQml;
    }
  } m_page;

  std::shared_ptr<opt::core::ICore> m_core;
};
}; // namespace opt::ui
