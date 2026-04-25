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
                 currentViewModelChanged)

public:
  explicit Navigator(std::shared_ptr<opt::core::ICore> core,
                     QObject *parent = nullptr);

  IViewModel *currentViewModel() const;

  Q_INVOKABLE void navigateToHome();
  Q_INVOKABLE void navigateToConfig();
  Q_INVOKABLE void navigateToSettings();

signals:
  void currentViewModelChanged();

private:
  std::shared_ptr<opt::core::ICore> m_core;
  std::unique_ptr<IViewModel> m_currentViewModel;
};

}; // namespace opt::ui
