#include "entity_manager.h"

namespace jet::ecs {
entt::entity entity_manager::create_entity() { return registry_.create(); }

void entity_manager::destroy_entity(entt::entity entity) {
  registry_.destroy(entity);
}
}  // namespace jet::ecs