#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "renderer.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	if(width < 1 || height < 1) {
		std::cout << "WIDTH or HEIGHT is invalid" << std::endl;
		
		exit(-1);
	}

	std::cerr << "Window's size has been changed to (" << width << " x " << height << ")" << std::endl;

	glViewport(0, 0, width, height);
}

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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;

		exit(-1);
	}
}
