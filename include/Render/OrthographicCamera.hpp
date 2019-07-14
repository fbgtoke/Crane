#pragma once

#include "Camera.hpp"

#include <glm/vec3.hpp>

namespace Crane {
 
class OrthographicCamera : public Camera {
public:
  OrthographicCamera(
    float l, float r, float b, float t, 
    float znear = -1.f, float zfar = 1.f
  );

  ~OrthographicCamera() override = default;

  glm::mat4 getViewMatrix() const override
  {
    return  m_ViewMatrix;
  }

  glm::mat4 getProjectionMatrix() const override
  {
    return  m_ProjectionMatrix;
  }

  glm::mat4 getViewProjectionMatrix() const override
  {
    return  m_ViewProjectionMatrix;
  }

  void setPosition(const glm::vec3& position);
  void move(const glm::vec3& v);

  void setRotation(float rotation);
  void rotate(float v);

  void recomputeMatrices();

  inline glm::vec3 getPosition() const { return m_Position; }
  inline float getRotation() const { return m_Rotation; }

private:
  /* View */
  glm::vec3 m_Position;
  float m_Rotation;

  /* Matrices */
  glm::mat4 m_ViewMatrix;
  glm::mat4 m_ProjectionMatrix;
  glm::mat4 m_ViewProjectionMatrix;
};

}