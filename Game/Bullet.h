#pragma once
#include "GameObject.h"

class CBullet : public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

protected:
	virtual void Moving() override;
	
	virtual void UpdateRectCollision() override;
};

