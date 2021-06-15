#include "DXUT.h"
#include "cInputManager.h"

cInputManager::cInputManager()
{
}

cInputManager::~cInputManager()
{
	
}

void cInputManager::Update()
{
	for (int i = 0; i < 256; i++) oldkey[i] = nowkey[i];
	for (int i = 0; i < 256; i++)
	{
		if (GetAsyncKeyState(i)) nowkey[i] = true;
		else nowkey[i] = false;
	}
}

bool cInputManager::KeyPress(int key)
{
	return nowkey[key] == true && oldkey[key] == true;
}

bool cInputManager::KeyDown(int key)
{
	return nowkey[key] == true && oldkey[key] == false;
}

bool cInputManager::KeyUp(int key)
{
	return nowkey[key] == false && oldkey[key] == true;
}
