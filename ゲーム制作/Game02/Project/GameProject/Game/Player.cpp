#include "Player.h"
#include "Bullet.h"

Player::Player(const CVector2D& pos, bool flip) : Base(eType_Player) {
	m_img.Load("Image/Player.png");
	m_pos = pos;
	m_img.SetSize(50, 50);
	m_img.SetCenter(25, 25);
	m_flip = flip;
}

void Player::Update() {
	const float speed = 10;
	//è„
	if (HOLD(CInput::eUp)) {
		m_pos.y -= speed;
	}
	//â∫
	if (HOLD(CInput::eDown)) {
		m_pos.y += speed;
	}
	//âE
	if (HOLD(CInput::eRight)) {
		m_pos.x += speed;
	}
	//ç∂
	if (HOLD(CInput::eLeft)) {
		m_pos.x -= speed;
	}
	/*
	if (PUSH(CInput::eButton1)) {
		Base::Add(new Bullet(m_pos));
	}
	*/
}

void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}