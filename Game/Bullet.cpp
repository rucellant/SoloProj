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

	CGameObject::UpdateRect();
}

void CBullet::Update()
{
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
}

void CBullet::UpdateRectCollision()
{
	if (CCollisionMgr::GetInstance()->CollisionRect(this))
	{
		if (m_tInfo.fX - m_tInfo.fWidth*0.5f <= 0)
			SetPos(m_tInfo.fWidth*0.5f, m_tInfo.fY);
		if (m_tInfo.fX + m_tInfo.fWidth*0.5f >= GAMECX)
			SetPos(GAMECX - m_tInfo.fWidth*0.5f, m_tInfo.fY);
		if (m_tInfo.fY - m_tInfo.fHeight*0.5f <= 0)
			SetPos(m_tInfo.fX, m_tInfo.fHeight*0.5f);
		if (m_tInfo.fY + m_tInfo.fWidth*0.5f >= GAMECY)
			SetPos(m_tInfo.fX, GAMECY - m_tInfo.fHeight*0.5f);
	}
}
