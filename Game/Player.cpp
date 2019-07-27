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
	m_tInfo.isAlive = true;
	m_tInfo.fX		= GAMECX*0.5f;
	m_tInfo.fY		= GAMECY*0.5f;
	m_tInfo.fWidth	= PWIDTH;
	m_tInfo.fHeight = PHEIGHT;
	m_tInfo.fXSpeed = PXSPEED;
	m_tInfo.fYSpeed = PYSPEED;
	m_tInfo.theta	= M_PI*1.5f;
	m_Barrel		= BLENGTH;

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
	DrawBarrel(hdc);
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
	if (m_tInfo.theta >= 2 * M_PI || m_tInfo.theta <= -1 * 2 * M_PI)
		m_tInfo.theta = 0;

	if (CKeyMgr::GetInstance()->KeyPressing('W'))
	{
		m_tInfo.fX += cosf((float)m_tInfo.theta)*m_tInfo.fXSpeed;
		m_tInfo.fY += sinf((float)m_tInfo.theta)*m_tInfo.fYSpeed;
	}
	if (CKeyMgr::GetInstance()->KeyPressing('S'))
	{
		m_tInfo.fX += -1*cosf((float)m_tInfo.theta)*m_tInfo.fXSpeed;
		m_tInfo.fY += -1*sinf((float)m_tInfo.theta)*m_tInfo.fYSpeed;
	}
	if (CKeyMgr::GetInstance()->KeyPressing('A'))
		m_tInfo.theta += -1 * (M_PI / 180)*ROTATESPEED;
	if (CKeyMgr::GetInstance()->KeyPressing('D'))
		m_tInfo.theta += 1 * (M_PI / 180)*ROTATESPEED;
	if (CKeyMgr::GetInstance()->KeyDown(VK_SPACE))
		CObjectMgr::GetInstance()->AddObject(OBJ_BULLET, CreateBullet());
}

CGameObject* CPlayer::CreateBullet()
{
	CGameObject* pObj = CAbstractFactory<CBullet>::CreateObject(cosf((float)m_tInfo.theta)*m_Barrel + m_tInfo.fX,
		sinf((float)m_tInfo.theta)*m_Barrel + m_tInfo.fY,
		(float)m_tInfo.theta);
	
	return pObj;
}

void CPlayer::DrawBarrel(HDC hdc)
{
	MoveToEx(hdc, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hdc, static_cast<int>(cosf((float)m_tInfo.theta)*m_Barrel + m_tInfo.fX),
		static_cast<int>(sinf((float)m_tInfo.theta)*m_Barrel + m_tInfo.fY));
}
