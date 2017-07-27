#include "flapper.h"

flapper::flapper()
{

}

flapper::flapper(Sprite _sprite)
{
	sprite = _sprite;
	rb.Initialize(0.8f, 2, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());
}

void flapper::Update()
{
	sprite.Update();
	rb.Update();
}

void flapper::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

Sprite& flapper::GetSprite()
{
	return sprite;
}

Rigidbody& flapper::GetRB()
{
	return rb;
}