#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"

class GameManager
{
	
private:
	static GameManager* sInstance;

	const int FRAME_RATE = 60;

	bool mQuit;
	Graphics* mGraphics;
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;
	AudioManager* mAudioMgr;
	Timer* mTimer;

	SDL_Event mEvents;

	Texture* mTex;
	AnimatedTexture* mAniTex;

public:

	static GameManager* Instance();
	static void Release();

	void Run();

private:
	GameManager();
	~GameManager();
};

#endif
  