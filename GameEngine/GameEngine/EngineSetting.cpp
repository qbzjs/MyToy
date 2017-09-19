#include"EngineSetting.h"
#include"Config.h"

bool CEngineSetting::DrawGrid;
float CEngineSetting::GridStrength;
bool CEngineSetting::DrawGizmos;

void CEngineSetting::Init()
{
	DrawGrid = _Config->GetValue<bool>("debug", "draw_grid");
	GridStrength = _Config->GetValue<float>("debug", "grid_strength");
	DrawGizmos = _Config->GetValue<bool>("debug", "draw_gizmos");
}