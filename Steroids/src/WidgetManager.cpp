#include "WidgetManager.h"
#include "Widgets/Widget.h"

std::vector<Widget*> WidgetManager::Widgets;
std::queue<Widget*> WidgetManager::AddQueue;
std::stack<Widget*> WidgetManager::RemoveQueue;


void WidgetManager::Add(Widget* widget)
{
	AddQueue.push(widget);
}

void WidgetManager::AddToRemove(Widget* entity)
{
	RemoveQueue.push(entity);
}

void WidgetManager::PreUpdate() {
	while (!RemoveQueue.empty()) {
		Widget* widget = RemoveQueue.top();
		Remove(widget);
		RemoveQueue.pop();
	}
	while (!AddQueue.empty()) {
		Widget* widget = AddQueue.front();
		Widgets.push_back(widget);
		AddQueue.pop();
	}
}
void WidgetManager::Update()
{
	for (auto& widget : Widgets) {
		widget->Draw();
	}
}

void WidgetManager::Remove(Widget* widget)
{
	RemoveQueue.push(widget);
}
