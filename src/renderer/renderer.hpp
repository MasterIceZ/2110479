#ifndef __RENDERER_HPP_INCLUDED__
#define __RENDERER_HPP_INCLUDED__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class renderer_t {
private:
	GLFWwindow *window;
public:
	renderer_t(size_t width, size_t height, std::string app_name="LEARN OPENGL");
	void start();
};

#endif
