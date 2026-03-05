#pragma once

#include <string>
#include <cmath>

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

	float Magitude() {
		return sqrtf(X * X + Y * Y);
	}
	Vector2 Normalized() {
		float mag = Magitude();

		Vector2 vec(X, Y);

		if (mag > 0) {
			vec.X /= mag;
			vec.Y /= mag;
		}

		return vec;
	}
	void Normalize() {
		Vector2 normalized = Normalized();

		X = normalized.X;
		Y = normalized.Y;
	}


	std::string ToString() const {
		return std::string("(" + std::to_string(X) + ", " + std::to_string(Y) + ")");
	}

	Vector2 operator+ (const Vector2& obj) {
		return { X += obj.X, Y += obj.Y };
	}
	Vector2& operator+= (const Vector2& obj) {
		X += obj.X;
		Y += obj.Y;
		return *this;
	}
	Vector2 operator- (const Vector2& obj) {
		return { X -= obj.X, Y -= obj.Y };
	}
	Vector2& operator-= (const Vector2& obj) {
		X - obj.X;
		Y - obj.Y;
		return *this;
	}
	Vector2 operator* (const float& obj) {
		return { X * obj, Y * obj };
	}
	Vector2 operator* (const int& obj) {
		return { X * obj, Y * obj };
	}
	Vector2 operator* (const Vector2& obj) {
		return { X *= obj.X, Y *= obj.Y };
	}
	Vector2& operator*= (const float& obj) {
		X *= obj;
		Y *= obj;
		return *this;
	}	
	Vector2& operator*= (const int& obj) {
		X *= obj;
		Y *= obj;
		return *this;
	}
	Vector2& operator*= (const Vector2& obj) {
		X *= obj.X;
		Y *= obj.Y;
		return *this;
	}
};