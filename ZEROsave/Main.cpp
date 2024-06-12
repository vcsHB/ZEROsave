#include "Define.h"

class a
{

};
class test
{
	a m_a;
};
int main()
{
	test t;

	SceneManager *sceneManager = new SceneManager();
	sceneManager->Initialize();
	sceneManager->Start();

	delete &sceneManager;
}
