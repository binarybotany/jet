#ifndef JET_ECS_ENTITY_MANAGER_H_
#define JET_ECS_ENTITY_MANAGER_H_

#include <entt/entt.hpp>

namespace jet::ecs {
typedef entt::entity entity;

class entity_manager final {
 public:
  entt::entity create_entity();
  void destroy_entity(entt::entity entity);

  template <typename Component, typename... Args>
  Component &add_component(entt::entity entity, Args &&...args);

  template <typename Component>
  void remove_component(entt::entity entity);

  template <typename Component>
  Component &component(entt::entity entity);

 private:
  entt::registry registry_;
};

template <typename Component, typename... Args>
Component &entity_manager::add_component(entt::entity entity, Args &&...args) {
  return registry_.emplace<Component>(entity, std::forward<Args>(args)...);
}

template <typename Component>
void entity_manager::remove_component(entt::entity entity) {
  registry_.remove<Component>(entity);
}

template <typename Component>
Component &entity_manager::component(entt::entity entity) {
  return registry_.get<Component>(entity);
}
}  // namespace jet::ecs

#endif