#pragma once

#include <string>

namespace Crane {

class Shader {
public:
  typedef enum {
    Unknown, Vertex, Fragment
  } ShaderType;

  Shader();
  ~Shader();

  void create(ShaderType t);
  void destroy();

  bool compileFromFile(const std::string& file);
  bool compileFromSource(const std::string& src);

  inline ShaderType getType() const { return m_Type; }
  inline unsigned int getId() const { return m_Id; }

  inline bool isCompiled() const { return m_Compiled; }
  inline std::string getInfoLog() const { return m_InfoLog; }

private:
  ShaderType m_Type;
  int m_Id;

  bool m_Compiled;
  std::string m_InfoLog;
};

}