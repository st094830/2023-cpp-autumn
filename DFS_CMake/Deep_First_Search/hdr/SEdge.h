#pragma once
#ifndef _SEDGE_
#define _SEDGE_

#include <iostream>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a , int b, int w) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

#endif
