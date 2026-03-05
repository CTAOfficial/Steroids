#pragma once
#include "../Widget.h"

template <typename T>
class Inspector : public Widget {
protected:
	T target;

public:
	Inspector(T target) : Widget() {
		this->target = target;
	}
	Inspector(T target, std::string title) : Widget(title) {
		this->target = target;
	}
};