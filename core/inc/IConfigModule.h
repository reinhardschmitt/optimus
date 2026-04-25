#pragma once

#include "ICoreModule.h"

namespace opt::core {

class IConfigModule : public ICoreModule {
public:
  virtual ~IConfigModule() = default;
  virtual std::string getData() const = 0;
  virtual void setData(const std::string &data) = 0;
};

}; // namespace opt::core
