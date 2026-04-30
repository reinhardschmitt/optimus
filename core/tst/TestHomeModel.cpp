#include "HomeModule.h"
#include "MockEnvironment.h"
#include "MockLogger.h"
#include <gtest/gtest.h>

namespace opt::core {

using namespace ::testing;

class HomeModuleTest : public Test {
protected:
  void SetUp() override {
    envMock = std::make_shared<NiceMock<MockEnvironment>>();
    loggerMock = std::make_shared<NiceMock<MockLogger>>();

    // Standard-Verhalten: Wenn env->logger() gerufen wird, gib den Mock zurück
    ON_CALL(*envMock, logger()).WillByDefault(Return(loggerMock));

    homeModule = std::make_unique<HomeModule>(envMock);
  }

  std::shared_ptr<MockEnvironment> envMock;
  std::shared_ptr<MockLogger> loggerMock;
  std::unique_ptr<HomeModule> homeModule;
};

// Testet den Standardwert nach der Konstruktion
TEST_F(HomeModuleTest, ReturnsInitialData) {
  EXPECT_EQ(homeModule->getData(), "Home");
}

TEST_F(HomeModuleTest, SetDataLogsCorrectMessageAndUpdatesState) {
  std::string testData = "Kitchen";

  // 1. Erwartung: Der Logger muss genau einmal mit diesem Text gerufen werden
  std::string expectedLog = "HomeModule: Setting data to 'Kitchen'";
  EXPECT_CALL(*loggerMock, log(expectedLog)).Times(1);

  // 2. Aktion
  homeModule->setData(testData);

  // 3. Status prüfen
  EXPECT_EQ(homeModule->getData(), testData);
}

// Optional: Test für leere Strings, um Robustheit zu prüfen
TEST_F(HomeModuleTest, SetDataLogsEmptyStringCorrectly) {
  EXPECT_CALL(*loggerMock, log("HomeModule: Setting data to ''")).Times(1);

  homeModule->setData("");

  EXPECT_EQ(homeModule->getData(), "");
}

} // namespace opt::core
