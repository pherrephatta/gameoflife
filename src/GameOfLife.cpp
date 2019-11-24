#include "Controller.hpp"
#include <cstdio>
#include <cassert>

int main(int argc, char *argv[]) {

	uint16_t wdWidth = 1024;
	uint16_t wdHeight = 768;

	// Changing window size at execution
	switch(argc) {
		case 2: {
			assert(atoi(argv[1]) > 0);
			wdWidth = wdHeight = atoi(argv[1]);
			printf("%d %d\n", wdWidth, wdHeight);
			break;
		}
		case 3: {
			assert(atoi(argv[1]) > 0);
			assert(atoi(argv[2]) > 0);
			wdWidth = atoi(argv[1]);
			wdHeight = atoi(argv[2]);
			printf("%d %d\n", wdWidth, wdHeight);
			break;
		}
		default: {
			printf("%d %d\n", wdWidth, wdHeight);
			break;
		}
	}

	Model model(wdWidth, wdHeight);
	View view(wdWidth, wdHeight);
	Controller controller(model, view);
	controller.start();

	return 0;
}
