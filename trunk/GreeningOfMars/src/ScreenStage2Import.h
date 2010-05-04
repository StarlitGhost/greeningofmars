#pragma once

#include "Screen.h"

#include "Camera.h"
#include "Mars.h"

class ScreenStage2Import : public Screen
{
public:
	ScreenStage2Import(void);
	~ScreenStage2Import(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	Camera *camera;
	Mars *mars;
};