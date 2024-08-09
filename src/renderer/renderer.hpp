#ifndef __RENDERER_HPP_INCLUDED__
#define __RENDERER_HPP_INCLUDED__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>

#include "types/vertex.hpp"
#include "types/face.hpp"

class renderer_t {
private:
	GLFWwindow *window;
	std::vector<vertex_t> vertices;
	std::vector<float> verticesBuffer;
	std::vector<face_t> faces;
	std::vector<unsigned int> facesBuffer;
	unsigned int VAO, VBO, EBO;
public:
	renderer_t(size_t width, size_t height, std::string app_name="LEARN OPENGL");
	void start(unsigned int shaderProgram);
	void addVertex(float x, float y, float z);
	void addFace(size_t x, size_t y, size_t z);
	void prerenderShapes();
};

#endif
