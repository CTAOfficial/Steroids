#pragma once

#include <string>

struct Vector2 {
public:
	static Vector2 Zero;
	static Vector2 One;

	Vector2() {}
	Vector2(float x) : Vector2() {
		X = x;
	}
	Vector2(float x, float y) : Vector2() {
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