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

  inline unsigned int getId() const { return m_Id; }
  inline bool isLinked() const { return m_Linked; }

  inline std::string getInfoLog() const { return m_InfoLog; }

private:
  unsigned int m_Id;

  bool m_Linked;
  std::string m_InfoLog;
};

}