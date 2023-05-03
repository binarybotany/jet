#ifndef Jet_Renderer_h
#define Jet_Renderer_h

#include "window.h"

namespace jet::renderer {
class Renderer {
 public:
  Renderer() {}
  ~Renderer() {}

  void StartUp(const Window &window);

  void ShutDown();

 private:
};
}  // namespace jet::renderer

#endif