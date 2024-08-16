#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "shader.hpp"

std::string readShaderSource(const std::string& filename) {
	std::ifstream file(filename);

	if(!file.is_open()) {
		std::cerr << "Cannot open shader file: " << filename << std::endl;

		exit(-1);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

void logShaderCompileError(unsigned int shader, std::string compile_type) {
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cerr << "ERROR: Shader " << compile_type << " Compiled Failed!" << std::endl;

		exit(-1);
	}
}

unsigned int loadShaderVertex(const std::string& source) {
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShaderCode = source.c_str();

	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexShader);

	logShaderCompileError(vertexShader, "Vertex");

	return vertexShader;
}

unsigned int loadShaderFragment(const std::string& source) {
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShaderCode = source.c_str();

	glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentShader);

	logShaderCompileError(fragmentShader, "Fragment");
	
	return fragmentShader;
}

unsigned int loadShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) {
	unsigned int shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cerr << "ERROR: Shader Program Linking Failed!" << std::endl;
		
		exit(-1);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

shader_t::shader_t(const std::string& vertexPath, const std::string &fragmentPath) {
	std::string vertexShaderSource = readShaderSource(vertexPath);
	std::string fragmentShaderSource = readShaderSource(fragmentPath);

	vertexShader = loadShaderVertex(vertexShaderSource);
	fragmentShader = loadShaderFragment(fragmentShaderSource);

	shaderProgram = loadShaderProgram(vertexShader, fragmentShader);
}

void shader_t::use() {
	glUseProgram(shaderProgram);
}
