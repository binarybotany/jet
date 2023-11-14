#ifndef JET_CORE_LOGGER_H_
#define JET_CORE_LOGGER_H_

#include <fstream>
#include <iostream>
#include <string>

namespace jet::core {
enum class log_level { debug, info, warning, error, fatal };

class logger final {
 public:
  logger(const std::string &filepath)
      : log_(filepath, std::ios::out | std::ios::app) {}

  void log(log_level level, const std::string &message);

 private:
  std::ofstream log_;
  std::string current_date_time() const;
  std::string level_to_string(log_level level) const;
};
}  // namespace jet::core

#endif