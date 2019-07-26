// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

//Standard headers
#include <list>


using namespace std;


//User headers
#include "Define.h"
#include "Extern.h"
#include "Struct.h"
#include "Typedef.h"
#include "Enum.h"
#include "Function.h"
#include "Constants.h"

//Manager headers
#include "CAbstractFactory.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "ObjectMgr.h"