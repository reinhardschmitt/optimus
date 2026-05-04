#include "IHomeModule.h"
#include "detail/HomeViewModel.h"
#include <QSignalSpy>
#include <QtTest>

class ModelViewTest : public QObject {
  Q_OBJECT
private slots:
  void initialValueTest() {
    auto mockModule = std::make_shared<MockHomeModule>();
    opt::ui::HomeViewModel model(mockModule);
    QCOMPARE(model.data(), "mock data");
  }
  void setDataTest() {
    auto mockModule = std::make_shared<MockHomeModule>();
    opt::ui::HomeViewModel model(mockModule);
    QSignalSpy spy(&model, &opt::ui::HomeViewModel::dataChanged);

    model.setData("new data");
    QCOMPARE(model.data(), "new data");
    QCOMPARE(spy.count(), 1);
  }
  void readDataTest() {
    auto mockModule = std::make_shared<MockHomeModule>();
    opt::ui::HomeViewModel model(mockModule);
    mockModule->setData("new data");
    QCOMPARE(model.data(), "new data");
  }

private:
  class MockHomeModule : public opt::core::IHomeModule {
  public:
    std::string getData() const override { return m_data; }
    void setData(const std::string &data) override { m_data = data; }

  private:
    std::string m_data{"mock data"};
  };
};

QTEST_MAIN(ModelViewTest)
#include "TestModelView.moc"
