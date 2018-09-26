#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H
#include <SDL_hints.h>
#include <SDL.h>

class InputManager
{
private:
	static InputManager* sInstance;

	const Uint8* mKeyboardStates;
public:
	static InputManager* Instance();
	static void Release();

	bool KeyDown(SDL_Scancode scanCode);
	void Update();

private:
	InputManager();
	~InputManager();
};

#endif
