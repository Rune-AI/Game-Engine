#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "RenderComponent.h"
#include "FPSComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	auto rc = std::make_shared<dae::RenderComponent>();
	rc->SetTexture("background.tga");
	go->AddComponent(rc);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	rc = std::make_shared<dae::RenderComponent>();
	rc->SetTexture("logo.tga");
	go->AddComponent(rc);
	go->SetPosition(216, 180);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	auto to = std::make_shared<dae::TextObject>("FPS", font);
	auto fps = std::make_shared<dae::FPSComponent>(to);
	go->AddComponent(fps);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	go->AddComponent(to);
	go->SetPosition(80, 20);
	scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}