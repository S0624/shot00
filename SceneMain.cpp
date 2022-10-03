#include "DxLib.h"
#include "SceneMain.h"

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


	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_shot)
	{
		shot.update();
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}

	//現在存在している玉の数を表示
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExsist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(0, 255, 255), "弾の数%d", shotNum);
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_shot)
	{
		if (shot.isExsist()) continue;

		shot.start(pos);
		return true;
	}
	return false;
}