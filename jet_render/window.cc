#include "window.h"

#include <iostream>

using jet::core::log_level;

namespace jet::render {
void window::start_up() {
  if (!glfwInit()) {
    logger_->log(log_level::error, "Unable to initialize GLFW");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  glfw_window_ = glfwCreateWindow(640, 480, "Jet", nullptr, nullptr);
  if (glfw_window_ == nullptr) {
    logger_->log(log_level::error, "Unable to create window");
  }

  glfwMakeContextCurrent(glfw_window_);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    logger_->log(log_level::error, "Unable to initialize OpenGL 3.3 context");
  }

  while (!glfwWindowShouldClose(glfw_window_)) {
    glfwPollEvents();

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(glfw_window_);
  }
}

void window::shut_down() {
  if (glfw_window_ != nullptr) {
    glfwDestroyWindow(glfw_window_);
  }
  glfwTerminate();
}
}  // namespace jet::render