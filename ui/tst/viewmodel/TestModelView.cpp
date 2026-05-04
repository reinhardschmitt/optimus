#include "IHomeModule.h"
#include "detail/HomeViewModel.h"
#include <QSignalSpy>
#include <QtTest>
#include <gmock/gmock.h>

class ModelViewTest : public QObject {
  Q_OBJECT
private slots:
  void dataTest() {
    auto mockModule = std::make_shared<MockHomeModule>();

    opt::ui::HomeViewModel model{mockModule};
    QSignalSpy spy(&model, &opt::ui::HomeViewModel::dataChanged);

    EXPECT_CALL(*mockModule, getData())
        .WillRepeatedly(::testing::Return("mock data"));
    QCOMPARE(model.data(), "mock data");

    EXPECT_CALL(*mockModule, setData(::testing::_)).Times(1);
    EXPECT_CALL(*mockModule, getData())
        .WillRepeatedly(::testing::Return("new data"));

    model.setData("new data");
    EXPECT_CALL(*mockModule, getData())
        .WillRepeatedly(::testing::Return("new data"));

    QCOMPARE(model.data(), "new data");
    QCOMPARE(spy.count(), 1);
  }

private:
  class MockHomeModule : public opt::core::IHomeModule {
  public:
    MOCK_METHOD(std::string, getData, (), (const, override));
    MOCK_METHOD(void, setData, (const std::string &), (override));
  };
};

QTEST_MAIN(ModelViewTest)
#include "TestModelView.moc"
