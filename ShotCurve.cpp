#include"game.h"
#include "ShotCurve.h"
#include "DxLib.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
}

void ShotCurve::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = +kShotSpeed;
	m_vec.y = 0.0f;
}

void ShotCurve::update()
{
	if (!m_isExist)return;
	m_pos += m_vec;

	if (m_pos.y > 70)
	{
		m_vec.y = -3.5f;
	}
	m_vec.y += 0.5f;
	
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
