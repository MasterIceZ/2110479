#ifndef __FACE_HPP_INCLUDED__
#define __FACE_HPP_INCLUDED__

#include <cstddef>

class face_t {
private:
	size_t a[3];
public:
	face_t(size_t _x, size_t _y, size_t _z);
	size_t getX();
	size_t getY();
	size_t getZ();
};

#endif
