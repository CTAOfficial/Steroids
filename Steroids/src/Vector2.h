#pragma once

#include <string>

struct Vector2 {
public:
	Vector2(){}
	Vector2(float x) {
		X = x;
	}
	Vector2(float x, float y) {
		X = x;
		Y = y;
	}

	float X = 0;
	float Y = 0;

	std::string ToString() const {
		std::string string;
		string += "(";
		string += std::to_string(X);
		string += ", ";
		string += std::to_string(Y);
		string += ")";
		return string;
	}
};