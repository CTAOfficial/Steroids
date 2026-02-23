#pragma once
#include <SDL3/SDL_events.h>
#include <list>
#include <vector>

static class InputManager {

private:
	static std::vector<SDL_Keycode> downKeys;
	static std::vector<SDL_Keycode> upKeys;
	static std::vector<SDL_Keycode> pressedKeys;

	static void HandleKeyDown(SDL_Keycode key);
	static void HandleKeyUp(SDL_Keycode key);

public:
	static void Process(SDL_Event& event);	

	static void Update();
	static bool GetKey(SDL_Keycode key);
	static bool GetKeyUp(SDL_Keycode key);
	static bool GetKeyDown(SDL_Keycode key);
};