#ifndef JET_CORE_PUBLISHER_H_
#define JET_CORE_PUBLISHER_H_

#include <list>

#include "subscriber.h"

namespace jet::core {
template <typename Event>
class publisher {
 public:
  publisher() = default;
  ~publisher() = default;
  publisher(const publisher&) = delete;
  publisher(publisher&&) = delete;
  publisher& operator=(const publisher&) = delete;
  publisher& operator=(publisher&&) = delete;

  void subscribe(subscriber<Event>* observer) {
    subscribers_.push_back(observer);
  }

  void unsubscribe(subscriber<Event>* observer) {
    subscribers_.remove(observer);
  }

  void publish(Event e) {
    auto iterator = subscribers_.begin();

    while (iterator != subscribers_.end()) {
      (*iterator)->handle(e);
      ++iterator;
    }
  }

 private:
  std::list<subscriber<Event>*> subscribers_;
};
}  // namespace jet::core

#endif