#pragma once
#include<GLLibrary.h>
enum {
	eType_Field,
	eType_UI,
	eType_Player,
	eType_Enemy,
	eType_Rock,
	eType_Bullet,
	eType_Player_Bullet,
	eType_Enemy_Bullet, 
	eType_Effect,
	eType_Scene,
};

class Base {
public:
	int m_type;
	CVector2D m_pos;
	CVector2D m_vec;
	float m_rad;
	float m_ang;
	static std::list<Base*> m_list;
	bool m_kill;
	static CVector2D m_scroll;
	//��`
	CRect	m_rect;
public:
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }
	static void KillAll();
	static void UpdateAll();
	static void DrawAll();
	static void Add(Base* b);
	static void CollisionAll();
	static bool CollisionCircle(Base* b1, Base* b2);
	static void CheckKillAll();
	static CVector2D GetScreenPos(const CVector2D& pos);
	Base* Base::FindObject(int Type);
	static std::list<Base*>FindObjects(int type);
	/// ��`�̕\��
	void DrawRect();
};