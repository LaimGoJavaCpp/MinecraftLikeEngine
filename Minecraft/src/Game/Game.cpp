#include "VAO.h"
#include "Game.h"
#include "Program.h"

Game::Game()
{
	glfw = new MyGLFW();
	window = new Window("Minecraft",640,480);
	glew = new MyGLEW();
	version = "alpha 0.1.0";
	gameAuthors[0] = "Miha mahnovsky";
}

void Game::Work()
{
	VAO triangle;
	triangle.addVertexBufferObject({
	-0.5f,  0.5f, 0.0f,  
	-0.5f, -0.5f, 0.0f,  
	 0.5f, -0.5f, 0.0f,  

	 -0.5f,  0.5f, 0.0f,
	  0.5f, -0.5f, 0.0f,
	  0.5f,  0.5f, 0.0
	});
	
	Program prog("first");
	prog.bindAttribute(0, "position");
	prog.link();
	prog.use();

	while (!glfwWindowShouldClose(window->getWindow()))
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		triangle.draw(6);
		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}
}