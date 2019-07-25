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
}

void CCollisionMgr::CollisionSphere(OBJLIST * pSource, OBJLIST * pDest)
{
	OBJLIST::iterator Siter = pSource->begin();
	OBJLIST::iterator Diter = pDest->begin();
}

void CCollisionMgr::CollisionRectEX(OBJLIST * pSource, OBJLIST * pDest)
{
}
