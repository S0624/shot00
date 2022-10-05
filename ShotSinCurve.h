#pragma once

#include "ShotBase.h"

class ShotSinCurve : public ShotBase
{
public:
	ShotSinCurve();
	virtual ~ShotSinCurve() {}

	//ショット開始
	virtual void start(Vec2 pos);

	// 更新
	virtual void update();


private:
	Vec2 m_basePos;
	float m_sinRate;
};
