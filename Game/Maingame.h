#pragma once
class CMaingame
{
private:

public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();
};

