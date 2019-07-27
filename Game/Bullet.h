#pragma once
#include "GameObject.h"

class CBullet : public CGameObject
{
private:
	float m_fDistance;
	float m_fTargetX;
	float m_fTargetY;

public:
	CBullet();
	virtual ~CBullet();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

protected:
	virtual void Moving() override;
	
	virtual void UpdateRectCollision() override;

private:
	//��ǥ���� ���� ���ϴ� �Լ�
	void ChaseTarget();

	//���� ����� ���͸� ã�� �Լ�
	CGameObject* FindNearTarget(OBJLIST* objList);
};

