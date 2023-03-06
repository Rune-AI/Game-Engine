#include <stdexcept>
#include <SDL_ttf.h>
#include "TextRenderComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Component.h"


dae::TextRenderComponent::TextRenderComponent(GameObject* object)
	: Component{ object }, 
	m_font{ dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36) }
{
}

dae::TextRenderComponent::TextRenderComponent(GameObject* object, const std::string& text)
	: Component{ object },
	m_text{ text },
	m_font{ dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36) }
{
}

dae::TextRenderComponent::TextRenderComponent(GameObject* object, const std::string& text, std::shared_ptr<Font> font)
	: Component{ object },
	m_text{ text },
	m_font{ font }
{
}

void dae::TextRenderComponent::Update()
{
	if (m_needsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::TextRenderComponent::Render() const
{
	/*if (m_textTexture != nullptr)
	{
		const auto& pos = m_pOwner->GetTransfrom().GetPosition();
		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
	}*/
}

// This implementation uses the "dirty flag" pattern
void dae::TextRenderComponent::SetText(const std::string& text)
{
	m_text = text;
	m_needsUpdate = true;
}


