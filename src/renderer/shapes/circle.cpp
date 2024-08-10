#include <cmath>

#include "../renderer.hpp"

const int CIRCLE_SEGMENT = 100;

void renderer_t::addCircle(float x, float y, float z, float r) {
	float angle_step = 2.0f * acos(-1) / CIRCLE_SEGMENT;

	addVertex(x, y, z);
	int center_index = vertices.size() - 1;

	for(int i=0; i<=CIRCLE_SEGMENT; ++i) {
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
