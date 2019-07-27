#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.isAlive = true;
	m_tInfo.fX = GAMECX*0.5f;
	m_tInfo.fY = GAMECY*0.5f;
	m_tInfo.fWidth = BWIDTH;
	m_tInfo.fHeight = BHEIGHT;
	m_tInfo.fXSpeed = BXSPEED;
	m_tInfo.fYSpeed = BYSPEED;
	m_tInfo.theta = 0.f;

	m_fDistance = 1110.f;
	m_fTargetX = 0.f;
	m_fTargetY = 0.f;

	CGameObject::UpdateRect();
}

void CBullet::Update()
{
	ChaseTarget();
	Moving();
	UpdateRectCollision();
	CGameObject::UpdateRect();
}

void CBullet::Render(HDC hdc)
{
	Ellipse(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::Moving()
{
	ChaseTarget();
}

void CBullet::UpdateRectCollision()
{
	if(m_tInfo.isAlive)
		SetIsAlive(!CCollisionMgr::GetInstance()->CollisionRect(this));
}

void CBullet::ChaseTarget()
{
	CGameObject* pObj = FindNearTarget(CObjectMgr::GetInstance()->GetObjList(OBJ_MONSTER));
	
	if (pObj == nullptr)
	{
		m_tInfo.fX += cosf((float)m_tInfo.theta)*BXSPEED;
		m_tInfo.fY += sinf((float)m_tInfo.theta)*BXSPEED;
		
		return;
	}

	m_tInfo.theta = acosf(fabsf(pObj->GetInfo().fX - m_tInfo.fX) / m_fDistance);

	if (pObj->GetInfo().fX >= m_tInfo.fX)
		m_tInfo.fX += cosf((float)m_tInfo.theta)*BXSPEED;
	else
		m_tInfo.fX -= cosf((float)m_tInfo.theta)*BXSPEED;

	if (pObj->GetInfo().fY >= m_tInfo.fY)
		m_tInfo.fY += sinf((float)m_tInfo.theta)*BYSPEED;
	else
		m_tInfo.fY -= sinf((float)m_tInfo.theta)*BYSPEED;

}

CGameObject* CBullet::FindNearTarget(OBJLIST* objList)
{
	if (objList->size() <= 0)
		return nullptr;

	CGameObject* pObj = nullptr;

	OBJLIST::iterator iter = objList->begin();

	float a = (*iter)->GetInfo().fX - m_tInfo.fX;
	float b = (*iter)->GetInfo().fY - m_tInfo.fY;

	float r = sqrtf(a*a + b*b);

	m_fTargetX = a;
	m_fTargetY = b;

	m_fDistance = r;
	pObj = *(iter);
	iter++;

	for (; iter != objList->end(); ++iter)
	{
		float a = (*iter)->GetInfo().fX - m_tInfo.fX;
		float b = (*iter)->GetInfo().fY - m_tInfo.fY;

		float r = sqrtf(a*a + b*b);

		if (r < m_fDistance)
		{
			m_fTargetX = a;
			m_fTargetY = b;

			m_fDistance = r;
			pObj = *iter;
		}
	}

	return pObj;
}