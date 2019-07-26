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
	m_tInfo.fX += cosf((float)m_tInfo.theta)*BXSPEED;
	m_tInfo.fY += sinf((float)m_tInfo.theta)*BXSPEED;
}

void CBullet::UpdateRectCollision()
{
	SetIsAlive(!CCollisionMgr::GetInstance()->CollisionRect(this));
}
