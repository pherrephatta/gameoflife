#include "Controller.hpp"
#include <cstdio>
#include <cassert>

int main(int argc, char *argv[]) {

	uint16_t wdWidth = 200;
	uint16_t wdHeight = 200;

	// Changing window size at execution
	switch(argc) {
		case 2: {
			assert(atoi(argv[1]) > 0);
			wdWidth = wdHeight = atoi(argv[1]);
			break;
		}
		case 3: {
			assert(atoi(argv[1]) > 0);
			assert(atoi(argv[2]) > 0);
			wdWidth = atoi(argv[1]);
			wdHeight = atoi(argv[2]);
			break;
		}
		default: {
			break;
		}
	}

	View view(wdWidth, wdHeight);
	Model model(view.window().logWidth(), view.window().logHeight());
	Controller controller(model, view);
	controller.start();

	return 0;
}
