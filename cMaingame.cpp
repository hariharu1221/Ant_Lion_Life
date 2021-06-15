#include "DXUT.h"
#include "cMaingame.h"
#include "TitleScene.h"
#include "IngameScene.h"
#include "EndScene.h"

cMaingame::cMaingame()
{
}

cMaingame::~cMaingame()
{
}

void cMaingame::Init()
{
    AddResource();
    SCENE->AddScene("TitleScene", new TitleScene);
    SCENE->AddScene("IngameScene", new IngameScene);
    SCENE->AddScene("EndScene", new EndScene);
    SCENE->ChangeScene("TitleScene");
    //CAMERA->Init();
}

void cMaingame::Update()
{
    INPUT->Update();
    SCENE->Update();
    PART->Update();
    //CAMERA->Update();
}

void cMaingame::Render()
{
    PART->Render();
    UI->Begin();
    SCENE->UIRender();
    UI->End();
    SCENE->Render();
}

void cMaingame::Release()
{
    cImageManger::ReleaseInstance();
    cInputManager::ReleaseInstance();
    cUIManager::ReleaseInstance();
    cSceneManager::ReleaseInstance();
    cRenderManager::ReleaseInstance();
    cParticleManager::ReleaseInstance();
}

void cMaingame::LostDevice()
{
    UI->Lost();
}

void cMaingame::ResetDevice()
{
    UI->Reset();
}

void cMaingame::AddResource()
{
	IMAGE->AddImage("main_ui_start", "main_ui_start");
	IMAGE->AddImage("main_ui_start_d", "main_ui_start_d");
	IMAGE->AddImage("main_ui_option", "main_ui_option");
	IMAGE->AddImage("main_ui_option_d", "main_ui_option_d");
	IMAGE->AddImage("main_ui_exit", "main_ui_exit");
    IMAGE->AddImage("main_ui_exit_d", "main_ui_exit_d");
    IMAGE->AddImage("Title_bg", "Title_bg");
    IMAGE->AddImage("hp", "hp");
    IMAGE->AddImage("hp_bg", "hp_bg");
    IMAGE->AddImage("hp_hl", "hp_hl");
    IMAGE->AddImage("player", "player");
    IMAGE->AddImage("PBullet", "PBullet");
    IMAGE->AddImage("line", "line");
    IMAGE->AddImage("red", "red");
    IMAGE->AddImage("blue", "blue");
    IMAGE->AddImage("stage_f", "stage_f");
    IMAGE->AddImage("stage_c", "stage_c");

    IMAGE->AddImage("credit ready", "credit ready");
    IMAGE->AddImage("end the game ready", "end the game ready");
    IMAGE->AddImage("how to play ready", "how to play ready");
    IMAGE->AddImage("start game ready", "start game ready");

    IMAGE->AddImage("boss", "boss/1-2boss_file", 14);
    IMAGE->AddImage("bullet", "bullet/bullet", 8);
}
