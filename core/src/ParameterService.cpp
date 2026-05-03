#include "ParameterService.h"
#include "detail/ParameterCatalogue.h"

#include <vector>

namespace opt::core {

ParameterService::ParameterService() {
  for (const auto &item : ParameterCatalogue) {
    m_parameters.emplace_back(item);
  }
}

std::string_view ParameterService::nameToken(ParameterId id) const {
  return m_parameters.at(id).info.nameToken;
}

std::string_view ParameterService::categoryToken(ParameterId id) const {
  return m_parameters.at(id).info.categoryToken;
}

std::string_view ParameterService::descriptionToken(ParameterId id) const {
  return m_parameters.at(id).info.descriptionToken;
}

ParameterValueT ParameterService::defaultValue(ParameterId id) const {
  return m_parameters.at(id).info.defaultValue;
}

ParameterValueT ParameterService::value(ParameterId id,
                                        ParameterRole role) const {
  switch (role) {
  case ParameterRole::User:
    return m_parameters.at(id).userValue;
  case ParameterRole::Machine:
    return m_parameters.at(id).machineValue;
  }
}

void ParameterService::setValue(ParameterId id, ParameterRole role,
                                const ParameterValueT &value) {
  if (value.index() == defaultValue(id).index()) {
    switch (role) {
    case ParameterRole::User:
      m_parameters.at(id).userValue = value;
      break;
    case ParameterRole::Machine:
      m_parameters.at(id).machineValue = value;
      break;
    }
  }
}

double ParameterService::torque(ParameterRole role) const {
  return getDoubleValue(ParameterId::Torque, role);
}

int ParameterService::stageCount(ParameterRole role) const {
  return getIntValue(ParameterId::StageCount, role);
}

std::string_view ParameterService::password(ParameterRole role) const {
  return getStringValue(ParameterId::Password, role);
}

bool ParameterService::flag(ParameterRole role) const {
  return getBoolValue(ParameterId::Flag, role);
}

void ParameterService::setTorque(ParameterRole role, double value) {
  setValue(ParameterId::Torque, role, value);
}

void ParameterService::setStageCount(ParameterRole role, int value) {
  setValue(ParameterId::StageCount, role, value);
}

void ParameterService::setPassword(ParameterRole role, std::string_view value) {
  setValue(ParameterId::Password, role, value);
}

void ParameterService::setFlag(ParameterRole role, bool value) {
  setValue(ParameterId::Flag, role, value);
}

bool ParameterService::getBoolValue(ParameterId id, ParameterRole role) const {
  return std::get<bool>(value(id, role));
}

int ParameterService::getIntValue(ParameterId id, ParameterRole role) const {
  return std::get<int>(value(id, role));
}

double ParameterService::getDoubleValue(ParameterId id,
                                        ParameterRole role) const {
  return std::get<double>(value(id, role));
}

std::string_view ParameterService::getStringValue(ParameterId id,
                                                  ParameterRole role) const {
  return std::get<std::string_view>(value(id, role));
}

std::vector<std::string_view> ParameterService::categories() const {
  std::vector<std::string_view> result;
  for (int i = 0; i < static_cast<int>(ParameterId::ParameterIdCount); ++i) {
    const auto p = m_parameters.at(static_cast<ParameterId>(i));
    if (std::find(result.begin(), result.end(), p.info.categoryToken) ==
        result.end()) {
      result.push_back(p.info.categoryToken);
    }
  }
  return result;
}

std::vector<ParameterId>
ParameterService::parameters(std::string_view category) const {
  std::vector<ParameterId> result;
  for (int i = 0; i < static_cast<int>(ParameterId::ParameterIdCount); ++i) {
    const auto p = m_parameters.at(static_cast<ParameterId>(i));
    if (p.info.categoryToken == category) {
      result.push_back(p.info.id);
    }
  }
  return result;
}

}; // namespace opt::core