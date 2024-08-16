#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <algorithm>

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

	glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	GLint tLocation = glGetUniformLocation(shader_container[0].shaderProgram, "tim");
    if (tLocation == -1) {
        std::cerr << "Failed to find uniform location for 'tim'" << std::endl;
    }

	float tValue = 1.0f;
	while(!glfwWindowShouldClose(window)) {
		checkKeyPress(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // only lines of face
		
		tValue += 0.001f; 
		for(int i=0; i<(int) sz; ++i) {
			shader_container[i].use();
    		glUniform1f(tLocation, tValue);
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
