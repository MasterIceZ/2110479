#version 330 core

layout (location = 0) in vec3 aPos;

uniform float tim;

void main() {
	float x = 0.1, angle = tim, z = 0.1;
	mat4 rotate_x = mat4(
		cos(x), -sin(x), 0, 0, 
		sin(x), cos(x), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	mat4 rotate_y = mat4(
        cos(angle), 0.0, sin(angle), 0.0,
        0.0, 1.0, 0.0, 0.0,
        -sin(angle), 0.0, cos(angle), 0.0,
        0.0, 0.0, 0.0, 1.0
    );	

	mat4 rotate_z = mat4(
		1, 0, 0, 0,
		0, cos(z), -sin(z), 0,
		0, sin(z), cos(z), 0,
		0, 0, 0, 1
	);


	gl_Position = rotate_z * rotate_y * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
