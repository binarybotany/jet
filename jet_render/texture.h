#ifndef JET_RENDER_TEXTURE_H_
#define JET_RENDER_TEXTURE_H_

#include <jet/core.h>

#include <memory>
#include <string>

namespace jet::render {
class texture final {
 public:
  texture(std::shared_ptr<jet::core::logger> logger,
          const std::string &imagepath);

  ~texture();

  void bind() const;
  void unbind() const;

 private:
  unsigned int texture_;
};
}  // namespace jet::render

#endif