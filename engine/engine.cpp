#include "engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int engine::SCREEN_WIDTH = 1366;
int engine::SCREEN_HEIGHT = 768;
GLFWwindow* engine::window = NULL;
float engine::dt = 0;

engine::engine()
{

}

engine::~engine()
{

}

bool engine::Initialize(char* windowTitle)
{
	if (!glfwInit())
	{
		cout << "cao nima" << endl;
		return false;
	}
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL)
	{
		cout << "create error" << endl;
		return false;
	}

	//glfw setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);
	
	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);


	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	lastTime = (float)glfwGetTime();

	return true;
}

void engine::Update()
{
	float now = (float)glfwGetTime();
	dt = (now - lastTime);
	lastTime = now;
	glfwPollEvents();
}

void engine::BeginRender()
{
	glClearColor(0, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void engine::EndRender()
{
	glfwSwapBuffers(window);
}

float engine::GetDT()
{
	return dt;
}