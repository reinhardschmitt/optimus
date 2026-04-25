#pragma once

#include "IConfigModule.h"
#include "IHomeModule.h"
#include "ISettingsModule.h"

#include <memory>
#include <string>

namespace opt::core {

class ICore {
public:
  virtual ~ICore() = default;

  virtual std::string version() const = 0;
  virtual std::shared_ptr<IHomeModule> homeModule() = 0;
  virtual std::shared_ptr<IConfigModule> configModule() = 0;
  virtual std::shared_ptr<ISettingsModule> settingsModule() = 0;
};

}; // namespace opt::core
