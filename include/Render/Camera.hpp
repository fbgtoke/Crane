#pragma once

#include <glm/mat4x4.hpp>

namespace Crane {
 
class Camera {
public:
  virtual ~Camera() = default;
  
  virtual glm::mat4 getViewMatrix() const = 0;
  virtual glm::mat4 getProjectionMatrix() const = 0;
  virtual glm::mat4 getViewProjectionMatrix() const = 0;
};

}