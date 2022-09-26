#include "Bullet.h"
#include "Effect.h"
Bullet::Bullet(const CVector2D& pos) :Base(eType_Bullet) {
	m_img.Load("Image/ƒr[ƒ€3.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(350, 50);
	m_img.SetCenter(330,25);
}

void Bullet::Update()
{
	const int move_speed = 9;
	m_pos.x += move_speed;
}

void Bullet::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Bullet::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Rock:
	case eType_Enemy:
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			
		}
		break;
	}
}
