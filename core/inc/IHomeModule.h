#pragma once

#include "ICoreModule.h"

namespace opt::core {

class IHomeModule : public ICoreModule {
public:
  virtual ~IHomeModule() = default;
  virtual std::string getData() const = 0;
  virtual void setData(const std::string &data) = 0;
};

}; // namespace opt::core
