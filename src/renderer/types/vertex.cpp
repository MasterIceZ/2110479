#include <cstddef>

#include "vertex.hpp"

vertex_t::vertex_t(float _x, float _y, float _z):
	x(_x), y(_y), z(_z) {}

float vertex_t::getX() {
	return x;
}

float vertex_t::getY() {
	return y;
}

float vertex_t::getZ() {
	return z;
}

size_t vertex_t::getOffsetX() {
	return offsetof(vertex_t, x);
}

size_t vertex_t::getOffsetY() {
	return offsetof(vertex_t, y);
}

size_t vertex_t::getOffsetZ() {
	return offsetof(vertex_t, z);
}
