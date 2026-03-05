#include "PlayerWidget.h"
#include <format>
#include <imgui/imgui.h>

void PlayerWidget::OnDraw()
{
	std::string playerText = std::format("Player: {}", (void*)target);
	ImGui::Text(playerText.c_str());



	std::string debugText = "Debug Mode" + std::to_string(target->DebugMode);
	ImGui::Checkbox("Debug Mode", &target->DebugMode);
	/*if (ImGui::Button("Reset")) {
		ball->Reset();
	}*/

	if (ImGui::Button("Shoot")) {
		target->ForceFire();
	}
	/*Vector2 vel = ball->GetVelocity();
	float v[2] = { vel.X, vel.Y };
	ImGui::InputFloat2("Velocity", v);

	ImGui::InputFloat("Speed: ", &ball->speed);
	ImGui::InputInt("Damage: ", &ball->Damage);*/
}
