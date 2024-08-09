#include <cstddef>

#include "face.hpp"

face_t::face_t(size_t _x, size_t _y, size_t _z) {
	a[0] = _x, a[1] = _y, a[2] = _z;
}

size_t face_t::getX() {
	return a[0];
}

size_t face_t::getY() {
	return a[1];
}

size_t face_t::getZ() {
	return a[2];
}
