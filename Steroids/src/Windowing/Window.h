#pragma once
#include <SDL3/SDL.h>
#include <string>

class Window {

protected:
	Window(std::string& title, int width, int height);

	bool IsRunning = false;
	SDL_Window* window;
	SDL_Renderer* renderer;

	double deltaTime = 0.0;
	Uint64 lastTick{ 0 };
	Uint64 currentTick{ 0 };

	virtual void Start() {}
	virtual void HandlePoll(SDL_Event event);
	virtual void Update() {}
	virtual void OnClose(){}

public:
	~Window();	

	std::string Title;
	int Width;
	int Height;

	virtual void Run();
	void Close();

	static Window* Create(std::string title, int width, int height);
};