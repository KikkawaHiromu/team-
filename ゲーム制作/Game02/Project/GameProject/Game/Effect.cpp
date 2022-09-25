#include "Effect.h"

//一つのアニメーション
static TexAnim _effect_bomb[] = {
	//パターン、速度
	{0,2},
	{1,2},
	{2,2},
	{3,2},
	{4,2},
};

//アニメーションの総合データ
TexAnimData effectAnimData[] = {
	ANIMDATA(_effect_bomb),
};

Effect::Effect(const CVector2D& pos) : Base(eType_Effect) {
	//画像の読み込み
	//アニメーションデータ付きで読み込み
	//　　　　　ファイル名　　アニメーションデータ　一枚の幅　高さ
	m_img.Load("Image/Effect_Bomb.png", effectAnimData, 96, 96);
	m_pos = pos;
	//アニメーション変更　　ループフラグ
	m_img.ChangeAnimation(0, false);
	m_img.SetCenter(96 / 2, 96 / 2);
}

void Effect::Update() {
	//アニメーション更新
	m_img.UpdateAnimation();
	//アニメーション終了チェック
	if (m_img.CheckAnimationEnd())
		m_kill = true;
}

void Effect::Draw() {
	//座標
	m_img.SetPos(m_pos);
	//画像の表示
	m_img.Draw();

}

