#pragma once
#include <GLLibrary.h>
#include "../Base//Base.h"

class Player : public Base {
private:
	CImage m_img;
	bool m_flip;
public:
	CVector2D m_pos;
public:
	Player(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	
};