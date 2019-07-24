#pragma once
class CGameObject
{
protected:
	INFO m_tInfo;
	RECT m_tRect;

public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void Initialize()		= 0;
	virtual void Update()			= 0;
	virtual void Render(HDC hdc)	= 0;
	virtual void Release()			= 0;

protected:
	void UpdateRect();

	virtual void Moving() = 0;
};

