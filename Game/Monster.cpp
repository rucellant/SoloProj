#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.isAlive = true;
	m_tInfo.fX		= static_cast<float>(rand() % (GAMECX - 100) + 50);
	m_tInfo.fY		= static_cast<float>(rand() % (GAMECY - 100) + 50);
	m_tInfo.fWidth	= MWIDTH;
	m_tInfo.fHeight = MHEIGHT;
	m_tInfo.fXSpeed = MXSPEED;
	m_tInfo.fYSpeed = MYSPEED;
	m_tInfo.theta	= 0.f;

	CGameObject::UpdateRect();
}

void CMonster::Update()
{
	Moving();
	UpdateRectCollision();
	CGameObject::UpdateRect();
}

void CMonster::Render(HDC hdc)
{
	Rectangle(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

void CMonster::Moving()
{
	m_tInfo.fX += m_tInfo.fXSpeed;
	m_tInfo.fY += m_tInfo.fYSpeed;
}

void CMonster::UpdateRectCollision()
{
	if (CCollisionMgr::GetInstance()->CollisionRect(this))
	{
		if (m_tInfo.fX - m_tInfo.fWidth*0.5f <= 0)
			m_tInfo.fXSpeed *= -1.f;
		if (m_tInfo.fX + m_tInfo.fWidth*0.5f >= GAMECX)
			m_tInfo.fXSpeed *= -1.f;
		if (m_tInfo.fY - m_tInfo.fHeight*0.5f <= 0)
			m_tInfo.fYSpeed *= -1.f;
		if (m_tInfo.fY + m_tInfo.fWidth*0.5f >= GAMECY)
			m_tInfo.fYSpeed *= -1.f;
	}
}

bool CMonster::isDying()
{
	return false;
}
