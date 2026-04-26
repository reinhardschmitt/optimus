#pragma once

#include "IConfigModule.h"
#include "IViewModel.h"

#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace opt::ui {

class ConfigViewModel : public IViewModel {
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("ViewModels can only be created by the Navigator C++ backend")
  Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
public:
  explicit ConfigViewModel(std::shared_ptr<opt::core::IConfigModule> module,
                           QObject *parent = nullptr);

  QString data() const;
  void setData(const QString &msg);

signals:
  void dataChanged();

private:
  std::shared_ptr<opt::core::IConfigModule> m_module;
};

} // namespace opt::ui
