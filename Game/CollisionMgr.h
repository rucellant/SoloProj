#pragma once

class CGameObject;

//싱글톤
class CCollisionMgr
{
private:
	static CCollisionMgr* m_pInstance;

private:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static CCollisionMgr* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new CCollisionMgr;
			
			return m_pInstance;
		}

		return m_pInstance;
	}

	static void DestroyInstance()
	{
		if (m_pInstance != nullptr)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	bool CollisionRect(CGameObject* pObj);

	//객체 간의 원형 충돌 검사
	void CollisionSphere(OBJLIST* pSource, OBJLIST* pDest);

	//객체간의 사각형 충돌 검사
	void CollisionRectEX(OBJLIST* pSource, OBJLIST* pDest);
};

