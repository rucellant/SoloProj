#pragma once

//½Ì±Û Åæ
class CKeyMgr
{
private:
	static CKeyMgr* m_pInstance;

	DWORD m_dwKey;
	DWORD m_dwKeyDown;
	DWORD m_dwKeyUp;

private:
	CKeyMgr();
	~CKeyMgr();

public:
	static CKeyMgr* GetInstance();

	void DestroyInstance();

public:
	void Update();

	bool KeyPressing(TCHAR _Input);
	bool KeyDown(TCHAR _Input);
	bool KeyUp(TCHAR _Input);

protected:
	DWORD TCHARTODWORD(TCHAR _Input);
};

