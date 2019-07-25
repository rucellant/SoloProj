#pragma once
#include "GameObject.h"

class CBullet;

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

	OBJLIST* m_pBulletList;
	
public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

protected:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Moving() override;

	// CGameObject��(��) ���� ��ӵ�
	virtual void UpdateRectCollision() override;

	void KeyInput();

	void CreateBullet();

public:
	void SetBulletList(OBJLIST* pBulletList);

	
};

