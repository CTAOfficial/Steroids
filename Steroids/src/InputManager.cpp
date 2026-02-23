#include "InputManager.h"
#include <algorithm>
#include <iostream>


std::vector<SDL_Keycode> InputManager::downKeys;
std::vector<SDL_Keycode> InputManager::upKeys;
std::vector<SDL_Keycode> InputManager::pressedKeys;

void InputManager::Process(SDL_Event& event)
{
	switch (event.type)
	{

	case SDL_EVENT_KEY_DOWN:
		InputManager::HandleKeyDown(event.key.key);
		break;
	case SDL_EVENT_KEY_UP:
		InputManager::HandleKeyUp(event.key.key);
		break;
	}
}

void InputManager::HandleKeyDown(SDL_Keycode key)
{
	auto iterator = std::find(downKeys.begin(), downKeys.end(), key);
	if (iterator != downKeys.end()) {
		return;
	}

	pressedKeys.push_back(key);
	downKeys.push_back(key);
}

void InputManager::HandleKeyUp(SDL_Keycode key)
{
	upKeys.push_back(key);

	auto iterator = std::find(downKeys.begin(), downKeys.end(), key);
	if (iterator != downKeys.end()) {
		downKeys.erase(iterator);
	}
}

void InputManager::Update()
{
	pressedKeys.clear();
	upKeys.clear();
}

bool InputManager::GetKey(SDL_Keycode key)
{
	for (int i = 0; i < pressedKeys.size(); i++) {
		if (pressedKeys[i] == key) { return true; }
	}
	return false;
}

bool InputManager::GetKeyUp(SDL_Keycode key)
{
	for (int i = 0; i < upKeys.size(); i++) {
		if (upKeys[i] == key) { return true; }
	}
	return false;
}

bool InputManager::GetKeyDown(SDL_Keycode key)
{
	for (int i = 0; i < downKeys.size(); i++) {
		if (downKeys[i] == key) { return true; }
	}

	return false;
}
