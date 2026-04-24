#include "CoreFactory.h"
#include "Navigator.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  auto core{opt::core::createCore()};
  opt::ui::Navigator navigator{core};

  QQmlApplicationEngine engine;
  engine.addImportPath("qrc:/");
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

  engine.setInitialProperties({{"nav", QVariant::fromValue(&navigator)}});
  engine.loadFromModule("optimus.ui", "Main");

  return app.exec();
}
