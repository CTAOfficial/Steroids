#include "Widget.h"
#include "WidgetManager.h"
#include "imgui/imgui.h"

Widget::Widget()
{
	WidgetManager::Add(this);
}

Widget::~Widget()
{
	WidgetManager::AddToRemove(this);
}

void Widget::Draw()
{
	if (!Visible) { return; }

	ImGui::Begin(Title.c_str());
	OnDraw();
	ImGui::End();
}
