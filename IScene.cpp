#include "IScene.h"

//タイトルシーンでの初期化
int IScene::sceneNo = TITLE;

//仮想デストラクタの定義
//純粋仮想関数化していないので、ここで定義できる
IScene::~IScene(){}

int IScene::GetSeeneNo()
{
	return sceneNo;
}


