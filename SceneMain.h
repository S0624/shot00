#pragma once

#include "player.h"
#include "ShotNormal.h"
//#include "ShotSinCurve.h"
//#include "ShotCurve.h"
#include "ShotBound.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();
	
	//弾の生成
	bool createShotNormal (Vec2 pos);
	bool createShotBound (Vec2 pos);

private:
	// ショットの最大数
	static constexpr int kShotMax = 64;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// プレイヤー
	Player m_player;
	// ショット
	//ShotBase m_pShot[kShotMax];


	ShotNormal* m_pShotNormal[kShotMax];
	ShotBound* m_pShotBound[kShotMax];

	//ShotSinCurve m_shot[kShotMax];
	//ShotCurve m_shot[kShotMax];
};