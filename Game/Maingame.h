#pragma once

#include "GameObject.h"

class CMaingame
{
private:
	HDC m_hDC;

	CGameObject* m_pPlayer;
	CGameObject* m_pMonster[5];

	OBJLIST m_ObjList[OBJ_END];

public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();
};

