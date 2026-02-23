#include "EntityManagementObserver.h"
#include "EntityManager.h"
#include <imgui.h>

void EntityManagementObserver::OnDraw()
{


	if (ImGui::BeginTable("table1", 3)) {
		for (int row = 0; row < 4; row++) {
			ImGui::TableNextRow();
			for (int column = 0; column < 3; column++) {
				ImGui::TableSetColumnIndex(column);
				ImGui::Text("Row %d Column %d", row, column);
			}
		}
		ImGui::EndTable();
	}
}
