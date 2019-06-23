#ifndef STATEOPTIONS_H_
#define STATEOPTIONS_H_

#include <stdlib.h>
#include <Aurealis/Graphics/TextureUtil.h>
#include <Aurealis/Utils/StateManager.h>
#include <Aurealis/Utils/GameState.h>

#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Utils/Logger.h>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/System/SystemManager.h>
#include <Aurealis/Graphics/Camera.h>
#include <Aurealis/Graphics/Sprite.h>

#include <Aurealis/Audio/SoundManager.h>

using namespace Aurealis::Graphics;
using namespace Aurealis::Utils;
using namespace Aurealis::System;
using namespace Aurealis::Audio;
using namespace Aurealis;

class StateOptions : public CGameState
{
public:
	StateOptions();
	virtual ~StateOptions();

	void Init();
	void Enter();
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(StateManager* sManager);
	void Update(StateManager* sManager);
	void Draw(StateManager* sManager);
	void DrawText(int x,int y, unsigned int color, float size, const char *message, ...);

private:
	Sprite *buttonSprite;
	Sprite *sbuttonSprite;
	Sprite *nbuttonSprite;
	Sprite *halfbuttonSprite;
	Sprite *halfsbuttonSprite;
	Sprite *moverSprite;
	Sprite *smoverSprite;
	Sprite *backSprite;


	int selectPos;
	int menuState;//0 main,1 load,2 options

	Texture *texButtons, *texDirt;

	//controls
	int controlPos;
	int controlStart;
	int controlEnd;

	//choosing key
	bool chooseKeyState;
	bool configChanged;
	int currentKey;
	int newKey;

	//analog stick
	int currentAnalogPos;

};

#endif
