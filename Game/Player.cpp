#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_pBulletList = nullptr;

	m_tInfo.isAlive = true;
	m_tInfo.fX		= GAMECX*0.5f;
	m_tInfo.fY		= GAMECY*0.5f;
	m_tInfo.fWidth	= PWIDTH;
	m_tInfo.fHeight = PHEIGHT;
	m_tInfo.fXSpeed = PXSPEED;
	m_tInfo.fYSpeed = PYSPEED;
	m_tInfo.theta	= 0.f;

	CGameObject::UpdateRect();
}

void CPlayer::Update()
{
	Moving();
	UpdateRectCollision();
	CGameObject::UpdateRect();
}

void CPlayer::Render(HDC hdc)
{
	Rectangle(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Moving()
{
	KeyInput();
}

void CPlayer::UpdateRectCollision()
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

void CPlayer::KeyInput()
{
	if (GetAsyncKeyState('W') & 0x8000)
		m_tInfo.fY += m_tInfo.fYSpeed*-1.f;
	if (GetAsyncKeyState('S') & 0x8000)
		m_tInfo.fY += m_tInfo.fYSpeed;
	if (GetAsyncKeyState('A') & 0x8000)
		m_tInfo.fX += m_tInfo.fXSpeed*-1.f;
	if (GetAsyncKeyState('D') & 0x8000)
 		m_tInfo.fX += m_tInfo.fXSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		CreateBullet();
}

void CPlayer::CreateBullet()
{
	CGameObject* pBullet = new CBullet;
	dynamic_cast<CBullet*>(pBullet)->Initialize();
	pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);
	m_pBulletList->push_back(pBullet);
}

void CPlayer::SetBulletList(OBJLIST * pBulletList)
{
	m_pBulletList = pBulletList;
}
