#ifndef __SHADER_H_INCLUDED__
#define __SHADER_H_INCLUDED__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

unsigned int createShaderProgram(const std::string &vertexPath, const std::string &fragmentPath);

#endif
