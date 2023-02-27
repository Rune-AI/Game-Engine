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
