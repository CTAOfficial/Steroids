#pragma once
#include "Widget.h"

class EntityManagementObserver : public Widget {
protected:
	void OnDraw() override;

public:
	EntityManagementObserver() : Widget("Entity Manager") {

	}
};