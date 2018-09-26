#include "InputManager.h"

InputManager* InputManager::sInstance = nullptr;

InputManager* InputManager::Instance()
{
	if (sInstance == nullptr)
		sInstance = new InputManager();

	return sInstance;
}

void InputManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{
	
}

bool InputManager::KeyDown(SDL_Scancode scanCode)
{
	return mKeyboardStates[scanCode];
}

void InputManager::Update()
{
	mKeyboardStates = SDL_GetKeyboardState(nullptr);
}




