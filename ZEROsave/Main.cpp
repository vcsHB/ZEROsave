#include "Define.h"

int main()
{
	SceneManager sceneManager = SceneManager();
	sceneManager.Initialize();
	sceneManager.Start();

	delete &sceneManager;
}
