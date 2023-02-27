#include "FPSComponent.h"
#include "Time.h"
#include "TextObject.h"

dae::FPSComponent::FPSComponent(std::shared_ptr<TextObject> to)
	: m_TextObject(to),
	m_FPS(0)
{
}

dae::FPSComponent::~FPSComponent()
{
}

void dae::FPSComponent::Update(GameObject& go)
{
	auto& time = Time::GetInstance();
	m_FPS = int(1 / time.GetDeltaTime());

	go.GetTransfrom();
	m_TextObject->Update(go);
}

void dae::FPSComponent::Render(const GameObject& go) const
{
	go.GetTransfrom();
	
	m_TextObject->SetText("FPS: " + std::to_string(m_FPS));
	m_TextObject->Render(go);
}
