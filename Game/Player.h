#pragma once
#include "GameObject.h"

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();
	
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
};

