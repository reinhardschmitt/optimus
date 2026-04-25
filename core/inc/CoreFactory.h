#include "ICore.h"

#include <memory>

namespace opt::core {

std::shared_ptr<ICore> createCore();

std::unique_ptr<IHomeModule> createHomeModule();

std::unique_ptr<IConfigModule> createConfigModule();

std::unique_ptr<ISettingsModule> createSettingsModule();

}