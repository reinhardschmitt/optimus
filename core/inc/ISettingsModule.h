#pragma once

#include "ICoreModule.h"

#include <string>

namespace opt::core {

class ISettingsModule : public ICoreModule {
public:
  virtual ~ISettingsModule() = default;
  virtual std::string getData() const = 0;
  virtual void setData(const std::string &data) = 0;
};

}; // namespace opt::core
