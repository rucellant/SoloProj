#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"


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
	m_ObjList[OBJ_PLAYER].push_back(pObj);

	//몬스터 생성
	pObj = nullptr;
	for (int i = 0; i < MNUM; i++)
	{
		pObj = CAbstractFactory<CMonster>::CreateObject();
		m_ObjList[OBJ_MONSTER].push_back(pObj);
	}
}

void CMaingame::Update()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin	= m_ObjList[i].begin();
		OBJLIST::iterator iter_End		= m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			(*iter_Begin)->Update();
	}
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, GAMECX, GAMECY);

	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			(*iter_Begin)->Render(m_hDC);
	}
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			SAFE_RELEASE(*iter_Begin);
	}
}
