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
	m_ObjList[OBJ_PLAYER].push_back(pObj);
	dynamic_cast<CPlayer*>(pObj)->SetBulletList(&m_ObjList[OBJ_BULLET]);

	//몬스터 생성
	
	for (int i = 0; i < MNUM; i++)
	{
		pObj = nullptr;
		pObj = CAbstractFactory<CMonster>::CreateObject();
		m_ObjList[OBJ_MONSTER].push_back(pObj);
	}
}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();

	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin	= m_ObjList[i].begin();
		OBJLIST::iterator iter_End		= m_ObjList[i].end();

		for (; iter_Begin != iter_End;)
		{
			(*iter_Begin)->Update();

			if (!(*iter_Begin)->GetInfo().isAlive)
			{
				SAFE_RELEASE(*iter_Begin);
				iter_Begin = m_ObjList[i].erase(iter_Begin);
			}
			else
				++iter_Begin;
		}
	}

	CCollisionMgr::GetInstance()->CollisionSphere(&m_ObjList[OBJ_MONSTER], &m_ObjList[OBJ_BULLET]);
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

	ShowInfo();
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

void CMaingame::ShowInfo()
{
	wsprintf(gameInfo, L"총알의 갯수 : %d", m_ObjList[OBJ_BULLET].size());
	TextOut(m_hDC, 0, 0, gameInfo, wcslen(gameInfo));
}
