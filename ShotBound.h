#pragma once
#include "ShotBase.h"


class ShotBound : public ShotBase
{
public:
	ShotBound();
	virtual ~ShotBound(){}

	//�V���b�g�J�n
	void start(Vec2 pos);

	// �X�V
	virtual void update();


private:
	int m_boundCount;
};