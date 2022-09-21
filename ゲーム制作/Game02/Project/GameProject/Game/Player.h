#pragma once
#include <GLLibrary.h>
#include "../Base//Base.h"

class Player : public Base {
private:
	CImage m_img;
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	
};