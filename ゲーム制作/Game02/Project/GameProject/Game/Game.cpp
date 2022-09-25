#include "Game.h"
//#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "../Title/Title.h"
#include "Rock.h"

Game::Game() :Base(eType_Scene) {
	
	Base::Add(new Player(CVector2D(200, 500)));
	Base::Add(new Enemy(CVector2D(1000, 400)));
	Base::Add(new Rock(CVector2D(1000, 200)));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 3, 540)));
	
}/*
Game::~Game() {
//全てのオブジェクトを破棄
	Base::KillAll();
//タイトルシーンへ
	Base::Add(new Title());
}
*/
void Game::Update() {
	/*
	//ゴールが無ければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {
		
	}

*/
//プレイヤー死亡 ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}


}
