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
		float GetFixedTimeStep();
		int GetSleepTime();
	private:
		float m_DeltaTime{};
		const float m_FixedTimeStep{0.03f};
		const float m_DesiredFPS{60.f};
		std::chrono::steady_clock::time_point m_LastTime;
	};
}