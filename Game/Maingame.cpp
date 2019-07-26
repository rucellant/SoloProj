#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"


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

	//플레이어 생성
	CGameObject* pObj = CAbstractFactory<CPlayer>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJ_PLAYER, pObj);

	//몬스터 생성
	for (int i = 0; i < MNUM; i++)
	{
		pObj = nullptr;
		pObj = CAbstractFactory<CMonster>::CreateObject();
		CObjectMgr::GetInstance()->AddObject(OBJ_MONSTER, pObj);
	}
}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();
	CObjectMgr::GetInstance()->Update();
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, GAMECX, GAMECY);
	CObjectMgr::GetInstance()->Render(m_hDC);
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CKeyMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
}