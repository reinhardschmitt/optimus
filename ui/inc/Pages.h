#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace opt::ui {

Q_NAMESPACE
QML_ELEMENT

enum class Page { Home, Settings, Config };

Q_ENUM_NS(Page)

} // namespace opt::ui
