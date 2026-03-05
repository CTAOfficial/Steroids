#pragma once
#include <queue>
#include <vector>
#include <stack>

class Widget;

class WidgetManager {
private:
	static std::vector<Widget*> Widgets;
	static std::queue<Widget*> AddQueue;
	static std::stack<Widget*> RemoveQueue;
	static void Remove(Widget* widget);

public:
	static void Add(Widget* widget);
	static void AddToRemove(Widget* entity);
	static void PreUpdate();
	static void Update();
};