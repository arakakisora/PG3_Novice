#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize()
{
	//初期化
	keys[256] = { 0 };
	preKeys[256] = { 0 };





}

void ClearScene::Update()
{
	//更新
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//スペースキーが押されたらタイトルに戻る
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		sceneNo = TITLE;
	}


}

void ClearScene::Draw()
{
}
