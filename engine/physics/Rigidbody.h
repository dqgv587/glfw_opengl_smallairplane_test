#ifndef SFMLGAME_RIGIDBODY
#define SFMLGAME_RIGIDBODY

#include "../Math/Vector3.h"

class Rigidbody
{
public:
	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale,Vector3* _size);

	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);

private:
	Vector3* pos;
	float* rot;
	Vector3* scale;
	Vector3* size;

	float gravity;//重力
	float friction;//摩擦
	Vector3 vel;//速度
};
#endif