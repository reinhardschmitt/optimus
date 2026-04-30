#include <QtTest>

class ModelViewTest : public QObject {
  Q_OBJECT
private slots:
  void simpleTest() { QCOMPARE(1, 1); }
};

QTEST_MAIN(ModelViewTest)
#include "TestModelView.moc"
