#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

void checkKeyPress(GLFWwindow *window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void renderer_t::start(unsigned int shaderProgram) {
	if(!shaderProgram) {
		std::cerr << "Invalid shader program" << std::endl;

		exit(-1);
	}
	while(!glfwWindowShouldClose(window)) {
		checkKeyPress(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);


		glDrawElements(GL_TRIANGLES, static_cast<GLsizei> (faces.size() * 3), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	
	glfwTerminate();
}
