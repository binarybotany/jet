#ifndef JET_CORE_SUBSCRIBER_H_
#define JET_CORE_SUBSCRIBER_H_

#include <functional>

namespace jet::core {
template <typename Event>
class subscriber final {
 public:
  subscriber() = default;
  ~subscriber() = default;
  subscriber(const subscriber&) = delete;
  subscriber(subscriber&&) = delete;
  subscriber& operator=(const subscriber&) = delete;
  subscriber& operator=(subscriber&&) = delete;

  template <typename Object, void (Object::*Method)(void*, Event)>
  void bind(Object* object_ptr) {
    sender_ptr_ = static_cast<void*>(object_ptr);
    handler_ = std::bind(Method, object_ptr, std::placeholders::_1,
                         std::placeholders::_2);
  }

  void handle(Event e) { handler_(sender_ptr_, e); }

 private:
  void* sender_ptr_;
  std::function<void(void*, Event)> handler_;
};
}  // namespace jet::core

#endif