#pragma once

#include "Button.h"

class SwishyButton : public Button
{
public:
	SwishyButton(void);
	SwishyButton(
		float p_x, float p_y,
		float p_width, float p_height,
		char* p_name, char* p_fontPath,
		int p_swishDir);
	~SwishyButton(void);

	void Update(float f_dt);

	void SwishOn();
	void SwishOff();
private:
	float originX, originY;
	float targetX, targetY;
	int swishDir;
	int originSwishDir;
	bool swishing;
};
