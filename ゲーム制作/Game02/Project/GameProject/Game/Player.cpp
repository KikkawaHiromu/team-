#include "Player.h"
#include "Bullet.h"

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Pl1.png");
	m_pos = pos;
	m_img.SetSize(130, 150);
	m_img.SetCenter(55, 55);
}

void Player::Update() {
	const float speed = 10;
	//è„
	if (HOLD(CInput::eButton1)) {
		m_pos.y -= speed;
	}
	//â∫
	if (HOLD(CInput::eButton2)) {
		m_pos.y += speed;
	}
	//âE
	if (HOLD(CInput::eButton3)) {
		m_pos.x += speed;
	}
	//ç∂
	if (HOLD(CInput::eButton4)) {
		m_pos.x -= speed;
	}
	
	if (HOLD(CInput::eMouseL)) {
		Base::Add(new Bullet(m_pos));
	}
	m_scroll.x = m_pos.x - 1280 / 2;
}

void Player::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}