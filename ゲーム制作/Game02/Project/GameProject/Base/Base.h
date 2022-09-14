#pragma once
#include <GLLibrary.h>

enum {
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Effect,
	eType_UI,
};

class Base {
public:
	int m_type;
	CVector2D m_pos;
	float m_rad;
	bool m_kill;
	
	Base* Base::FindObject(int type);
	

public:
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }

	static std::list<Base*> m_list;
	static void UpdateAll();
	static void DrawAll();
	static void CollisionAll();
	static void CheckKillAll();
	static void Add(Base* b);
	static bool CollisionCircle(Base* b1, Base* b2);
	static std::list<Base*> FindObjects(int type);
};
