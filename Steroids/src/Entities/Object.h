#pragma once
#include <string>

class Object {
private:
	int ID = 0;

protected:
	Object(){}

public:
	std::string name = "New Object";

	virtual ~Object() {
		
	}

	int GetID() const {
		return ID;
	}
};