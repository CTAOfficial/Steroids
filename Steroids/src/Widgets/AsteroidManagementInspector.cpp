#include "AsteroidManagementInspector.h"
#include "AsteroidManager.h"
#include "../Entities/Asteroid.h"
#include <imgui.h>
#include <format>
#include <Entities/GameObject.h>

void AsteroidManagementInspector::OnDraw()
{
	std::vector<Asteroid*> asteroids = target->GetAsteroids();

	// Limiter
	ImGui::Text("Limit:");	
	ImGui::SameLine();
	ImGui::InputInt("##", &target->Limit);
	ImGui::Checkbox("Use Limit", &target->UseLimit);
	ImGui::NewLine();

	// Buttons
	if (ImGui::Button("Request Asteroid")) {
		target->RequestAsteroid();
	}
	ImGui::SameLine();
	if (ImGui::Button("Create Asteroid")) {
		target->ForceCreate();
	}

	// TODO: Implement ImGuiListClipper when list becomes conistently large
	// Table
	ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(5.0f, 5.0f));
	if (ImGui::BeginTable("AsteroidList", 2, ImGuiTableFlags_Borders)) {
		//ImGui::TableHeadersRow();

		ImGui::TableSetupColumn("AsteroidList_Indexer", ImGuiTableColumnFlags_WidthFixed, 10);
		ImGui::TableSetupColumn("AsteroidList_Tag", ImGuiTableColumnFlags_WidthStretch, 10);

		for (int row = 0; row < asteroids.size(); row++) {
			ImGui::PushID(row);
			Asteroid* asteroid = asteroids[row];

			// Asteroid Indexer
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text(std::to_string(row).c_str());
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(std::format("{}", (void*)asteroid).c_str());
				ImGui::EndTooltip();
			}

			ImGui::TableSetColumnIndex(1);			
			
			// Asteroid Tag
			if (ImGui::CollapsingHeader(asteroid->tag.c_str())) {
				ImGui::Text(std::format("Address: {}", (void*)asteroid).c_str());
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The address of the object in memory.");
					ImGui::EndTooltip();
				}
				ImGui::Checkbox("Debug Mode", &asteroid->DebugMode);
				ImGui::NewLine();

				ImGui::Text(std::format("Size: {}", std::to_string(asteroid->size)).c_str());
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The Size of the object. \n 0 - Small\n 1 - Medium\n 2 - Large");
					ImGui::EndTooltip();
				}
				ImGui::Text(std::format("Position: {}", asteroid->position.ToString()).c_str());
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The position of the object.");
					ImGui::EndTooltip();
				}
				ImGui::Text(std::format("Velocity: {}", asteroid->velocity.ToString()).c_str());
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text("The velocity of the object.");
					ImGui::EndTooltip();
				}
			}
			if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Right)) {
				ImGui::OpenPopup("AsteroidContextMenu");
			}


			if (ImGui::BeginPopupContextItem("AsteroidContextMenu"))
			{
				if (ImGui::MenuItem("Destroy"))
				{
					target->RemoveAsteroid(asteroid);
					GameObject::Destroy(*asteroid);
				}
				ImGui::EndPopup();
			}
			
			ImGui::PopID();
		}

		
		ImGui::EndTable();
	}
	ImGui::PopStyleVar(); // Restore previous style
}
