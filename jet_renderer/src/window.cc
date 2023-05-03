#include "window.h"

#include <iostream>

namespace jet::renderer {
void Window::StartUp(const WindowConfiguration& configuration) {
  try {
    if (!glfwInit()) {
      std::runtime_error("Unable to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 8);

    GLFWmonitor* p_monitor = nullptr;

    if (configuration.fullscreen) {
      p_monitor = glfwGetPrimaryMonitor();
      const GLFWvidmode* p_video_mode = glfwGetVideoMode(p_monitor);

      m_width = p_video_mode->width;
      m_height = p_video_mode->height;
    } else {
      m_width = configuration.width;
      m_height = configuration.height;
    }

    m_p_window =
        glfwCreateWindow(m_width, m_height, "Jet Driver", p_monitor, nullptr);

    if (m_p_window == nullptr) {
      throw std::runtime_error("Unable to create window");
    }

    glfwMakeContextCurrent(m_p_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      throw std::runtime_error("Unable to initialize context");
    }
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
  }

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);

#ifdef _DEBUG
  glEnable(GL_DEBUG_OUTPUT);
#endif

  glViewport(0, 0, m_width, m_height);
}

void Window::ShutDown() {
  if (m_p_window != nullptr) {
    glfwDestroyWindow(m_p_window);
  }
  glfwTerminate();
}

void Window::Run() {
  while (!glfwWindowShouldClose(m_p_window)) {
    glfwPollEvents();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(m_p_window);
  }
}
}  // namespace jet::renderer