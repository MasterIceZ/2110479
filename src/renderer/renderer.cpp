#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "renderer.hpp"

renderer_t::renderer_t(size_t width, size_t height, std::string app_name) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(width, height, app_name.c_str(), NULL, NULL);
	if(window == NULL) {
		std::cout << "Failed to create FLGW window" << std::endl;
		glfwTerminate();

		exit(-1);
	}

	glfwMakeContextCurrent(window);
	
	if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;

		exit(-1);
	}
}
