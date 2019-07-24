#pragma once

#include "GameObject.h"

class CMaingame
{
private:
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
};

