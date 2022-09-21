#include "Bullet.h"

Bullet::Bullet(const CVector2D& pos) :Base(eType_Bullet) {
	m_img.Load("Image/ƒr[ƒ€3.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(500, 50);
	m_img.SetCenter(16, 16);
}

void Bullet::Update()
{
	const int move_speed = 5;
	m_pos.x += move_speed;
}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Bullet::COllsion(Base* b)
{
	switch (b->m_type) {
	case eType_Enemy:
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			
		}
		break;
	}
}
