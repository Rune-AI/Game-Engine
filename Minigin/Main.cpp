#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
//#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextRenderComponent.h"
#include "Scene.h"
#include "TextureRenderComponent.h"
#include "FPSComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	/*auto fpsCounter = std::make_shared<dae::GameObject>();
	fpsCounter->AddComponent<dae::TextRenderComponent>();
	fpsCounter->AddComponent<dae::FPSComponent>();
	scene.Add(fpsCounter);*/

	auto go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::TextureRenderComponent>("background.tga");
	scene.Add(go);


	/*go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextRenderComponent>();
	go->AddComponent<dae::FPSComponent>();
	scene.Add(go);*/

	/*go = std::make_shared<dae::GameObject>();
	rc = std::make_shared<dae::TextureRenderComponent>();
	rc->SetTexture("logo.tga");
	go->AddComponent(rc);
	go->SetPosition(216, 180);
	scene.Add(go);*/

	//go = std::make_shared<dae::GameObject>();
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	//auto to = std::make_shared<dae::TextRenderComponent>("FPS", font);
	//auto fps = std::make_shared<dae::FPSComponent>(to);
	//go->AddComponent(fps);
	//go->AddComponent(to);
	//scene.Add(go);

	//go = std::make_shared<dae::GameObject>();
	//font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//to = std::make_shared<dae::TextRenderComponent>("Programming 4 Assignment", font);
	//go->AddComponent(to);
	//go->SetPosition(80, 20);
	//scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}