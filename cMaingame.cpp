#include "DXUT.h"
#include "cMaingame.h"
#include "TitleScene.h"
#include "EndScene.h"
#include "Stage_1_1.h"
#include "Stage_1_0.h"
#include "Stage_2_0.h"

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
    SCENE->AddScene("EndScene", new EndScene);
    SCENE->AddScene("Stage_1_1", new Stage_1_1);
    SCENE->AddScene("Stage_1_0", new Stage_1_0);
    SCENE->AddScene("Stage_2_0", new Stage_2_0);
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
    IMAGE->AddImage("2-0stage_f", "2-0stage_f");
    IMAGE->AddImage("2-0stage_c", "2-0stage_c");
    IMAGE->AddImage("timebar", "timebar");
    IMAGE->AddImage("ui_bg", "ui_bg");
    IMAGE->AddImage("start", "start/startgame", 14);

    IMAGE->AddImage("credit ready", "credit ready");
    IMAGE->AddImage("end the game ready", "end the game ready");
    IMAGE->AddImage("how to play ready", "how to play ready");
    IMAGE->AddImage("start game ready", "start game ready");

    IMAGE->AddImage("boss", "boss/1-2boss_file", 14);
    IMAGE->AddImage("bos2", "boss2/stop");
    IMAGE->AddImage("boss2r", "boss2/boss2l", 10);
    IMAGE->AddImage("boss2l", "boss2/boss2r", 10);
    IMAGE->AddImage("bullet", "bullet/bullet", 8);
    IMAGE->AddImage("mob1", "mob1/mob1", 5);
    IMAGE->AddImage("mob2", "mob2/mob2", 9);
    IMAGE->AddImage("mob2_skill", "mob2/mob2_skill", 9);
    IMAGE->AddImage("mob3rl", "mob3r/left/mob3", 3);
    IMAGE->AddImage("mob3rr", "mob3r/right/mob3", 3);
    IMAGE->AddImage("mob3rt", "mob3r/up/mob3", 3);
    IMAGE->AddImage("mob3rb", "mob3r/down/mob3", 3);
    IMAGE->AddImage("mob3bl", "mob3b/left/mob3", 3);
    IMAGE->AddImage("mob3br", "mob3b/right/mob3", 3);
    IMAGE->AddImage("mob3bt", "mob3b/up/mob3", 3);
    IMAGE->AddImage("mob3bb", "mob3b/down/mob3", 3);
    IMAGE->AddImage("boss3l", "boss3/left/boss3", 4);
    IMAGE->AddImage("boss3r", "boss3/right/boss3", 4);
    IMAGE->AddImage("boss3t", "boss3/up/boss3", 4);
    IMAGE->AddImage("boss3b", "boss3/down/boss3", 4);
    IMAGE->AddImage("boss3sk1", "boss3/ready/boss3", 4);
    IMAGE->AddImage("boss3sk2", "boss3/go/boss3", 2);
}

