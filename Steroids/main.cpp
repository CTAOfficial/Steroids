#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_image/SDL_image.h>
#include "src/Windowing/Window.h"
#include "src/Game.h"
#include "DynamicArray.h"
#include <string>

static bool Initialize() {

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL Failed to initialize.\n";
		return false;
	}
	if (!TTF_Init()) {
		std::cout << "SDL_TTF Failed to initialize.\n";
		return false;
	}


	if (!MIX_Init()) {
		std::cerr << "SDL_Mixer Failed to Initialize. " << SDL_GetError() << "\n";
		return false;
	}

	return true;
}

int main() {

	if (!Initialize()) {
		return -1;
	}

	/*DynamicArray<int> array(2);
	array.push_back(5);
	array.push_back(7);
	array.push_back(7);
	array.push_back(58);
	array.push_back(12);
	for (int i = 0; i < array.Size(); i++) {
		std::cout << array.GetValue(i) << "\n";
	}*/

	std::string name = "Steroids";
	Game* game = new Game(name, Vector2{ 720, 1080 });

	game->Run();

	delete game;
	game = nullptr;

	TTF_Quit();
	SDL_Quit();
	return 0;
}

