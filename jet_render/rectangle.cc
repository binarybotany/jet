#include "rectangle.h"

#include <glad/glad.h>

using jet::core::logger;

namespace jet::render {
rectangle::rectangle(std::shared_ptr<logger> logger) {
  const float vertices[] = {0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                            0.5f,  -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
                            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                            -0.5f, 0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

  const unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  program_ = std::make_unique<program>(logger);
  program_->add_shader(GL_VERTEX_SHADER, "shaders/rectangle.vert.glsl");
  program_->add_shader(GL_FRAGMENT_SHADER, "shaders/rectangle.frag.glsl");
  program_->link();

  texture_ = std::make_unique<texture>(logger, "images/checkers-16-16.png");

  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glGenBuffers(1, &ebo_);

  bind();

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  int stride = 8 * sizeof(float);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride,
                        (void *)(3 * sizeof(float)));
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride,
                        (void *)(6 * sizeof(float)));

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  unbind();
}

rectangle::~rectangle() {
  glDeleteVertexArrays(1, &vao_);
  glDeleteBuffers(1, &vbo_);
  glDeleteBuffers(1, &ebo_);
}

void rectangle::render() const {
  bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  unbind();
}

void rectangle::bind() const {
  program_->use();
  texture_->bind();

  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
}

void rectangle::unbind() const {
  texture_->unbind();

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
}  // namespace jet::render