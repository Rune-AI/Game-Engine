#include "TextureRenderComponent.h"
#include "Transform.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::TextureRenderComponent::TextureRenderComponent(GameObject* object)
	: Component{ object }
{
}

dae::TextureRenderComponent::TextureRenderComponent(GameObject* object, const std::string& textureFile)
	: Component{ object },
	m_pTexture{ ResourceManager::GetInstance().LoadTexture(textureFile) }
{
}

void dae::TextureRenderComponent::Update()
{
}

void dae::TextureRenderComponent::Render() const
{
	//const auto& pos = m_pOwner->GetTransform()->GetLocalPosition();
	//Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
}

void dae::TextureRenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}
