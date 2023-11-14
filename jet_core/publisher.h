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
    observers_.push_back(observer);
  }

  void unsubscribe(subscriber<Event>* observer) { observers_.remove(observer); }

  void publish(Event e) {
    auto iterator = observers_.begin();

    while (iterator != observers_.end()) {
      (*iterator)->handle(e);
      ++iterator;
    }
  }

 private:
  std::list<subscriber<Event>*> observers_;
};
}  // namespace jet::core

#endif