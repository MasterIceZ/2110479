#include "renderer/renderer.hpp"
#include "shader/shader.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

signed main(int argc, char *argv[]) {
	renderer_t renderer(SCR_WIDTH, SCR_HEIGHT, "MY APP");

	renderer.addVertex(0.5f, 0.5f, 0.0f);
	renderer.addVertex(0.5f, -0.5f, 0.0f);
	renderer.addVertex(-0.5f, -0.5f, 0.0f);
	renderer.addVertex(-0.5f, 0.5f, 0.0f);
	renderer.addVertex(0.9f, -0.9f, 0.0f);

//	renderer.addFace(0, 1, 3);
	renderer.addFace(1, 2, 3);
	renderer.addFace(0, 1, 4);

	unsigned int shaderProgram = createShaderProgram("shaders/shader.vs", "shaders/shader.fs");

	renderer.prerenderShapes();

	renderer.start(shaderProgram);
	return 0;
}
