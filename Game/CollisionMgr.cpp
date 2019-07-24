#include "stdafx.h"
#include "CollisionMgr.h"
#include "GameObject.h"

CCollisionMgr* CCollisionMgr::m_pInstance = nullptr;

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::CollisionRect(CGameObject * pObj)
{
	if (pObj->GetInfo().fX - pObj->GetInfo().fWidth*0.5f <= 0 ||
		pObj->GetInfo().fX + pObj->GetInfo().fWidth*0.5f >= 0 ||
		pObj->GetInfo().fY - pObj->GetInfo().fHeight*0.5f <= 0 ||
		pObj->GetInfo().fY + pObj->GetInfo().fHeight*0.5f >= 0)
		return true;
	else
		return false;
	/*if (pObj->GetInfo().fX - pObj->GetInfo().fWidth*0.5f <= 0)
		return COL_LEFT;
	if (pObj->GetInfo().fX + pObj->GetInfo().fWidth*0.5f >= 0)
		return COL_RIGHT;
	if (pObj->GetInfo().fY - pObj->GetInfo().fHeight*0.5f <= 0)
		return COL_TOP;
	if (pObj->GetInfo().fY + pObj->GetInfo().fHeight*0.5f >= 0)
		return COL_RIGHT;*/
}
