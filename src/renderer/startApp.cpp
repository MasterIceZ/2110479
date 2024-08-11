#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

void checkKeyPress(GLFWwindow *window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void renderer_t::start() {
	for(int i=0; i<(int) sz; ++i) {
		if(!shader_container[i].shaderProgram) {
			std::cerr << "Invalid shader program" << std::endl;
	
			exit(-1);
		}
	}

	while(!glfwWindowShouldClose(window)) {
		checkKeyPress(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for(int i=0; i<(int) sz; ++i) {
			glUseProgram(shader_container[i].shaderProgram);
			glBindVertexArray(vertex_container[i].VAO);

			glDrawElements(GL_TRIANGLES, static_cast<GLsizei> (vertex_container[i].faces.size() * 3), GL_UNSIGNED_INT, 0);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	for(int i=0; i<(int) sz; ++i) {
		glDeleteVertexArrays(1, &vertex_container[i].VAO);
		glDeleteBuffers(1, &vertex_container[i].VBO);
		glDeleteBuffers(1, &vertex_container[i].EBO);
	}
	
	glfwTerminate();
}
