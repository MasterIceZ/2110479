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
}

void renderer_t::addVertex(float x, float y, float z) {
	vertices.emplace_back(x, y, z);
	
	verticesBuffer.emplace_back(x);
	verticesBuffer.emplace_back(y);
	verticesBuffer.emplace_back(z);
}

void renderer_t::addFace(size_t x, size_t y, size_t z) {
	if(x >= vertices.size() || y >= vertices.size() || z >= vertices.size()) {
		std::cerr << "Invalid Vertex index for Face" << std::endl;

		exit(-1);
	}	
	faces.emplace_back(x, y, z);

	facesBuffer.emplace_back(static_cast<unsigned int> (x));
	facesBuffer.emplace_back(static_cast<unsigned int> (y));
	facesBuffer.emplace_back(static_cast<unsigned int> (z));
}

void renderer_t::prerenderShapes() {
	GLenum err;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesBuffer.size() * sizeof(float), verticesBuffer.data(), GL_STATIC_DRAW);
	err = glGetError();
	if(err != GL_NO_ERROR) {
		std::cerr << "Error in glBufferData (VBO): " << err << std::endl;

		exit(-1);
	}

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, facesBuffer.size() * sizeof(unsigned int), facesBuffer.data(), GL_STATIC_DRAW);
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
