#ifndef JET_CORE_FILE_H_
#define JET_CORE_FILE_H_

#include <memory>
#include <string>

#include "logger.h"

namespace jet::core {
class file final {
 public:
  explicit file(std::shared_ptr<logger> logger, const std::string &filepath);
  std::string contents();

 private:
  std::string contents_;
};
}  // namespace jet::core

#endif