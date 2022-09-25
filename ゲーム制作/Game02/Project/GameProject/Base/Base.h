#pragma once
#include<GLLibrary.h>
enum {
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

public:
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }

	static void UpdateAll();
	static void DrawAll();
	static void Add(Base* b);
	static void CollisionAll();
	static bool CollisionCircle(Base* b1, Base* b2);
	static void CheckKillAll();
	Base* Base::FindObject(int Type);
	static std::list<Base*>FindObjects(int type);
};