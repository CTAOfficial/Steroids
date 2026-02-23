#include "Widget.h"
#include "imgui/imgui.h"

Widget::Widget(std::string title)
{
	Title = title;
}

void Widget::Draw()
{
	ImGui::Begin(Title.c_str());
	OnDraw();
	ImGui::End();
}
