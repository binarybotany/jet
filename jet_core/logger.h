#ifndef JET_CORE_LOGGER_H_
#define JET_CORE_LOGGER_H_

#include <fstream>
#include <iostream>
#include <string>

namespace jet::core {
enum class log_level { debug, info, warning, error, fatal };

class logger final {
 public:
  void set_file(const std::string &filepath);

  void log(log_level level, const std::string &message);

 private:
  std::string filepath_;

  std::string current_date_time();

  std::string level_to_string(log_level level);
};
}  // namespace jet::core

#endif