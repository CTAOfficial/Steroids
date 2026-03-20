#include "PlayerWidget.h"
#include "Utilities/Timer.h"
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

	Vector2 vel = target->velocity;
	float v[2] = { vel.X, vel.Y };
	ImGui::InputFloat2("Velocity", v);
	ImGui::InputFloat("Speed: ", &target->speed);

	ImGui::Text("Shooting");
	ImGui::Text(std::format("Can Shoot : {}", target->CanFire()).c_str());
	ImGui::DragFloat("Timer", &target->timer->Time);

	std::vector projectiles = target->bullets;
	// TODO: Implement ImGuiListClipper when list becomes conistently large
	// Table
	ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(5.0f, 5.0f));
	if (ImGui::BeginTable("ProjectileList", 2, ImGuiTableFlags_Borders)) {
		//ImGui::TableHeadersRow();

		ImGui::TableSetupColumn("ProjectileList_Indexer", ImGuiTableColumnFlags_WidthFixed, 10);
		ImGui::TableSetupColumn("ProjectileList_Name", ImGuiTableColumnFlags_WidthStretch, 10);

		for (int row = 0; row < projectiles.size(); row++) {
			ImGui::PushID(row);
			Projectile* projectile = projectiles[row];

			// Projectile Indexer
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text(std::to_string(row).c_str());
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(std::format("{}", (void*)projectile).c_str());
				ImGui::EndTooltip();
			}

			ImGui::TableSetColumnIndex(1);

			// Projectile Tag
			if (ImGui::CollapsingHeader(projectile->name.c_str())) {
				ImGui::Text(std::format("Address: {}", (void*)projectile).c_str());
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The address of the object in memory.");
					ImGui::EndTooltip();
				}
				ImGui::Checkbox("Projectile Debug Mode", &projectile->DebugMode);
				ImGui::NewLine();

				// Position
				ImGui::Text("Position: ");
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The position of the object.");
					ImGui::EndTooltip();
				}
				ImGui::SameLine();
				float* positions[2] = { &projectile->position.X, &projectile->position.Y };
				ImGui::InputFloat2("##ProjectilePosition", *positions);

				// Velocity
				ImGui::Text("Velocity: ");
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The velocity of the object.");
					ImGui::EndTooltip();
				}
				ImGui::SameLine();
				float* velocities[2] = { &projectile->velocity.X, &projectile->velocity.Y };
				ImGui::InputFloat2("##ProjectileVelocity", *velocities);

				// Speed
				ImGui::Text("Speed: ");
				ImGui::InputFloat("##ProjectileSpeed", &projectile->speed);
			}
			if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Right)) {
				ImGui::OpenPopup("ProjectileContextMenu");
			}


			if (ImGui::BeginPopupContextItem("ProjectileContextMenu"))
			{
				if (ImGui::MenuItem("DestroyProjectile"))
				{
					GameObject::Destroy(*projectile);
				}
				ImGui::EndPopup();
			}

			ImGui::PopID();
		}


		ImGui::EndTable();
	}
	ImGui::PopStyleVar(); // Restore previous style
}
