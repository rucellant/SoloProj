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
}
