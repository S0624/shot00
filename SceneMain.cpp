#include "DxLib.h"
#include "SceneMain.h"
#include "player.h"
#include "ShotNormal.h"
//#include "ShotSinCurve.h"
//#include "ShotCurve.h"
#include "ShotBound.h"
#include<cassert>

namespace
{
	//�V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);

	//for (auto& pShot : m_pShot)
	//{
	//	pShot = nullptr;
	//}
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
	
	for (auto& pShot : m_pShotVt)
	{
		assert(pShot);				//�o�O����������킴�Ǝ~�߂鏈��
		//if (!pShot) continue;
		delete pShot;
		pShot = nullptr;
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();

	std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
	while (it != m_pShotVt.end())
	{
		auto& pShot = (*it);
		
		//if (!pShot)
		//{
		//	it++;
		//	continue;
		//}

		assert(pShot);				//�킴�Ǝ~�߂鏈��

		pShot->update();
		if (!pShot->isExsist())
		{
			delete pShot;
			pShot = nullptr;

			//vector�̗v�f�폜
			it = m_pShotVt.erase(it);		//�w�肵���ꏊ���폜����
			continue;					//�폜�����Ƃ����[�v�̐擪�ɖ߂�
		}
		it++;
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		pShot->draw();
	}

	//���ݑ��݂��Ă���ʂ̐���\��
	DrawFormatString(0, 0, GetColor(0, 255, 255), "�e�̐�:%d", m_pShotVt.size());
}

bool SceneMain::createShotNormal(Vec2 pos)
{
	ShotNormal * pShot = new ShotNormal;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);
	
	return true;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	ShotBound * pShot = new ShotBound;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);
	
	return true;
}