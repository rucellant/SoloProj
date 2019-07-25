#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::UpdateRect()
{
	m_tRect.left	= static_cast<LONG>(m_tInfo.fX - m_tInfo.fWidth*0.5f);
	m_tRect.right	= static_cast<LONG>(m_tInfo.fX + m_tInfo.fWidth*0.5f);
	m_tRect.top		= static_cast<LONG>(m_tInfo.fY - m_tInfo.fHeight*0.5f);
	m_tRect.bottom	= static_cast<LONG>(m_tInfo.fY + m_tInfo.fHeight*0.5f);
}

void CGameObject::SetPos(INFO tInfo)
{
	m_tInfo.fX = tInfo.fX;
	m_tInfo.fY = tInfo.fY;
}

void CGameObject::SetPos(float x, float y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
}

void CGameObject::SetIsAlive(bool canEdit)
{
	m_tInfo.isAlive = canEdit;
}

void CGameObject::SetAngle(double angle)
{
	m_tInfo.theta = angle;
}

INFO CGameObject::GetInfo() const
{
	return m_tInfo;
}

RECT CGameObject::GetRect() const
{
	return m_tRect;
}
