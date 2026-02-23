#pragma once
#include <string>

class Widget {

protected:
	std::string Title;
	virtual void OnDraw(){}

public:
	Widget(std::string title);
	~Widget() = default;

	void Draw();
};