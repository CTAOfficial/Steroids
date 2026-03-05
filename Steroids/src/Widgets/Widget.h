#pragma once
#include <string>

class Widget {

protected:
	std::string Title;
	virtual void OnDraw(){}

public:
	Widget();
	Widget(std::string title) : Widget() {
		Title = title;
	}
	~Widget();

	bool Visible = true;

	void Draw();
	void SetTitle(std::string title) {
		Title = title;
	}
	void Toggle() {
		Visible = !Visible;
	}
	
};