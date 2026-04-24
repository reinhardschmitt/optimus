#include "ICore.h"

namespace opt::core {

class Core : public ICore {
public:
  std::string version() const override;
};

}; // namespace opt::core