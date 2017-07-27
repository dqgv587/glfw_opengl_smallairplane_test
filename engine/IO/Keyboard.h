#ifndef SFMLGAME_KEYBOARD
#define SFMLGAME_KEYBOARD

#include "GLFW/glfw3.h"
class Keyboard
{
public:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool Key(int key);
	static bool KeyDown(int key);
	static bool KeyUp(int key);
private:
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];
};

#endif 