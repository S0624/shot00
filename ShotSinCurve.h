#pragma once

#include "ShotBase.h"

class ShotSinCurve : public ShotBase
{
public:
	ShotSinCurve();
	virtual ~ShotSinCurve() {}

	//�V���b�g�J�n
	virtual void start(Vec2 pos);

	// �X�V
	virtual void update();


private:
	Vec2 m_basePos;
	float m_sinRate;
};
