#pragma once

#include "Mode/Mode/Mode.h"
#include "Logic/Position/Position.h"

namespace CW
{
	class Map;
	class Tile;
	class FieldUnit;

	class GameMode : public Mode
	{
	public:
		GameMode();
		virtual ~GameMode();

		virtual void Initialize(const std::shared_ptr<FG::Window>& window) override;
		virtual void Destroy() override;

		virtual bool Run() override;
	private:
		// Logic
		virtual void Update(std::chrono::system_clock::duration dt) override;

		// Graphics
		virtual void Draw(std::chrono::system_clock::duration dt) override;

		void InitializeGraphics();

		void DrawTile(Tile* tile);
		void DrawUnit(FieldUnit* unit);

		int GetTileX(WORD screenX) const;
		int GetTileY(WORD screenY) const;
		Position GetTilePosition(WORD screenX, WORD screenY) const;

		// Logic variables
		std::chrono::system_clock::time_point currentTime;
		std::shared_ptr<Map> mMap;
		std::shared_ptr<FieldUnit> mSelectedUnit;

		// Canvas
		const int mTileWidth = 50;
		const int mTileHeight = 50;
		int mLeftMargin = 50;
		int mBottomMargin = 50;
	};
}