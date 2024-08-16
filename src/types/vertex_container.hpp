#ifndef __VERTEX_CONTAINER_HPP_INCLUDED__
#define __VERTEX_CONTAINER_HPP_INCLUDED__

#include <vector>
#include <cstddef>

#include "../types/vertex.hpp"
#include "../types/face.hpp"

class vertex_container_t {
private:
	size_t sz;
public:
	std::vector<vertex_t> vertices;
	std::vector<face_t> faces;
	std::vector<float> vertices_buffer;
	std::vector<unsigned int> faces_buffer;
	unsigned int VAO, VBO, EBO;

	void addVertex(float x, float y, float z);
	void addVertex(vertex_t a);
	void addFace(size_t x, size_t y, size_t z);
	void addTriangle(vertex_t a, vertex_t b, vertex_t c);
	void addCircle(float x, float y, float z, float r, size_t s=100);
	
	size_t size();
};

#endif
