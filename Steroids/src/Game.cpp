#include "Game.h"
#include "InputManager.h"
#include "Entities/Player.h"
#include "EntityManager.h"
#include "CollisionSystem.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_sdl3.h"
#include "imgui/backends/imgui_impl_sdlrenderer3.h"
#include "Sprite.h"
#include "DynamicArray.h"
#include <iostream>
#include <SDL3_image/SDL_image.h>
#include <WidgetManager.h>
#include <AsteroidManager.h>


Game::Game(std::string& title, Vector2 size) : Window(title, (int)size.X, (int)size.Y)
{
	screenCenter = Vector2{ size.X * 0.5f, size.Y * 0.5f };
	Bounds = size;

	Sprite::MissingSprite = new Sprite{ renderer, "build/images/MissingSprite.png" };

	player = new Player(0, renderer, Vector2{ screenCenter.X * 0.5f, Bounds.Y * 0.5f });
	player->SetBounds(Bounds);

	player->SetUpKey(SDLK_W);
	player->SetDownKey(SDLK_S);
	player->SetLeftKey(SDLK_A);
	player->SetRightKey(SDLK_D);

	SteroidManager = new AsteroidManager();

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
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();

		InputManager::Update();
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			ImGui_ImplSDL3_ProcessEvent(&event);
			HandlePoll(event);
		}

		if (!IsRunning) { break; }

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderClear(renderer);
		Update();
		ImGui::Render();
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
		SDL_RenderPresent(renderer);

	}
}

void Game::Start()
{
	LoadIcon();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);

	SteroidManager->Load(renderer);
}
void Game::LoadIcon() {
	SDL_Surface* icon = IMG_Load("build/icon.png");
	SDL_SetWindowIcon(window, icon);
	SDL_DestroySurface(icon);
}

void Game::Update() {

	if (InputManager::GetKey(SDLK_ESCAPE)) { Close(); return; }

	lastTick = currentTick;
	currentTick = SDL_GetTicks();
	double dt = static_cast<double>(currentTick - lastTick) / 1000.0;

	WidgetManager::PreUpdate();
	EntityManager::PreUpdate();
	SteroidManager->Update();
	EntityManager::Update(*this, dt);
	WidgetManager::Update();
	//CollisionSystem::Update(EntityManager::GetEntities());
	EntityManager::Draw(renderer);
	
}

void Game::OnClose()
{
	EntityManager::Shutdown();
}
