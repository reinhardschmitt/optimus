#pragma once

#include "ICoreModule.h"

namespace opt::core {

class ISettingsModule : public ICoreModule {
public:
  virtual ~ISettingsModule() = default;
};

}; // namespace opt::core
