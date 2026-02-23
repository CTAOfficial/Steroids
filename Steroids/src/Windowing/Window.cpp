#include <iostream>
#include <string>
#include "Window.h"
#include "InputManager.h"

Window::Window(std::string& title, int width, int height)
{
	Width = width;
	Height = height;

	SDL_CreateWindowAndRenderer(
		title.c_str(),
		Width,
		Height,
		NULL,
		&window,
		&renderer
	);

	if (window == nullptr) {
		std::cout << "Failed to initialize SDL Window\n";
	}
	if (renderer == nullptr) {
		std::cout << "Failed to initialize SDL Renderer\n";
	}

	Title = title;
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::Run()
{
	IsRunning = true;
	currentTick = SDL_GetTicks();

	Start();
	while (IsRunning) {
		lastTick = currentTick;
		currentTick = SDL_GetTicks();
		deltaTime = static_cast<double>(currentTick - lastTick) / 1000.0;

		InputManager::Update();
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			HandlePoll(event);
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		Update();
		SDL_RenderPresent(renderer);
	}
}

void Window::HandlePoll(SDL_Event event)
{
	if (event.type == SDL_EVENT_QUIT) { Close(); }

	InputManager::Process(event);
}

void Window::Close()
{
	IsRunning = false;
	OnClose();
	//delete this;
}


Window* Window::Create(std::string title, int width, int height)
{
	Window* window = new Window(title, width, height);
	return window;
}
