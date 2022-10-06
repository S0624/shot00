#pragma once

#include<vector>
#include"ShotBase.h"
#include "player.h"


class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	
	//�e�̐���
	bool createShotNormal (Vec2 pos);
	bool createShotBound (Vec2 pos);

//private:
//	// �V���b�g�̍ő吔
//	static constexpr int kShotMax = 64;


private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �V���b�g
	std::vector< ShotBase*> m_pShotVt;
	//ShotBase* m_pShot[kShotMax];


	//ShotNormal* m_pShotNormal[kShotMax];
	//ShotBound* m_pShotBound[kShotMax];

	//ShotSinCurve m_shot[kShotMax];
	//ShotCurve m_shot[kShotMax];
};