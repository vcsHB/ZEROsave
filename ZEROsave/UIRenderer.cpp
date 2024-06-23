#include "UIRenderer.h"

void UIRenderer::Initialize(Player* player, Map* map, WindowManager* windowManager)
{
	_player = player;
	_map = map;
	_windowManager = windowManager;
}

void UIRenderer::Render()
{
	GotoPos(0, 0);
	SetColor((int)COLOR::LIGHT_BLUE);
	GotoPos(0, 1);
	cout << "                                        ";
	cout << "\r¢º NOW ADDRESS  \t|\t" << _player->position.x << ", " << _player->position.y;
	GotoPos(0, 2);
	cout << "                                        ";
	cout << "\r¢º TARGET ADDRESS\t|\t" << _player->newPosition.x << ", " << _player->newPosition.y;

	GotoPos(_windowManager->windowSizeX / 2 - 10, _windowManager->windowSizeY - 3);
	int hp = _player->HealthCompo->GetCurrentHP();
	int maxHp = _player->HealthCompo->maxHP;
	_player->HealthCompo->TakeDamage(1);

	int fillAmount = (int)(((float)hp / maxHp) * 20);
	SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::LIGHT_BLUE);
	for (int i = 0; i < fillAmount; i++)
	{
		wcout << GAUGE_TILESET[0];
	}
	SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::BLUE);
	if (fillAmount > 0) {

		for (int i = 0; i < 20 - fillAmount; i++)
		{
			wcout << GAUGE_TILESET[0];
		}
	}

	SetColor();
}
