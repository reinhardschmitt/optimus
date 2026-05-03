#pragma once

#include "IParameterService.h"
#include "detail/ParameterCatalogue.h"

#include <memory>

namespace opt::core {

class ParameterService : public IParameterService {
public:
  ParameterService();
  virtual ~ParameterService() = default;

  std::string_view nameToken(ParameterId id) const override;
  std::string_view categoryToken(ParameterId id) const override;
  std::string_view descriptionToken(ParameterId id) const override;
  ParameterValueT defaultValue(ParameterId id) const override;
  ParameterValueT value(ParameterId id, ParameterRole role) const override;

  void setValue(ParameterId id, ParameterRole role,
                const ParameterValueT &value);

  double torque(ParameterRole role) const override;
  int stageCount(ParameterRole role) const override;
  std::string_view password(ParameterRole role) const override;
  bool flag(ParameterRole role) const override;

  void setTorque(ParameterRole role, double value) override;
  void setStageCount(ParameterRole role, int value) override;
  void setPassword(ParameterRole role, std::string_view value) override;
  void setFlag(ParameterRole role, bool value) override;

  std::vector<std::string_view> categories() const override;
  std::vector<ParameterId> parameters(std::string_view category) const override;

private:
  bool getBoolValue(ParameterId id, ParameterRole role) const;
  int getIntValue(ParameterId id, ParameterRole role) const;
  double getDoubleValue(ParameterId id, ParameterRole role) const;
  std::string_view getStringValue(ParameterId id, ParameterRole role) const;

  std::vector<Parameter> m_parameters;
};

}; // namespace opt::core