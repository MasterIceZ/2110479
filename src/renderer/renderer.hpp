#ifndef __RENDERER_HPP_INCLUDED__
#define __RENDERER_HPP_INCLUDED__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>

#include "../shader/shader.hpp"
#include "../types/vertex_container.hpp"

class renderer_t {
private:
	GLFWwindow *window;
	size_t sz;
	std::vector<shader_t> shader_container;
	std::vector<vertex_container_t> vertex_container;
public:
	renderer_t(size_t width, size_t height, std::string app_name="LEARN OPENGL");
	void start();
	void addShader(const std::string& vertexPath, const std::string& fragmentPath);
	void addVertex(float x, float y, float z);
	void addFace(size_t x, size_t y, size_t z);
	void addCircle(float x, float y, float z, float r, int segment=100);
	void prerenderShapes();

	size_t size();
	shader_t& getShaderContainer(size_t idx);
	vertex_container_t& getVertexContainer(size_t idx);
};

#endif
