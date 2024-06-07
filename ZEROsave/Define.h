#pragma once
#include <iostream>
using std::cout;
using std::wcout;
using std::endl;
#include <Windows.h>
//#define GET_SINGLE(c) c::GetInstance();
#define SAFE_DELETE(p) if (p != nullptr){ delete p;  p = nullptr; }

#include "Core/Scene/GameLogic.h"
#include "Core/Scene/SceneManager.h"
#include "Core/Scene/TitleScene.h"
#include "Core/Scene/GameScene.h"

