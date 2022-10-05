#pragma once

#include "ShotBase.h"

class ShotCurve : public ShotBase
{
public:
	ShotCurve() {}
	virtual ~ShotCurve() {}

	//ショット開始
	virtual void start(Vec2 pos);

	// 更新
	virtual void update();


private:

};
