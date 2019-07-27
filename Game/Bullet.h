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
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

protected:
	virtual void Moving() override;
	
	virtual void UpdateRectCollision() override;

private:
	//목표와의 각도 구하는 함수
	void ChaseTarget();

	//가장 가까운 몬스터를 찾는 함수
	CGameObject* FindNearTarget(OBJLIST* objList);
};

