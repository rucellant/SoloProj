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
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

protected:
	// CGameObject을(를) 통해 상속됨
	virtual void Moving() override;

	// CGameObject을(를) 통해 상속됨
	virtual void UpdateRectCollision() override;

	void KeyInput();

	void CreateBullet();

public:
	void SetBulletList(OBJLIST* pBulletList);

	
};

