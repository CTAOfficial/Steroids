#include "Game.h"
#include "InputManager.h"
#include "Entities/Player.h"
#include "EntityManager.h"
#include "CollisionSystem.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_sdl3.h"
#include "imgui/backends/imgui_impl_sdlrenderer3.h"
#include "DynamicArray.h"
#include <iostream>


Game::Game(std::string& title, Vector2 size) : Window(title, (int)size.X, (int)size.Y)
{
	screenCenter = Vector2{ size.X * 0.5f, size.Y * 0.5f };
	Bounds = size;

	player = new Player(0, Vector2{ screenCenter.X * 0.5f, Bounds.Y * 0.9f }, RGBA{ 255, 255, 255, 255 });
	player->SetBounds(Bounds);



}

Game::~Game()
{
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
}

void Game::Run()
{
	IsRunning = true;
	currentTick = SDL_GetTicks();

	Start();
	while (IsRunning) {
		lastTick = currentTick;
		currentTick = SDL_GetTicks();
		deltaTime = static_cast<double>(currentTick - lastTick) / 1000.0;

		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();

		InputManager::Update();
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			ImGui_ImplSDL3_ProcessEvent(&event);
			HandlePoll(event);
		}

		if (!IsRunning) { break; }

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		Update();
		ImGui::Render();
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
		SDL_RenderPresent(renderer);

	}
}

void Game::Start()
{

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
}

void Game::Update() {

	if (InputManager::GetKey(SDLK_ESCAPE)) { Close(); }

	EntityManager::PreUpdate();
	EntityManager::Update(*this, deltaTime);
	CollisionSystem::Update(EntityManager::GetEntities());
	EntityManager::Draw(renderer);
	
}

void Game::OnClose()
{
	EntityManager::Shutdown();
}
