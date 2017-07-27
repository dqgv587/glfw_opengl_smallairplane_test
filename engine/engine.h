#ifndef SFMLGAME_ENGINE
#define SFMLGAME_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib,"opengl32.lib")

#include <iostream>
using namespace std;

class engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float GetDT();

	engine();
	~engine();

	bool Initialize(char * windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	static float dt;
	float lastTime;
};

#endif