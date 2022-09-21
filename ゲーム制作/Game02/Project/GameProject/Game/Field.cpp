#include "Field.h"

Field::Field() :Base(eType_Field) {
	m_space = COPY_RESOURCE("space", CImage);

}
void Field::Draw() {

	m_space.Draw();
}