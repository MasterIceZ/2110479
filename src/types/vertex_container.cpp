#include <iostream>
#include <cstddef>

#include "vertex_container.hpp"

void vertex_container_t::addVertex(float x, float y, float z) {
	vertices.emplace_back(x, y, z);

	vertices_buffer.emplace_back(x);
	vertices_buffer.emplace_back(y);
	vertices_buffer.emplace_back(z);
}

void vertex_container_t::addFace(size_t x, size_t y, size_t z) {
	if(x >= vertices.size() || y >= vertices.size() || z >= vertices.size()) {
		std::cerr << "Invalid Vertex index for Face" << std::endl;

		exit(-1);
	}	
	faces.emplace_back(x, y, z);

	faces_buffer.emplace_back(static_cast<unsigned int> (x));
	faces_buffer.emplace_back(static_cast<unsigned int> (y));
	faces_buffer.emplace_back(static_cast<unsigned int> (z));
}	
