#pragma once

class CGameObject;

class CObjectMgr
{
private:
	static CObjectMgr* m_pInstance;

	OBJLIST m_ObjList[OBJ_END];

	TCHAR gameInfo[100];

private:
	CObjectMgr();
	~CObjectMgr();

public:
	static CObjectMgr* GetInstance()
	{
		if (m_pInstance == nullptr)
			m_pInstance = new CObjectMgr;

		return m_pInstance;
	}

	void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void AddObject(OBJ_TYPE eType, CGameObject* pObj);
	void Update();
	void Render(HDC hdc);

	OBJLIST* GetObjList(OBJ_TYPE eType);

private:
	void Release();

	void ShowInfo(HDC hdc);
};

