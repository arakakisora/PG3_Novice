#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Initialize()
{
	keys[256] = { 0 };
	preKeys[256] = { 0 };

}

void TitleScene::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		sceneNo = STAGE;
	}

}

void TitleScene::Draw()
{
}
