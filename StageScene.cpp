#include "StageScene.h"
#include <Novice.h>
#include <corecrt_math.h>

void StageScene::Initialize()
{
	//初期化
	keys[256] = { 0 };
	preKeys[256] = { 0 };

	playerPos = { 100,100 };
	enemypos = { 500,100 };

	playerSpeed = { 3,3 };
	enemySpeed = { 1,1 };

	plauerbulletPos = { 0,0 };
	playerbulletSpeed = { 0,0 };



}

void StageScene::Update()
{
	//更新
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//Aキーが押されたら左に移動
	if (keys[DIK_A] != 0)
	{
		playerPos.x -= playerSpeed.x;
	}
	//Dキーが押されたら右に移動
	if (keys[DIK_D] != 0)
	{
		playerPos.x += playerSpeed.x;
	}
	//Wキーが押されたら上に移動
	if (keys[DIK_W] != 0)
	{
		playerPos.y -= playerSpeed.y;
	}
	//Sキーが押されたら下に移動
	if (keys[DIK_S] != 0)
	{
		playerPos.y += playerSpeed.y;
	}

	//スペースキーが押されたら弾を発射
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		plauerbulletPos = playerPos;
		playerbulletSpeed = { 0, -5 };
	}

	//弾の移動
	plauerbulletPos.x += playerbulletSpeed.x;
	plauerbulletPos.y += playerbulletSpeed.y;

	//敵の移動画面は時に行ったら反転
	enemypos.x += enemySpeed.x;
	if (enemypos.x > 1000 || enemypos.x < 0)
	{
		enemySpeed.x *= -1;
	}

	//弾と敵の当たり判定円の判定
	float distance = (float)sqrt((plauerbulletPos.x - enemypos.x) * (plauerbulletPos.x - enemypos.x) + (plauerbulletPos.y - enemypos.y) * (plauerbulletPos.y - enemypos.y));
	if (distance < 20)
	{
		sceneNo = CLEAR;
	}






}

void StageScene::Draw()
{
	Novice::DrawEllipse((int)playerPos.x, (int)playerPos.y, 20, 20,0.0f,RED,kFillModeSolid);
	Novice::DrawEllipse((int)enemypos.x, (int)enemypos.y, 20, 20, 0.0f, BLUE, kFillModeSolid);
	Novice::DrawEllipse((int)plauerbulletPos.x, (int)plauerbulletPos.y, 5, 5, 0.0f, WHITE, kFillModeSolid);


}
