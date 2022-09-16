#include "Enemy.h"

Enemy::Enemy(const CVector2D& pos) :Base(eType_Enemy)
{
	m_img.Load("Image/Enemy.png");
	m_pos = pos;
	m_rad = 25;
	m_img.SetSize(50, 50);
	m_img.SetCenter(25, 25);
}

void Enemy::Update()
{
	const int move_speed = 2;
	m_pos.x -= move_speed;
	if (m_pos.x < 0 - 25) {
		m_kill = true;
	}
	Base* b = Base::FindObject(eType_Player);
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
	}
}

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}
void Enemy::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Rock:
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
		}
		break;
	}
}