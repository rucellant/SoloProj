#pragma once

typedef struct tagInfo
{
	//생사여부
	bool isAlive;

	//좌표
	float fX;
	float fY;

	//크기
	float fWidth;
	float fHeight;

	//속도
	float fXSpeed;
	float fYSpeed;

	//각도
	double theta;
}INFO;