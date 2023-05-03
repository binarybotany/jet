#ifndef Jet_Window_h
#define Jet_Window_h

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <exception>

#include "window_configuration.h"

namespace jet::renderer {
class Window {
 public:
  Window() {}

  ~Window() {}

  void StartUp(const WindowConfiguration &configuration);

  void ShutDown();

  void Run();

 private:
  GLFWwindow *m_p_window = nullptr;
  int m_width, m_height;
};
}  // namespace jet::renderer

#endif
