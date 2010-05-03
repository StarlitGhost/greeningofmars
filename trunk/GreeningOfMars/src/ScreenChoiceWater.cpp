#include "ScreenChoiceWater.h"

#include "Screens.h"
#include "MouseHandler.h"

ScreenChoiceWater::ScreenChoiceWater(void)
{
}

ScreenChoiceWater::~ScreenChoiceWater(void)
{
}

void ScreenChoiceWater::Update(float f_dt)
{
	ScreenChoice::Update(f_dt);

	if (MouseHandler::Pressed(0))
	{
		int mouseX = 0;
		int mouseY = 0;
		MouseHandler::GetPosition(mouseX, mouseY);

		if (buttonGo->CheckClicked(mouseX, mouseY))
		{
			if (labelChoiceTitle->Name() == buttonChoice1->Name())
			{
				ScreenManager::GetInstance()->ChangeScreen(new ScreenStage2Import());
			}
			else
			{
				labelChoiceTitle->Name("Please choose a method.");
			}
		}
	}
}

void ScreenChoiceWater::Draw()
{
	ScreenChoice::Draw();
}

void ScreenChoiceWater::Load()
{
	ScreenChoice::Load();

	labelTitle->Name("Water");
	buttonChoice1->Name("Import");
	buttonChoice2->Name("");
	buttonChoice3->Name("");
	buttonChoice4->Name("");
}

void ScreenChoiceWater::Unload()
{
	ScreenChoice::Unload();
}
