#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

class Camera
{
public:
    Camera(glm::vec3 startPosition, float startYaw = -90.0f, float startPitch = 0.0f);

    glm::mat4 getViewMatrix() const;
    void processKeyboard(int key, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset);

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;
    float speed;
    float sensitivity;

    void updateCameraVectors();
};