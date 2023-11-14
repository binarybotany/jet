#include <jet/core.h>
#include <jet/ioc.h>
#include <jet/render.h>
#include <jet/ui.h>

#include <memory>

using jet::core::logger;
using jet::core::publisher;
using jet::core::subscriber;
using jet::render::window;

struct some_event {
  int id;
};

class something {
 public:
  something(std::shared_ptr<logger> logger, unsigned int id)
      : logger_(logger), id_(id) {}

  unsigned int id() { return id_; }

  void handler(void *sender, const some_event &event) {
    something *s = static_cast<something *>(sender);

    std::string message("Event id: ");
    message += std::to_string(event.id);
    message += ", id: ";
    message += std::to_string(s->id());

    logger_->log(jet::core::log_level::info, message);
  }

 private:
  std::shared_ptr<logger> logger_{nullptr};
  unsigned int id_{0};
};

int main(int argc, char **argv) {
  auto l = std::make_shared<logger>("jet.log");

  auto w = std::make_unique<window>(l);
  w->start_up();
  w->shut_down();

  something *st = new something(l, 10);
  auto p = std::make_unique<publisher<const some_event &>>();
  auto s = std::make_unique<subscriber<const some_event &>>();
  p->subscribe(s.get());
  s->bind<something, &something::handler>(st);

  some_event e;
  e.id = 201;
  p->publish(e);

  return 0;
}