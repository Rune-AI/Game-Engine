#pragma once
#include "GameObject.h"

namespace dae
{
	class Component
	{
	public:
		virtual ~Component() = default;
		virtual void Update(GameObject& go) = 0;
		virtual void Render(const GameObject& go) const = 0;

		const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
	};
}

