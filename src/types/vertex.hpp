#ifndef __VERTEX_HPP_INCLUDED__
#define __VERTEX_HPP_INCLUDED__

#include <cstddef>
#pragma pack(push, 1)

class vertex_t {
private:
	float x, y, z;
public:
	vertex_t(float _x, float _y, float _z);
	float getX();
	float getY();
	float getZ();
	static size_t getOffsetX();
	static size_t getOffsetY();
	static size_t getOffsetZ();
};

#pragma pack(pop)

#endif
