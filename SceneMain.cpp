#include "DxLib.h"
#include "SceneMain.h"
#include "player.h"
#include "ShotNormal.h"
//#include "ShotSinCurve.h"
//#include "ShotCurve.h"
#include "ShotBound.h"
namespace
{
	//ショットの発射間隔
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

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);


	for (auto& pShot : m_pShot)
	{
		pShot = nullptr;
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
	
	for (auto& pShot : m_pShot)
	{
		if (!pShot) continue;
		delete pShot;
		pShot = nullptr;
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	for (auto& pShot : m_pShot)
	{
		if (!pShot) continue;
		pShot->update();
		if (!pShot->isExsist())
		{
			delete pShot;
			pShot = nullptr;
		}
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();

	for (auto& pShot : m_pShot)
	{
		if (!pShot) continue;
		pShot->draw();
	}

	//現在存在している玉の数を表示
	int shotNum = 0;
	for (auto& pShot : m_pShot)
	{
		if (!pShot) continue;
		if (pShot->isExsist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(0, 255, 255), "弾の数:%d", shotNum);
}

bool SceneMain::createShotNormal(Vec2 pos)
{
	for (auto& pShot : m_pShot)
	{
		if (pShot) continue;

		pShot = new ShotNormal;
		pShot->setHandle(m_hShotGraphic);
		pShot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	for (auto& pShot : m_pShot)
	{
		if (pShot) continue;

		pShot = new ShotBound;
		pShot->setHandle(m_hShotGraphic);
		pShot->start(pos);
		return true;
	}
	return false;

}