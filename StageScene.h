#pragma once
#include"IScene.h"

struct Vector2
{
	float x;
	float y;
};

class StageScene :public IScene
{

public:
	void Initialize()override;
	void Update()override;
	void Draw()override;
private:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	Vector2 playerPos;
	Vector2 enemypos;

	Vector2 playerSpeed;
	Vector2 enemySpeed;

	Vector2 plauerbulletPos;
	Vector2 playerbulletSpeed;

};

