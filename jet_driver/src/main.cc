#include <jet/renderer.h>

#include <iostream>

using jet::renderer::Window;
using jet::renderer::WindowConfiguration;

int main(int argc, char **argv) {
  WindowConfiguration configuration{};
  configuration.fullscreen = false;
  configuration.width = 1024;
  configuration.height = 768;

  Window window{};
  window.StartUp(configuration);
  window.Run();
  window.ShutDown();

  return 0;
}