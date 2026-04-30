#include "IEnvironment.h"
#include "ILogger.h"
#include <gmock/gmock.h>

namespace opt::core {

class MockEnvironment : public IEnvironment {
public:
  MOCK_METHOD(std::shared_ptr<ILogger>, logger, (), (const, override));
};

} // namespace opt::core
