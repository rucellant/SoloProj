#pragma once

#include "GameObject.h"

class CMaingame
{
private:
	HDC m_hDC;

	CGameObject* m_pPlayer;

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

