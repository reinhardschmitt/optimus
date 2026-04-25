#pragma once

#include "ICoreModule.h"

namespace opt::core {

class IConfigModule : public ICoreModule {
public:
  virtual ~IConfigModule() = default;
};

}; // namespace opt::core
