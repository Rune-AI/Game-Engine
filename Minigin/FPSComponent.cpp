#include "FPSComponent.h"
#include "Time.h"
#include "TextRenderComponent.h"

dae::FPSComponent::FPSComponent(GameObject* object)
	: Component{ object },
	m_FPS{}
{
	//static_assert(object->hasComponent<TextRenderComponent>(), "FPSComponent needs a TextRenderComponent");
	m_TextRenderComponent = m_pOwner->GetComponent<TextRenderComponent>();
}

dae::FPSComponent::~FPSComponent()
{
}

void dae::FPSComponent::Update()
{
	auto& time = Time::GetInstance();
	m_FPS = int(1 / time.GetDeltaTime());

	m_TextRenderComponent->Update();
}

void dae::FPSComponent::Render() const
{
	m_TextRenderComponent->SetText("FPS: " + std::to_string(m_FPS));
	
	//m_TextObject->Render(go);
	// todo: do not dubble render, it is already called in the update of gameobject ALSO component should not be an owner of component, a reference is fine
}
