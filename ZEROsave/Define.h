#pragma once
#include <iostream>
using std::cout;
using std::wcout;
using std::endl;
#include <Windows.h>
#include "SceneManager.h"

//#define GET_SINGLE(c) c::GetInstance();
#define SAFE_DELETE(p) if (p != nullptr){ delete p;  p = nullptr; }


