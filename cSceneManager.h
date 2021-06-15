#pragma once
#include "singleton.h"
class cSceneManager : public singleton<cSceneManager>
{
public:
	map<string, cScene*> m_scenes;
	cScene* nowScene = nullptr;
	cScene* nextScene = nullptr;

	cSceneManager();
	~cSceneManager();

	float m_Hp;
	float m_MaxHp;
	int m_Score;
	Vec2 v_pos;

	bool tile = false;

	void Update();
	void Render();
	void UIRender();
	void Release();

	void AddScene(string key, cScene* scene);
	void ChangeScene(string key);

	void PlayerInit();
};

#define SCENE cSceneManager::GetInstance()