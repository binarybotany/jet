#ifndef JET_RENDER_WINDOW_H_
#define JET_RENDER_WINDOW_H_

#include <memory>

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <jet/core.h>

namespace jet::render {
class window final {
 public:
  window(std::shared_ptr<jet::core::logger> logger) : logger_(logger) {}

  void start_up();
  void shut_down();

 private:
  GLFWwindow *glfw_window_{nullptr};
  std::shared_ptr<jet::core::logger> logger_{nullptr};
};
}  // namespace jet::render

#endif