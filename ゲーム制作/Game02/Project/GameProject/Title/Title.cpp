#include "Title.h"
#include "../Game/Game.h"

Title::Title() : Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 100)
{
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�Q�[���V�[����
	Base::Add(new Game());
}

void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	//�����\��
	m_title_text.Draw(400, 256, 255, 255, 0, "GAMESTART");
	m_title_text.Draw(470, 512, 255, 255, 0, "Push Z");

}