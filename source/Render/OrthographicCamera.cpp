#include "OrthographicCamera.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace Crane {

OrthographicCamera::OrthographicCamera(
  float l, float r, float b, float t, 
  float znear, float zfar
) : m_Position(0.f), m_Rotation(0.f),
  m_ProjectionMatrix(glm::ortho(l, r, b, t, znear, zfar))
{
  recomputeMatrices();
}

void OrthographicCamera::setPosition(const glm::vec3& position)
{
  m_Position = position;
}

void OrthographicCamera::move(const glm::vec3& v)
{
  m_Position += v;
}

void OrthographicCamera::setRotation(float rotation)
{
  m_Rotation = rotation;
}

void OrthographicCamera::rotate(float v)
{
  m_Rotation += v;
}

void OrthographicCamera::recomputeMatrices()
{
  m_ViewMatrix = glm::mat4(1.f);
  m_ViewMatrix = glm::translate(m_ViewMatrix, -m_Position);
  m_ViewMatrix = glm::rotate(m_ViewMatrix, -m_Rotation, { 0.f, 0.f, -1.f });

  m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
}

}