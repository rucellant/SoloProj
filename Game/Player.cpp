#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
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
	if (GetAsyncKeyState('W') & 0x8000)
		m_tInfo.fY += m_tInfo.fYSpeed*-1.f;
	if (GetAsyncKeyState('S') & 0x8000)
		m_tInfo.fY += m_tInfo.fYSpeed;
	if (GetAsyncKeyState('A') & 0x8000)
		m_tInfo.fX += m_tInfo.fXSpeed*-1.f;
	if (GetAsyncKeyState('D') & 0x8000)
		m_tInfo.fX += m_tInfo.fXSpeed;
}
