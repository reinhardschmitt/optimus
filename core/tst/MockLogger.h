#include "ILogger.h"
#include <gmock/gmock.h>

namespace opt::core {

class MockLogger : public ILogger {
public:
  MOCK_METHOD(void, log, (const std::string &message), (override));
};

} // namespace opt::core
