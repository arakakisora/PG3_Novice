#pragma once
#include<memory>
#include"IScene.h"
#include"TitleScene.h"
#include"StageScene.h"
#include"ClearScene.h"

class GameManager
{
private:
	//シーンのインスタンスを格納する変数
	std::unique_ptr<IScene> sceneArr_[3];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;
	int prevSceneNo_;

public:
	GameManager();
	~GameManager();
	
	void Run();


};

