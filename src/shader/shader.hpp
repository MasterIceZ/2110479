#ifndef __SHADER_H_INCLUDED__
#define __SHADER_H_INCLUDED__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class shader_t {
public:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;

	shader_t(const std::string &vertexPath, const std::string &fragmentPath);
	void use();
};

#endif
