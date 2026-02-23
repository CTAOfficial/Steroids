#pragma once
#include <SDL3/SDL_stdinc.h>

struct RGBA {
public:
	RGBA(Uint8 r) {
		R = r;
	}
	RGBA(Uint8 r, Uint8 g) {
		R = r;
		G = g;
	}
	RGBA(Uint8 r, Uint8 g, Uint8 b) {
		R = r;
		G = g;
		B = b;
	}
	RGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		R = r;
		G = g;
		B = b;
		A = a;
	}

	Uint8 R = 0;
	Uint8 G = 0;
	Uint8 B = 0;
	Uint8 A = 0;

};