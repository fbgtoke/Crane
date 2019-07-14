#pragma once

#include "Shader.hpp"

#include <string>

namespace Crane {
  
class ShaderProgram {
public:
  ShaderProgram();
  ~ShaderProgram();

  void create();
  void destroy();

  void attach(const Shader& shader) const;
  void detach(const Shader& shader) const;

  bool link();

  void use() const;

  void setUniform1i(unsigned int location, int v) const;
  void setUniform1f(unsigned int location, float v) const;
  void setUniform2f(unsigned int location, float v1, float v2) const;
  void setUniform3f(unsigned int location, float v1, float v2, float v3) const;
  void setUniformMat3f(unsigned int location, float* v) const;
  void setUniformMat4f(unsigned int location, float* v) const;

  inline unsigned int getId() const { return m_Id; }
  inline bool isLinked() const { return m_Linked; }

  inline std::string getInfoLog() const { return m_InfoLog; }

private:
  unsigned int m_Id;

  bool m_Linked;
  std::string m_InfoLog;
};

}