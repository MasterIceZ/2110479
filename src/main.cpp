#include "renderer/renderer.hpp"
#include "shader/shader.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

signed main(int argc, char *argv[]) {
	renderer_t renderer(SCR_WIDTH, SCR_HEIGHT, "MY APP");

	renderer.addShader("shaders/shader.vs", "shaders/shader.fs");
	renderer.addShader("shaders/shader.vs", "shaders/shaderYellow.fs");

	renderer.getVertexContainer(0).addCircle(0, 0, 0, 0.5, 4);
	renderer.getVertexContainer(1).addVertex(0, 0.5, 0);
	renderer.getVertexContainer(1).addVertex(0, -0.5, 0);
	renderer.getVertexContainer(1).addVertex(0.5, 0, 0);
	renderer.getVertexContainer(1).addFace(0, 1, 2);

	renderer.prerenderShapes();

	renderer.start();
	return 0;
}
