#pragma once
#include "GameObject.h"

class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

public:
	virtual void Moving() override;

protected:
	// CGameObject을(를) 통해 상속됨
	virtual void UpdateRectCollision() override;
};

