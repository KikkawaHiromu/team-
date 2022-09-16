#pragma once
#include"../Base/Base.h"
class Rock :public Base {
public:
	CImage m_img;
	int m_cnt;

public:
	Rock(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};