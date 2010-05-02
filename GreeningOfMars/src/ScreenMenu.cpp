#include "ScreenMenu.h"

#include <vector>
#include <stdlib.h>

#include <GL/freeglut.h>

#include "Screens.h"
#include "Settings.h"
#include "HUD.h"
#include "MouseHandler.h"
#include "SwishyButton.h"
#include "Mars.h"

ScreenMenu::ScreenMenu(void)
{
}

ScreenMenu::~ScreenMenu(void)
{
}

void ScreenMenu::Update(float f_dt)
{
	for (std::vector<Button*>::iterator i = buttons->begin(); i != buttons->end(); ++i)
	{
		(*i)->Update(f_dt);
	}

	if (!transitioning)
	{
		if (MouseHandler::Pressed(0))
		{
			int mouseX = 0;
			int mouseY = 0;
			MouseHandler::GetPosition(mouseX, mouseY);
			if (buttonStart->CheckClicked(mouseX, mouseY))
			{
				transitioning = true;
				buttonStart->SwishOff();
				buttonQuit->SwishOff();
			}
			else if (buttonQuit->CheckClicked(mouseX, mouseY))
			{
				Settings::Save(".\\settings.ini");
				exit(0);
			}
		}
	}
	else
	{
		if (camera->Position().Z() < 10.0f)
		{
			camera->Position(
				Vector3f(0.0f, 0.0f, 10.0f));

			ScreenManager* screenManager = ScreenManager::GetInstance();
			screenManager->ChangeScreen(new ScreenChoice());
		}
		else
		{
			if (camera->Position().Z() < 100.0f)
			{
				if (moveSpeed > 5.0f)
				{
					moveSpeed -= 15.0f * f_dt;
				}
			}
			camera->MoveForwards(moveSpeed * f_dt);
		}
	}
}

void ScreenMenu::Draw()
{
	camera->Display();

	mars->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);

	labelThe->Draw();
	labelGreening->Draw();
	labelOf->Draw();
	labelMars->Draw();

	for (std::vector<Button*>::iterator i = buttons->begin(); i != buttons->end(); ++i)
	{
		(*i)->Draw();
	}

	HUD::End();
}

void ScreenMenu::Load()
{
	mars = new Mars();

	camera = new Camera(
		Vector3f(0.0f, 0.0f, 200.0f),
		0.0f, 0.0f);

	transitioning = false;
	moveSpeed = 50.0f;

	float titleSpacing = Settings::View::Height / 25.0f;

	ColourA red = ColourA(1.0f, 0.0f, 0.0f, 1.0f);
	ColourA green = ColourA(0.0f, 1.0f, 0.0f, 1.0f);

	labelThe = new Label(
		Vector2f(Settings::View::Width * 0.5f, titleSpacing),
		"The", Settings::UI::FontPath,
		Settings::UI::LabelColour,
		true);
	labelGreening = new Label(
		Vector2f(Settings::View::Width * 0.5f, 2 * titleSpacing),
		"Greening", Settings::UI::FontPath,
		green,
		true);
	labelOf = new Label(
		Vector2f(Settings::View::Width * 0.5f, 3 * titleSpacing),
		"Of", Settings::UI::FontPath,
		Settings::UI::LabelColour,
		true);
	labelMars = new Label(
		Vector2f(Settings::View::Width * 0.5f, 4 * titleSpacing),
		"Mars", Settings::UI::FontPath,
		red,
		true);

	buttons = new std::vector<Button*>();

	buttonStart = new SwishyButton(
		Vector2f(-20.0f, (float)(Settings::View::Height / 2) - 45.0f),
		Vector2f(110.0f, 40.0f),
		"Start", Settings::UI::FontPath,
		Settings::UI::ButtonColour,
		0);
	buttonStart->SwishOn();
	buttons->push_back(buttonStart);

	buttonQuit = new SwishyButton(
		Vector2f(-20.0f, (float)(Settings::View::Height / 2) + 5.0f),
		Vector2f(100.0f, 40.0f),
		"Quit", Settings::UI::FontPath,
		Settings::UI::ButtonColour,
		0);
	buttonQuit->SwishOn();
	buttons->push_back(buttonQuit);
}

void ScreenMenu::Unload()
{
	delete mars;
	delete camera;

	delete labelThe;
	delete labelGreening;
	delete labelOf;
	delete labelMars;
	delete buttonStart;
	delete buttonQuit;
	delete buttons;
}