#include "RenderComponent.h"
#include "Transform.h"
#include "ResourceManager.h"
#include "Renderer.h"

void dae::RenderComponent::Update(GameObject& go)
{
	go.GetTransfrom();
}

void dae::RenderComponent::Render(const GameObject& go) const
{
	const auto& pos = go.GetTransfrom().GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::RenderComponent::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}
