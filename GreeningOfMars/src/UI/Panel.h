#pragma once

#include "UIObject.h"

#include "../Maths/Vector2f.h"

class Panel : public UIObject
{
public:
	Panel();
	Panel(Vector2f p_position, Vector2f p_size,
		float p_cornerInset,
		ColourA p_colour);
	~Panel(void);

	virtual void Update(float f_dt);
	void Draw(void);

protected:
	Vector2f size;
	float cornerInset;
};
