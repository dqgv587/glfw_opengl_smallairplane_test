#include "engine/engine.h"
#include "engine/graphics/Sprite.h"
#include "engine/IO/Mouse.h"
#include "engine/IO/Keyboard.h"
#include "flappey/flapper.h"

#include <iostream>
using namespace std;

int main()
{
	engine engine;
	engine.Initialize("test");

	Sprite spritetest = Sprite("engine/assets/arts/Biplane.png",Vector3(200,200,0));
	spritetest.SetScale(0.2f);
	flapper player(spritetest);

	while (true)
	{
		engine.Update();
		player.Update();

		//spritetest.MoveTo((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			player.GetSprite().RotateBy(10);
		}

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
		{
			player.GetSprite().RotateBy(-10);
		}
		
		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			player.GetSprite().RotateBy(10);
		}
		if (Keyboard::Key(GLFW_KEY_W))
		{
			//player.GetSprite().MoveUp();
			player.GetRB().AddForce(Vector3(0, 15, 0));
			player.GetRB().AddForce(Vector3(20, 0, 0));
		}
		if (Keyboard::Key(GLFW_KEY_A))
		{
			//player.GetSprite().MoveLeft();
			//player.GetRB().AddForce(Vector3(-200, 0, 0));
		}
		if (Keyboard::Key(GLFW_KEY_S))
		{
			player.GetRB().AddForce(Vector3(0, 15, 0));
			player.GetRB().AddForce(Vector3(-20, 0, 0));
			//player.GetSprite().MoveDown();
			//player.GetRB().AddForce(Vector3(0, -5, 0));
		}
		if (Keyboard::Key(GLFW_KEY_D))
		{
			//player.GetSprite().MoveRight();
			//player.GetRB().AddForce(Vector3(200, 0, 0));
		}
		engine.BeginRender();
		player.Render();
		engine.EndRender();
	}
	return 0;
}