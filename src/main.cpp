#include "renderer/renderer.hpp"

#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

signed main(int argc, char *argv[]) {
	renderer_t renderer(SCR_WIDTH, SCR_HEIGHT);
	renderer.start();
	return 0;
}
