#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

void checkKeyPress(GLFWwindow *window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void renderer_t::start() {
	while(!glfwWindowShouldClose(window)) {
		checkKeyPress(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
}
