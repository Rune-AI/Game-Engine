#pragma once
#include "Singleton.h"
#include <chrono>

namespace dae
{
	class Time final : public Singleton<Time>
	{
	public:
		void CalculateDeltaTime();
		float GetDeltaTime();
	private:
		float m_DeltaTime;
		std::chrono::steady_clock::time_point m_LastTime;
	};
}