// Crane game engine
// Copyright (C) 2019  Fabio Banchelli
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "OpenGLShader.hpp"
#include "OpenGLLog.hpp"
#include "Render/Shader.hpp"

#include <glad/glad.h>

#include <cstring>
#include <fstream>
#include <streambuf>

namespace Crane {

OpenGLShader::OpenGLShader
(
  const std::vector<std::string>& src, const std::vector<Shader::Type>& types,
  const std::string& name
)
{
  fromSources(src, types, name);
}

OpenGLShader::OpenGLShader(const std::string& filename, const std::string& name)
{
  // Read file
  std::ifstream fstream(filename);
  CRANE_ASSERT(fstream.is_open(), "Error opening shader file");

  std::string contents;
  contents.assign
  (
    std::istreambuf_iterator<char>(fstream),
    std::istreambuf_iterator<char>()
  );
  fstream.close();

  // Extract name from filename
  std::string shader_name = nameFromFilename(filename);

  // Extract sources and types
  std::vector<std::string> shader_sources;
  std::vector<Shader::Type> shader_types;
  getSourcesAndTypes(contents, shader_sources, shader_types);

  // Compile shaders
  fromSources(shader_sources, shader_types, shader_name);
}

OpenGLShader::~OpenGLShader()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void OpenGLShader::destroy()
{
  CRANE_GL_CALL(glDeleteShader(m_Id));
  m_Id = GL_INVALID_VALUE;
}

void OpenGLShader::use() const
{
  CRANE_GL_CALL(glUseProgram(m_Id));
}

uint32_t OpenGLShader::getUniformLocation(const std::string& name) const
{
  uint32_t location =
    CRANE_GL_CALL(glGetUniformLocation(m_Id, name.c_str()));
    
  return location;
}

void OpenGLShader::setUniform1i(const std::string& name,
  int v
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Int, "Uniform", name, "is not of type Int");
  CRANE_GL_CALL(glUniform1i(uniform.location, v));
}

void OpenGLShader::setUniform1f(const std::string& name,
float v
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Int, "Uniform", name, "is not of type Float");
  CRANE_GL_CALL(glUniform1f(uniform.location, v));
}

void OpenGLShader::setUniform2f(const std::string& name, 
  float v1, float v2
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Int, "Uniform", name, "is not of type Float2");
  CRANE_GL_CALL(glUniform2f(uniform.location, v1, v2));
}

void OpenGLShader::setUniform3f(const std::string& name, 
  float v1, float v2, float v3
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Int, "Uniform", name, "is not of type Float3");
  CRANE_GL_CALL(glUniform3f(uniform.location, v1, v2, v3));
}

void OpenGLShader::setUniformMat3f(const std::string& name,
  const float* v
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Mat3, "Uniform", name, "is not of type Mat3");
  CRANE_GL_CALL(glUniformMatrix3fv(uniform.location, 1, GL_FALSE, v));
}

void OpenGLShader::setUniformMat4f(const std::string& name,
  const float* v
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Mat4, "Uniform", name, "is not of type Mat4");
  CRANE_GL_CALL(glUniformMatrix4fv(uniform.location, 1, GL_FALSE, v));
}

void OpenGLShader::setUniformTexture(const std::string& name,
  const Texture * const tex
) const
{
  CRANE_ASSERT(m_Uniforms.count(name) > 0, "Uniform", name, "not found");
  const Uniform& uniform = m_Uniforms.at(name);
  CRANE_ASSERT(uniform.type == Shader::Tex, "Uniform", name, "is not of type Tex");
  CRANE_GL_CALL(glUniform1i(uniform.location, tex->getTextureUnit()));
}

/******************************************************************************/
/* Implementation of private methods                                          */
/******************************************************************************/

void OpenGLShader::fromSources
(
  const std::vector<std::string>& src, const std::vector<Shader::Type>& types,
  const std::string& name
)
{
  m_Name = name;
  
  m_Id = CRANE_GL_CALL(glCreateProgram());
  CRANE_ASSERT(m_Id != GL_INVALID_VALUE, "Error creating shader program");

  CRANE_ASSERT
  (
    src.size() == types.size(),
    "Number of shader sources does not match number of types"
  );

  std::vector<int> shader_ids;
  shader_ids.reserve(src.size());

  for (unsigned int i = 0; i < src.size(); ++i)
  {
    int shader_id = compileShaderSource(src[i], types[i]);

    // Attach shaders to program
    CRANE_GL_CALL(glAttachShader(m_Id, shader_id));
    shader_ids.push_back(shader_id);
  }

  // Link program
  int linked = 0;
  CRANE_GL_CALL(glLinkProgram(m_Id));
  CRANE_GL_CALL(glGetProgramiv(m_Id, GL_LINK_STATUS, &linked));
  CRANE_ASSERT(linked, "Error linking shader program");

  // Free compiled shaders
  for (unsigned int i = 0; i < src.size(); ++i)
  {
    CRANE_GL_CALL(glDeleteShader(shader_ids[i]));
  }

  queryUniforms();
}

int OpenGLShader::compileShaderSource(const std::string& src, Shader::Type type)
{
  int shader_type;
  int shader_id;
  int compiled = 0;

  // Create shaders
  switch (type)
  {
  case Shader::Vertex:   shader_type =   GL_VERTEX_SHADER; break;
  case Shader::Fragment: shader_type = GL_FRAGMENT_SHADER; break;
  default: CRANE_LOG_ERROR("Unknown shader type"); break;
  }
  shader_id = CRANE_GL_CALL(glCreateShader(shader_type));
  CRANE_ASSERT(shader_id != GL_INVALID_VALUE, "Error creating shader");

  // Compile shaders
  const char* src_ptr = src.c_str();
  CRANE_GL_CALL(glShaderSource(shader_id, 1, &src_ptr, 0));    
  CRANE_GL_CALL(glCompileShader(shader_id));
  CRANE_GL_CALL(glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled));
  CRANE_ASSERT(compiled, "Error compiling shader");

  return shader_id;
}


Shader::Datatype toCrane(uint32_t type)
{
  switch (type)
  {
  case GL_INT:        return Shader::Int;
  case GL_INT_VEC2:   return Shader::Int2;
  case GL_INT_VEC3:   return Shader::Int3;
  case GL_INT_VEC4:   return Shader::Int4;
  case GL_FLOAT:      return Shader::Float;
  case GL_FLOAT_VEC2: return Shader::Float2;
  case GL_FLOAT_VEC3: return Shader::Float3;
  case GL_FLOAT_VEC4: return Shader::Float4;
  case GL_FLOAT_MAT3: return Shader::Mat3;
  case GL_FLOAT_MAT4: return Shader::Mat4;
  case GL_SAMPLER_2D: return Shader::Tex;
  }

  CRANE_LOG_ERROR("Unsupported Uniform type");
  return Shader::Int;
}

void OpenGLShader::queryUniforms()
{
  m_Uniforms.clear();

  int count;
  glGetProgramiv(m_Id, GL_ACTIVE_UNIFORMS, &count);

  const int max_length = 16;
  int length;
  int size;
  uint32_t type;
  char name[max_length];

  for (int i = 0; i < count; i++)
  {
    CRANE_GL_CALL(glGetActiveUniform(
      m_Id, (uint32_t)i,
      max_length, &length, &size, &type, name
    ));

    Shader::Datatype crane_type = toCrane(type);
    m_Uniforms[name] = Uniform(i, crane_type);
  }
}

std::string OpenGLShader::nameFromFilename(const std::string& filename)
{
  size_t begin = filename.find_last_of("/\\");
  if (begin == std::string::npos) begin = 0;
  else begin += 1; // Discard slashes

  size_t end = filename.find_last_of(".");
  if (end == std::string::npos) end = filename.size();

  return filename.substr(begin, end - begin);
}

void OpenGLShader::getSourcesAndTypes
(
  const std::string& file_contents,
  std::vector<std::string>& sources, std::vector<Shader::Type>& types
)
{
  const char* typeToken = "#type";
  size_t typeTokenLength = strlen(typeToken);
  size_t pos = file_contents.find(typeToken, 0);
  while (pos != std::string::npos)
  {
    size_t eol = file_contents.find_first_of("\r\n", pos);
    CRANE_ASSERT(eol != std::string::npos, "Syntax error");
    size_t begin = pos + typeTokenLength + 1;
    size_t nextLinePos = file_contents.find_first_not_of("\r\n", eol);
    pos = file_contents.find(typeToken, nextLinePos);

    // Parse shader source
    std::string shader_src;
    if (nextLinePos == std::string::npos)
    {
      shader_src =
        file_contents.substr(nextLinePos, pos - file_contents.size() - 1);
    }
    else
    {
      shader_src =
        file_contents.substr(nextLinePos, pos - nextLinePos);
    }
    sources.push_back(shader_src);

    // Parse shader type
    Shader::Type shader_type = fromString(file_contents.substr(begin, eol - begin));
    types.push_back(shader_type);

  }
}

/******************************************************************************/
/* Implementation of static methods from Shader class                         */
/******************************************************************************/

Shader* Shader::create(
  const std::vector<std::string>& src, const std::vector<Shader::Type>& types,
  const std::string& name
)
{
  return new OpenGLShader(src, types, name);
}

Shader* Shader::create(const std::string& filename, const std::string& name)
{
  return new OpenGLShader(filename, name);
}

std::size_t Shader::getDatatypeSize(Shader::Datatype t)
{
  switch (t)
  {
    case Shader::Int:    return sizeof(int) * 1;
    case Shader::Int2:   return sizeof(int) * 2;
    case Shader::Int3:   return sizeof(int) * 3;
    case Shader::Int4:   return sizeof(int) * 4;
    case Shader::Float:  return sizeof(float) * 1;
    case Shader::Float2: return sizeof(float) * 2;
    case Shader::Float3: return sizeof(float) * 3;
    case Shader::Float4: return sizeof(float) * 4;
    case Shader::Mat3:   return sizeof(float) * 3 * 3;
    case Shader::Mat4:   return sizeof(float) * 4 * 4;
    default: return 0;
  }
}

Shader::Type Shader::fromString(const std::string& str)
{
  if (str == "vertex")
    return Vertex;
  else if (str == "fragment")
    return Fragment;

  CRANE_LOG_ERROR("Unknown shader type:", str);
  return Unknown;
} 

}