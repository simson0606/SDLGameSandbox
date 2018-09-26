#include "GameManager.h"

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance()
{
	if (sInstance == nullptr)
		sInstance = new GameManager;

	return sInstance;
}

void GameManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

GameManager::GameManager()
{
	mQuit = false;

	mGraphics = Graphics::Instance();

	if (!Graphics::Initialized())
		mQuit = true;
	mAudioMgr = AudioManager::Instance();

	mAssetMgr = AssetManager::Instance();

	mInputMgr = InputManager::Instance();
	
	mTimer = Timer::Instance();

	mTex = new Texture("BLAZEIT!", "Blazed.ttf", 72, {0,60,0});
	mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, 80));

	mAniTex = new AnimatedTexture("SpriteSheet.png", 0, 0, 48, 48, 4, 1.0f, AnimatedTexture::vertical);
	mAniTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

}

GameManager::~GameManager()
{
	AudioManager::Release();
	mAudioMgr = nullptr;

	AssetManager::Release();
	mAssetMgr = nullptr;

	Graphics::Release();
	mGraphics = nullptr;

	InputManager::Release();
	mInputMgr = nullptr;

	Timer::Release();
	mTimer = nullptr;

	delete mTex;
	mTex = nullptr;

	delete mAniTex;
	mAniTex = nullptr;
}

void GameManager::Run()
{
	mAudioMgr->PlayMusic("Bionic Commando (Rusko Remix).mp3");
	while (!mQuit)
	{
		mTimer->Update();

		while (SDL_PollEvent(&mEvents) != 0)
		{
			if (mEvents.type == SDL_QUIT)
				mQuit = true;

		}
		if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {

			mInputMgr->Update();

			if (mInputMgr->KeyDown(SDL_SCANCODE_W))
			{
				mAniTex->Translate(Vector2(0.0f, -40.0f) * mTimer->DeltaTime());
			}
			else if(mInputMgr->KeyDown(SDL_SCANCODE_S))
			{
				mAniTex->Translate(Vector2(0.0f, 40.0f) * mTimer->DeltaTime());
			}
			else if (mInputMgr->KeyDown(SDL_SCANCODE_A))
			{
				mAniTex->Translate(Vector2(-40.0f, 0.0f) * mTimer->DeltaTime());
			}
			else if (mInputMgr->KeyDown(SDL_SCANCODE_D))
			{
				mAniTex->Translate(Vector2(40.0f, 0.0f) * mTimer->DeltaTime());
			}
			else if (mInputMgr->KeyDown(SDL_SCANCODE_SPACE))
			{
				mAudioMgr->PlaySFX("Shotgun.wav");
			}
			else if (mInputMgr->KeyDown(SDL_SCANCODE_P))
			{
				mAudioMgr->PauseMusic();
			}
			else if (mInputMgr->KeyDown(SDL_SCANCODE_R))
			{
				mAudioMgr->ResumeMusic();
			}

			mAniTex->Update();

			mGraphics->ClearBackBuffer();

			mTex->Render();
			mAniTex->Render();

			mGraphics->Render();

			mTimer->Reset();
		}

	}
}




