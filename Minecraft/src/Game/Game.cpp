#include "VAO.h"
#include "Game.h"
#include "Program.h"
#include "Grass.h"
#include "Dirt.h"
#include "Badapple.h"

Game::Game()
{
    glfw = new MyGLFW();
    window = new Window("Minecraft");
    glew = new MyGLEW();
    camera = new Camera(glm::vec3(0.0f, 0.0f, 1.5f), 180.0f, 0.0f);
    keyboard = new InputKeyboard(window);
    render = new Render(window, camera);
    version = "alpha 0.1.0";
    gameAuthors[0] = "Miha mahnovsky";
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    static float lastX = xpos, lastY = ypos;
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));
    if (camera)
        camera->processMouseMovement(xoffset, yoffset);
}

void Game::Work()
{
    glfwSetInputMode(window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window->getWindow(), mouse_callback);
    glfwSetWindowUserPointer(window->getWindow(), camera);

    Grass* grass = new Grass();
    Dirt* dirt = new Dirt();
    Badapple* badapple = new Badapple();
    grass->setPosition({ -2.0f,0.0f,0.0f });
    dirt->setPosition({ -4.0f,0.0f,0.0f });
    badapple->setPosition({ 0.0f,0.0f,0.0f });
    render->addRenderObject(dirt);
    render->addRenderObject(badapple);
    render->addRenderObject(grass);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window->getWindow()))
    {
        InputKeyBoardProcces();
        render->Draw();
    }
}

void Game::InputKeyBoardProcces()
{
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    if (keyboard->isKeyPressed(GLFW_KEY_W))
        camera->processKeyboard(GLFW_KEY_W, deltaTime);
    if (keyboard->isKeyPressed(GLFW_KEY_S))
        camera->processKeyboard(GLFW_KEY_S, deltaTime);
    if (keyboard->isKeyPressed(GLFW_KEY_A))
        camera->processKeyboard(GLFW_KEY_A, deltaTime);
    if (keyboard->isKeyPressed(GLFW_KEY_D))
        camera->processKeyboard(GLFW_KEY_D, deltaTime);
}