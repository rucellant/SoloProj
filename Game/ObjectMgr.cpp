#include "stdafx.h"
#include "ObjectMgr.h"
#include "GameObject.h"

CObjectMgr* CObjectMgr::m_pInstance = nullptr;

CObjectMgr::CObjectMgr()
{
}


CObjectMgr::~CObjectMgr()
{
	Release();
}

void CObjectMgr::AddObject(OBJ_TYPE eType, CGameObject * pObj)
{
	if (pObj == nullptr)
		return;

	m_ObjList[eType].push_back(pObj);
}

void CObjectMgr::Update()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

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

void CObjectMgr::Render(HDC hdc)
{
	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			(*iter_Begin)->Render(hdc);
	}

	ShowInfo(hdc);
}

void CObjectMgr::Release()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			SAFE_RELEASE(*iter_Begin);
	}
}

void CObjectMgr::ShowInfo(HDC hdc)
{
	wsprintf(gameInfo, L"ÃÑ¾ËÀÇ °¹¼ö : %d", m_ObjList[OBJ_BULLET].size());
	TextOut(hdc, 0, 0, gameInfo, wcslen(gameInfo));
}
