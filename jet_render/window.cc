#include "window.h"

#include <iostream>

using jet::core::log_level;

namespace jet::render {
void window::start_up() {
  logger_->log(log_level::info, "Starting up window");

  if (!glfwInit()) {
    logger_->log(log_level::error, "Unable to initialize GLFW");
  }
}

void window::shut_down() { glfwTerminate(); }
}  // namespace jet::render