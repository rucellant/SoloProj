#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"


CMaingame::CMaingame()
{
}


CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	srand((unsigned)time(nullptr));

	m_hDC = GetDC(g_hWnd);

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
}

void CMaingame::Update()
{
	m_pPlayer->Update();
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, GAMECX, GAMECY);

	m_pPlayer->Render(m_hDC);
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	delete m_pPlayer;
}
