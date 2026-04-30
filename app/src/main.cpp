#include "CoreFactory.h"
#include "Navigator.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  auto logger{opt::core::createLogger()};
  auto env{opt::core::createEnvironment(logger)};
  auto core{opt::core::createCore(env)};

  opt::ui::Navigator *navigator = new opt::ui::Navigator(core, &app);

  QQmlApplicationEngine engine;
  engine.addImportPath("qrc:/");
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

  engine.setInitialProperties({{"nav", QVariant::fromValue(navigator)}});
  engine.loadFromModule("optimus.ui", "Main");

  return app.exec();
}
