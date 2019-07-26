// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

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