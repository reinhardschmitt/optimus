#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace opt::ui {

class IViewModel : public QObject {
  Q_OBJECT
  QML_INTERFACE
public:
  IViewModel(QObject *parent = nullptr);
  virtual ~IViewModel() = default;
};

}; // namespace opt::ui
