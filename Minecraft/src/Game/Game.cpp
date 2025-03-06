#include "VAO.h"
#include "Game.h"
#include "Program.h"
#include "Grass.h"

Game::Game()
{
	glfw = new MyGLFW();
	window = new Window("Minecraft",640,480);
	glew = new MyGLEW();	
	render = new Render(window);
	version = "alpha 0.1.0";
	gameAuthors[0] = "Miha mahnovsky";
}

void Game::Work()
{
	Grass* grass = new Grass();
	render->addRenderObject(grass);

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window->getWindow()))
	{
		render->Draw();
	}
}