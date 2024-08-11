#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

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
		std::cerr << "Failed to initialize GLAD" << std::endl;

		exit(-1);
	}

	sz = (size_t) 0;
}

void renderer_t::addShader(const std::string& vertexPath, const std::string& fragmentPath) {
	shader_container.emplace_back(vertexPath, fragmentPath);
	vertex_container.emplace_back();
	sz = sz + 1;
}

void renderer_t::prerenderShapes() {
	GLenum err;

	for(int i=0; i<sz; ++i) {
		glGenVertexArrays(1, &vertex_container[i].VAO);
		glGenBuffers(1, &vertex_container[i].VBO);
		glGenBuffers(1, &vertex_container[i].EBO);

		glBindVertexArray(vertex_container[i].VAO);

		glBindBuffer(GL_ARRAY_BUFFER, vertex_container[i].VBO);
		glBufferData(GL_ARRAY_BUFFER, vertex_container[i].vertices_buffer.size() * sizeof(float), vertex_container[i].vertices_buffer.data(), GL_STATIC_DRAW); 
		err = glGetError();
		if(err != GL_NO_ERROR) {
			std::cerr << "Error in glBufferData (VBO): " << err << std::endl;

			exit(-1);
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_container[i].EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertex_container[i].faces_buffer.size() * sizeof(unsigned int), vertex_container[i].faces_buffer.data(), GL_STATIC_DRAW);
		err = glGetError();
		if(err != GL_NO_ERROR) {
			std::cerr << "Error in glBufferData (EBO): " << err << std::endl;

			exit(-1);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
		glEnableVertexAttribArray(0);
		err = glGetError();
		if(err != GL_NO_ERROR) {
		   std::cerr << "Error in glVertexAttribPointer: " << err << std::endl;

		   exit(-1);
		}	   

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}
}

size_t renderer_t::size() {
	return sz;
}

shader_t& renderer_t::getShaderContainer(size_t idx) {
	if(idx >= sz) {
		std::cerr << "Shader Container index out of bound" << std::endl;

		exit(-1);
	}
	return shader_container[idx];
}

vertex_container_t& renderer_t::getVertexContainer(size_t idx) {
	if(idx >= sz) {
		std::cerr << "Vertex Container index out of bound" << std::endl;

		exit(-1);
	}
	return vertex_container[idx];
}
