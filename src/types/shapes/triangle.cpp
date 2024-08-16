#include <iostream>

#include "../vertex_container.hpp"

void vertex_container_t::addTriangle(vertex_t a, vertex_t b, vertex_t c) {
	addVertex(a);
	addVertex(b);
	addVertex(c);	

	int last_index = (int) vertices.size() - 1;
	if(last_index < 2) {
		std::cerr << "VERTEX NOT FOUND" << std::endl;
	}
	addFace(last_index - 2, last_index - 1, last_index);
}
