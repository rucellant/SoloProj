#pragma once

class CGameObject;

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
};

