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
