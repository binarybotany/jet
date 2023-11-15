#ifndef JET_RENDER_RECTANGLE_H_
#define JET_RENDER_RECTANGLE_H_

#include <glad/glad.h>
#include <jet/core.h>

#include <memory>

#include "object.h"
#include "program.h"
#include "texture.h"

namespace jet::render {
class rectangle final : public object {
 public:
  rectangle(std::shared_ptr<jet::core::logger> logger);
  ~rectangle();
  void render() const override;
  void bind() const;
  void unbind() const;

 private:
  unsigned int vao_, vbo_, ebo_;
  std::unique_ptr<program> program_{nullptr};
  std::unique_ptr<texture> texture_{nullptr};
};
}  // namespace jet::render

#endif