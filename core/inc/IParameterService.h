#pragma once

#include "ParameterTypes.h"

#include <vector>

namespace opt::core {

class IParameterService {
public:
  virtual ~IParameterService() = default;

  virtual std::string_view nameToken(ParameterId id) const = 0;
  virtual std::string_view categoryToken(ParameterId id) const = 0;
  virtual std::string_view descriptionToken(ParameterId id) const = 0;
  virtual ParameterValueT defaultValue(ParameterId id) const = 0;
  virtual ParameterValueT value(ParameterId id, ParameterRole role) const = 0;

  virtual void setValue(ParameterId id, ParameterRole role,
                        const ParameterValueT &value) = 0;

  virtual double torque(ParameterRole role) const = 0;
  virtual int stageCount(ParameterRole role) const = 0;
  virtual std::string_view password(ParameterRole role) const = 0;
  virtual bool flag(ParameterRole role) const = 0;

  virtual void setTorque(ParameterRole role, double value) = 0;
  virtual void setStageCount(ParameterRole role, int value) = 0;
  virtual void setPassword(ParameterRole role, std::string_view value) = 0;
  virtual void setFlag(ParameterRole role, bool value) = 0;

  virtual std::vector<std::string_view> categories() const = 0;
  virtual std::vector<ParameterId>
  parameters(std::string_view category) const = 0;
};

}; // namespace opt::core