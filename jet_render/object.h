#ifndef JET_RENDER_OBJECT_H_
#define JET_RENDER_OBJECT_H_

namespace jet::render {
class object {
 public:
  virtual ~object() = default;
  virtual void render() const = 0;
};
}  // namespace jet::render

#endif