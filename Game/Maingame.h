#pragma once

#include "GameObject.h"

class CMaingame
{
private:
	TCHAR gameInfo[100];

	HDC m_hDC;

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

	void ShowInfo();
};

