#pragma once

#include "ISettingsModule.h"
#include "IViewModel.h"

#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace opt::ui {

class SettingsViewModel : public IViewModel {
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("ViewModels can only be created by the Navigator C++ backend")
  Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
public:
  explicit SettingsViewModel(std::shared_ptr<opt::core::ISettingsModule> module,
                             QObject *parent = nullptr);

  QString data() const;
  void setData(const QString &msg);

signals:
  void dataChanged();

private:
  std::shared_ptr<opt::core::ISettingsModule> m_module;
};

} // namespace opt::ui
