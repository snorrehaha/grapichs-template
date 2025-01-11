#ifndef ORTHOGRAPHICCAMERA_H_
#define ORTHOGRAPHICCAMERA_H_

#include "Camera.h"
#include <array>

class OrthographicCamera : public Camera
{
public:

  struct Frustrum {
    float left;
    float right;
    float bottom;
    float top;
    float near;
    float far;
  };

public:
  OrthographicCamera(const Frustrum& frustrum = {-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f},
                     const glm::vec3& position = glm::vec3(0.0f), float rotation = 0.0f){
                      {
  this->CameraFrustrum = frustrum;
  this->Position = position;
  this->Rotation = rotation;
  this->RecalculateMatrix();
};
                     };
  ~OrthographicCamera() = default;

  OrthographicCamera(const OrthographicCamera& camera) : Camera(camera)
  {
    this->Rotation = camera.Rotation;
    this->CameraFrustrum = camera.CameraFrustrum;
  }

  void SetRotation(float rotation)
  { this->Rotation = rotation; this->RecalculateMatrix(); }

  void SetFrustrum(const Frustrum& frustrum)
  { this->CameraFrustrum =frustrum; this->RecalculateMatrix(); }

protected:
  void RecalculateMatrix(){
    this->ProjectionMatrix = glm::ortho(
      CameraFrustrum.left, 
      CameraFrustrum.right, 
      CameraFrustrum.bottom, 
      CameraFrustrum.top, 
      CameraFrustrum.near, 
      CameraFrustrum.far);

    this->ViewMatrix = glm::translate(glm::mat4(1.0f), this->Position) * glm::rotate(glm::mat4(1.0f), this->Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    this->ViewProjectionMatrix = this->ProjectionMatrix * this->ViewMatrix;
};


protected:
  float Rotation;
  Frustrum CameraFrustrum;
};

#endif // ORTHOGRAPHICCAMERA_H_
