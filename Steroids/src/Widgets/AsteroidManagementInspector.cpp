#include "AsteroidManagementInspector.h"
#include "AsteroidManager.h"
#include "../Entities/Asteroid.h"
#include <imgui.h>
#include <format>

void AsteroidManagementInspector::OnDraw()
{
	std::vector<Asteroid*> asteroids = target->GetAsteroids();

	if (ImGui::Button("Request Asteroid")) {
		target->RequestAsteroid();
	}
	if (ImGui::Button("Create Asteroid")) {
		target->ForceCreate();
	}
	// TODO: Implement ImGuiListClipper when list becomes conistently large
	ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(5.0f, 5.0f));
	if (ImGui::BeginTable("AsteroidList", 2, ImGuiTableFlags_Borders)) {
		//ImGui::TableHeadersRow();

		ImGui::TableSetupColumn("AsteroidList_Indexer", ImGuiTableColumnFlags_WidthFixed, 10);
		ImGui::TableSetupColumn("AsteroidList_Tag", ImGuiTableColumnFlags_WidthStretch, 10);

		for (int row = 0; row < asteroids.size(); row++) {
			ImGui::PushID(row);
			Asteroid* asteroid = asteroids[row];

			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text(std::to_string(row).c_str());			

			ImGui::TableSetColumnIndex(1);
			
			if (ImGui::IsItemHovered()) {
				ImGui::BeginTooltip();
				ImGui::Text(std::format("{}", (void*)asteroid).c_str());
				ImGui::EndTooltip();			
			}
			if (ImGui::Selectable(asteroids[row]->tag.c_str())) {
				ImGui::OpenPopup("TextContextMenu");
			}

			// Create a context menu popup
			if (ImGui::BeginPopupContextItem("TextContextMenu"))
			{
				ImGui::Text(std::format("{}", (void*)asteroid).c_str());
				ImGui::Text(std::format("Velocity: {}", asteroid->velocity.ToString()).c_str());

				if (ImGui::MenuItem("Destroy"))
				{
					GameObject::Destroy(*asteroid);
				}
				ImGui::EndPopup();
			}
			ImGui::PopID();



			//ImGui::Text(std::format("Position: {}", asteroids[row]->position.ToString()).c_str());
		}

		ImGui::PopStyleVar(); // Restore previous style
		ImGui::EndTable();
	}
}
