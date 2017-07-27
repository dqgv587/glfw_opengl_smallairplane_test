#ifndef SFMLGAME_FLAPPER
#define SFMLGAME_FLAPPER

#include "../engine/physics/Rigidbody.h"
#include "../engine/graphics/Sprite.h"

class flapper
{
public:

	flapper();
	flapper(Sprite _sprite);

	void Update();
	void Render();

	Sprite& GetSprite();
	Rigidbody& GetRB();

private:
	Sprite sprite;
	Rigidbody rb;
};

#endif