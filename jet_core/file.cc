#include "file.h"

#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>

namespace jet::core {
file::file(std::shared_ptr<logger> logger, const std::string &filepath) {
  std::ifstream stream(filepath);
  if (!stream.is_open()) {
    std::string message("Unable to open file: ");
    message += filepath;
    logger->log(log_level::error, message);
  }

  std::stringstream buffer;
  buffer << stream.rdbuf();
  std::string contents = buffer.str();

  std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
  std::wstring wcontents = converter.from_bytes(contents);

  contents_ = std::string(wcontents.begin(), wcontents.end());
}

std::string file::contents() { return contents_; }
}  // namespace jet::core