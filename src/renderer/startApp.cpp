#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

void renderer_t::start() {
	while(!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
}
