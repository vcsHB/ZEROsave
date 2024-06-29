#include "Define.h"


int main()
{

	SceneManager *sceneManager = new SceneManager();
	sceneManager->Initialize();
	sceneManager->Start();
	cout << "Á¾·á";
	delete &sceneManager;
}
