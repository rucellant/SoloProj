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
	virtual void Moving() = 0;

	//����ȭ�� ������ �浹 �˻�
	virtual void UpdateRectCollision() = 0;

protected:
	void UpdateRect();

public:
	//set
	void SetPos(INFO tInfo);
	void SetPos(float x, float y);
	void SetIsAlive(bool canEdit);

	//get
	INFO GetInfo() const;
	RECT GetRect() const;
	
};

