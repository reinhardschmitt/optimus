#include <gtest/gtest.h>

#include "Core.h"
#include "CoreFactory.h"

TEST(SampleCoreTest, BasicAssertion) { EXPECT_EQ(1, 1); }

TEST(SampleCoreTest, Factory) {
  auto core = opt::core::createCore();
  EXPECT_NE(core, nullptr);
}
