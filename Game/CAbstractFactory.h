#pragma once

class CGameObject;

//�߻� ���丮 ����
template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() = default;
	~CAbstractFactory() = default;

public:
	static CGameObject* CreateObject()
	{
		CGameObject* pObj = new T;
		dynamic_cast<T*>(pObj)->Initialize();

		return pObj;
	}

	static CGameObject* CreateObject(float x, float y)
	{
		CGameObject* pObj = new T;
		dynamic_cast<T*>(pObj)->Initialize();
		pObj->SetPos(x, y);

		return pObj;
	}
};


