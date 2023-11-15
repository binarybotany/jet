#include "program.h"

#include <jet/core.h>

#include <string>

using jet::core::file;
using jet::core::log_level;
using jet::core::logger;

#define INFOLOG_SIZE 1024

namespace jet::render {
program::program(std::shared_ptr<jet::core::logger> logger) : logger_(logger) {
  program_ = glCreateProgram();
}

program::~program() { glDeleteProgram(program_); }

void program::add_shader(int type, const std::string &shaderpath) {
  file shader_file(logger_, shaderpath);

  std::string contents = shader_file.contents();
  const char *shader_source = contents.c_str();

  unsigned int shader = glCreateShader(type);
  glShaderSource(shader, 1, &shader_source, nullptr);
  glCompileShader(shader);

  int compiled = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  if (!compiled) {
    char infolog[INFOLOG_SIZE];
    glGetShaderInfoLog(shader, INFOLOG_SIZE, nullptr, infolog);
    logger_->log(log_level::warning, std::string(infolog));
    glDeleteShader(shader);
    return;
  }

  shaders_.push_back(shader);
}

void program::link() const {
  for (const unsigned int shader : shaders_) {
    glAttachShader(program_, shader);
  }

  glLinkProgram(program_);

  int linked = GL_FALSE;
  glGetProgramiv(program_, GL_LINK_STATUS, &linked);
  if (!linked) {
    char infolog[1024];
    glGetProgramInfoLog(program_, 1024, nullptr, infolog);
    logger_->log(log_level::warning, std::string(infolog));
    return;
  }

  for (const unsigned int shader : shaders_) {
    glDeleteShader(shader);
  }
}

void program::use() const { glUseProgram(program_); }
}  // namespace jet::render