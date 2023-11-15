#ifndef JET_RENDER_PROGRAM_H_
#define JET_RENDER_PROGRAM_H_

#include <glad/glad.h>
#include <jet/core.h>

#include <memory>
#include <vector>

namespace jet::render {
class program final {
 public:
  program(std::shared_ptr<jet::core::logger> logger);
  ~program();
  void add_shader(int type, const std::string &shaderpath);
  void link() const;
  void use() const;

 private:
  unsigned int program_{0};
  std::vector<unsigned int> shaders_;
  std::shared_ptr<jet::core::logger> logger_{nullptr};
};
}  // namespace jet::render

#endif