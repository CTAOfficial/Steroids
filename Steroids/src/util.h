#pragma once

#include <numbers>
#include <random>

namespace util {
	double pi = std::numbers::pi;
	static int GetRandom(int min, int max) {
		return min + rand() % (max - min + 1);
	}

	/*static int GetRandom(int min, int max) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist;

		return dist(gen);
	}*/
	static float GetRandom(float min, float max) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dist;

		return dist(gen);
	}
}