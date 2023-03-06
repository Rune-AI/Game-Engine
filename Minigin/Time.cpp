#include "Time.h"
#include <chrono>

void dae::Time::CalculateDeltaTime()
{
	const auto currentTime = std::chrono::high_resolution_clock::now();
	m_DeltaTime = std::chrono::duration<float>(currentTime - m_LastTime).count();
	m_LastTime = currentTime;
}

float dae::Time::GetDeltaTime()
{
	return m_DeltaTime;
}

float dae::Time::GetFixedTimeStep()
{
	return m_FixedTimeStep;
}

int dae::Time::GetSleepTime()
{
	// todo : implement more accurate fps timer
	return int(1 / m_DesiredFPS * 1000);
	//return m_LastTime + m_DesiredFPS - std::chrono::high_resolution_clock::now();
}
