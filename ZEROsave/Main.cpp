#include "Define.h"


int main()
{

	SceneManager *sceneManager = new SceneManager();
	sceneManager->Initialize();
	sceneManager->Start();

	delete &sceneManager;
}
