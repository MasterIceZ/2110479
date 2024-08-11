#include <cmath>

#include "../vertex_container.hpp"

void vertex_container_t::addCircle(float x, float y, float z, float r, size_t segment) {
	float angle_step = 2.0f * acos(-1) / segment;

	addVertex(x, y, z);
	int center_index = vertices.size() - 1;

	for(int i=0; i<=segment; ++i) {
		float cur_angle = i * angle_step;
		float cur_x = r * cos(cur_angle) + x;
		float cur_y = r * sin(cur_angle) + y;
		float cur_z = z;

		addVertex(cur_x, cur_y, cur_z);
		if(i != 0) {
			int vertex_index = vertices.size() - 1;
			addFace(center_index, vertex_index, vertex_index - 1);
		}
	}
}
