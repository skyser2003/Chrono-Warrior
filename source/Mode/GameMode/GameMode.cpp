#include "stdafx.h"
#include "GameMode.h"

#include "UIManager/UIManager.h"

#include "Window/Window.h"
#include "KeyboardInput/KeyboardInput.h"
#include "MouseInput/MouseInput.h"

#include "Logic/Map/Map.h"
#include "Logic/FieldObject/FieldUnit/FieldUnit.h"

namespace CW
{
	GameMode::GameMode()
	{
	}
	GameMode::~GameMode()
	{
	}

	void GameMode::Initialize(const std::shared_ptr<FG::Window>& window)
	{
		Mode::Initialize(window);

		mMap.reset(new Map);
		mMap->Initialize();
		currentTime = std::chrono::system_clock::now();
		mSelectedUnit = nullptr;

		InitializeGraphics();
	}
	void GameMode::Destroy()
	{
		Mode::Destroy();
	}

	bool GameMode::Run()
	{
		auto now = std::chrono::system_clock::now();
		auto duration = now - currentTime;
		currentTime = now;

		Update(duration);
		Draw(duration);

		return true;
	}

	void GameMode::Update(std::chrono::system_clock::duration dt)
	{
		// Keyboard input
		for (int keyCode : mKeyboard->GetDownKeys())
		{

		}

		// Mouse input
		WORD x = mMouse->GetX();
		WORD y = mMouse->GetY();
		FG::MouseInput::BUTTON_STATE lButton = mMouse->GetLButtonState();
		FG::MouseInput::BUTTON_STATE rButton = mMouse->GetRButtonState();
		float wheel = mMouse->GetWheelValue();

		if (lButton == FG::MouseInput::BUTTON_DOWN)
		{
			Position tilePos = GetTilePosition(x, y);
			auto tile = mMap->GetTile(tilePos);
			auto units = mMap->GetUnits(tilePos);
			if (tile != nullptr)
			{
				if (units.size() == 0)
				{
					mSelectedUnit = nullptr;

					std::shared_ptr<FieldUnit> unit(new FieldUnit);
					unit->SetUnitType(FieldUnit::FU_CHRONO_MAGE);
					unit->SetTile(tile);
					mMap->AddUnit(unit);
				}
				else
				{
					mSelectedUnit = units[0];
				}
			}
		}

		// Map update
		mMap->ForeachTile([](Tile* tile)
		{
			
		});
		mMap->ForeachUnit([](FieldUnit* unit)
		{
			
		});
	}
}