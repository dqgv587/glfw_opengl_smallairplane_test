#include "Sprite.h"
#include "../engine.h"


Sprite::Sprite()
{
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3(0);
	rot = 0;
	speed = 5;
	texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(),(float)texture.GetHeight(),1);
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath,Vector3 v)
{
	texture = Texture(imagePath);
	pos = v;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	rot = 0;
	speed = 100;
}

void Sprite::Update()
{
	
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity(); //����Ϊ��λ����

	//translate -> rotate ->scale
	glTranslatef(pos.x, pos.y, 0); //ƽ�ƣ���X����룬Y����룬Z����룩
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);
	//glScaled(0.5, 0.5, 1);
	//glscaled ����(X�ᣬY�ᣬZ��) 
	//glrotate ������������ת(�Ƕȣ�X���꣬Y�����꣬Z������)

	//rendering
	glColor4f(1, 1, 1, 1);  //��ɫ��͸���� (��ɫ����ɫ����ɫ��͸����)
	glBegin(GL_QUAD_STRIP);   //�������ͼԪ  �ı���
	{
		glTexCoord2f(0, 0);           glVertex2f(0,0);   //��������ӳ��
		glTexCoord2f(0, 1);           glVertex2f(0, texture.GetHeight());
		glTexCoord2f(1, 0);           glVertex2f(texture.GetWidth(), 0);
		glTexCoord2f(1, 1);           glVertex2f(texture.GetWidth(), texture.GetHeight());
	}
	glEnd();             //��������

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

void Sprite::MoveTo(Vector3 v)
{
	pos = v;
}

void Sprite::MoveBy(Vector3 v)
{
	pos = pos + (v*(float)engine::GetDT());
}

void Sprite::MoveLeft()
{
	pos = pos - Vector3((speed*engine::GetDT()),0,0); 
}

void Sprite::MoveRight()
{
	pos = pos + Vector3((speed*engine::GetDT()), 0, 0);
}

void Sprite::MoveUp()
{
	pos = pos + Vector3(0,(speed*engine::GetDT()), 0);
}

void Sprite::MoveDown()
{
	pos = pos - Vector3(0, (speed*engine::GetDT()), 0);
}

void Sprite::RotateTo(float x)
{
	rot = (x*engine::GetDT());
}

void Sprite::RotateBy(float x)
{
	rot += x;
}

void Sprite::SetScale(float x)
{
	scale = Vector3(x);
}

void Sprite::SetScale(Vector3 v)
{
	scale = v;
}

Vector3* Sprite::GetPos()
{
	return &pos;
}

float*   Sprite::GetRot()
{
	return &rot;
}

Vector3* Sprite::GetSize()
{
	return &size;
}

Vector3* Sprite::GetScale()
{
	return &scale;
}