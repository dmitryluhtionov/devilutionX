/**
 * @file debug.h
 *
 * Interface of debug functions.
 */
#pragma once

#include <cstdint>
#include <string_view>
#include <unordered_map>

#include "diablo.h"
#include "engine.h"
#include "engine/clx_sprite.hpp"

namespace devilution {

extern std::string TestMapPath;
extern OptionalOwnedClxSpriteList pSquareCel;
extern bool DebugToggle;
extern bool DebugGodMode;
extern bool DebugVision;
extern bool DebugPath;
extern bool DebugGrid;
extern std::unordered_map<int, Point> DebugCoordsMap;
extern bool DebugScrollViewEnabled;
extern std::string debugTRN;
extern uint32_t glMid1Seed[NUMLEVELS];
extern uint32_t glMid2Seed[NUMLEVELS];
extern uint32_t glMid3Seed[NUMLEVELS];
extern uint32_t glEndSeed[NUMLEVELS];

enum class DebugGridTextItem : uint16_t {
	None,
	dPiece,
	dTransVal,
	dLight,
	dPreLight,
	dFlags,
	dPlayer,
	dMonster,
	dCorpse,
	dObject,
	dItem,
	dSpecial,

	coords,
	cursorcoords,
	objectindex,

	// take dPiece as index
	Solid,
	Transparent,
	Trap,

	// megatiles
	AutomapView,
	dungeon,
	pdungeon,
	Protected,
};

void FreeDebugGFX();
void LoadDebugGFX();
void GetDebugMonster();
void NextDebugMonster();
void SetDebugLevelSeedInfos(uint32_t mid1Seed, uint32_t mid2Seed, uint32_t mid3Seed, uint32_t endSeed);
bool IsDebugGridTextNeeded();
bool IsDebugGridInMegatiles();
DebugGridTextItem GetDebugGridTextType();
void SetDebugGridTextType(DebugGridTextItem value);
bool GetDebugGridText(Point dungeonCoords, char *debugGridTextBuffer);
bool IsDebugAutomapHighlightNeeded();
bool ShouldHighlightDebugAutomapTile(Point position);
void AddDebugAutomapMonsterHighlight(std::string_view name);
void AddDebugAutomapItemHighlight(std::string_view name);
void AddDebugAutomapObjectHighlight(std::string_view name);
void ClearDebugAutomapHighlights();

} // namespace devilution
