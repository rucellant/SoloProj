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
	if (pObj->GetInfo().fX - pObj->GetInfo().fWidth*0.5f <= 0  ||
		pObj->GetInfo().fX + pObj->GetInfo().fWidth*0.5f >= 0  ||
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

	for (; pSource->end() != Siter; ++Siter)
	{
		for (; pDest->end() != Diter; ++Diter)
		{
			float a = powf((*Siter)->GetInfo().fX - (*Diter)->GetInfo().fX, 2);
			float b = powf((*Siter)->GetInfo().fY - (*Diter)->GetInfo().fY, 2);

			float l = sqrtf(a + b);

			if (l <= (*Siter)->GetInfo().fWidth*0.5f + (*Diter)->GetInfo().fWidth*0.5f)
			{
				(*Siter)->SetIsAlive(false);
				(*Diter)->SetIsAlive(false);
			}
		}
	}
}

void CCollisionMgr::CollisionRectEX(OBJLIST * pSource, OBJLIST * pDest)
{
}
