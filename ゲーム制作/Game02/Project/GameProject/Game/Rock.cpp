#include "Rock.h"

Rock::Rock(const CVector2D& pos) :Base(eType_Rock)
{
	m_img.Load("Image/Rock.png");
	m_pos = pos;
	m_rad = 25;
	m_img.SetSize(50, 50);
	m_img.SetCenter(25, 25);
}

void Rock::Update()
{
	const int move_speed = 1;
	m_pos.x -= move_speed;
	m_ang -=0.008;
	if (m_pos.x < 0 - 25) {
		m_kill = true;
	}
}

void Rock::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetAng(m_ang);
	m_img.Draw();
}
void Rock::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Rock:
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
		}
		break;
	}
}