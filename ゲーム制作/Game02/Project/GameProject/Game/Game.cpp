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
//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
//�^�C�g���V�[����
	Base::Add(new Title());
}
*/
void Game::Update() {
	/*
	//�S�[����������΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		
	}

*/
//�v���C���[���S �{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}


}
