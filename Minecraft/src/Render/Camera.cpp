#include "Camera.h"
#include <GLFW/glfw3.h>


Camera::Camera(glm::vec3 startPosition, float startYaw, float startPitch)
{
    position = startPosition;
    yaw = startYaw;
    pitch = startPitch;
    speed = 2.5f;
    sensitivity = 0.1f;
    worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    updateCameraVectors();
}


glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(int key, float deltaTime)
{
    float velocity = speed * deltaTime;
    if (key == GLFW_KEY_W) position += front * velocity;
    if (key == GLFW_KEY_S) position -= front * velocity;
    if (key == GLFW_KEY_A) position -= right * velocity;
    if (key == GLFW_KEY_D) position += right * velocity;
}

void Camera::processMouseMovement(float xoffset, float yoffset)
{
    xoffset *= sensitivity; 
    yoffset *= sensitivity;  

    yaw += xoffset;  
    pitch += yoffset;  

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateCameraVectors();
}


void Camera::updateCameraVectors()
{
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);

    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}