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
  Q_PROPERTY(QString currentQml READ currentQml NOTIFY currentQmlChanged)

public:
  explicit Navigator(std::shared_ptr<opt::core::ICore> core,
                     QObject *parent = nullptr);

  IViewModel *currentViewModel() const;
  QString currentQml() const;
  Q_INVOKABLE void navigateToHome();
  Q_INVOKABLE void navigateToConfig();
  Q_INVOKABLE void navigateToSettings();

signals:
  void currentViewModelChanged();
  void currentQmlChanged();

private:
  std::shared_ptr<opt::core::ICore> m_core;
  IViewModel *m_currentViewModel;
  QString m_currentQml;
};

}; // namespace opt::ui
