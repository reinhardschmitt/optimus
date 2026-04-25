#pragma once

#include "ICoreModule.h"

namespace opt::core {

class IHomeModule : public ICoreModule {
public:
  virtual ~IHomeModule() = default;
};

}; // namespace opt::core
