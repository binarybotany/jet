#include <jet/core.h>
#include <jet/ioc.h>
#include <jet/render.h>
#include <jet/ui.h>

#include <memory>

using jet::core::logger;
using jet::render::window;

int main(int argc, char **argv) {
  auto l = std::make_shared<logger>();
  l->set_file("jet.log");

  auto w = std::make_unique<window>(l);
  w->start_up();
  w->shut_down();

  return 0;
}