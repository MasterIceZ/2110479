#include "renderer/renderer.hpp"
#include "shader/shader.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

signed main(int argc, char *argv[]) {
	renderer_t renderer(SCR_WIDTH, SCR_HEIGHT, "MY APP");

	renderer.addCircle(0, 0, 0, 0.5);

	unsigned int shaderProgram = createShaderProgram("shaders/shader.vs", "shaders/shader.fs");

	renderer.prerenderShapes();

	renderer.start(shaderProgram);
	return 0;
}
