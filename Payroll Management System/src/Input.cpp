#include "Input.h"

namespace MNGSYS {

	Input* Input::mpInput = nullptr;
	Input* Input::InitInput() {
		if (!mpInput) {
			mpInput = new Input();
		}
		else {
			// TODO: Warn that Input has already been created.
		}
		return mpInput;
	}
	void Input::DestroyInput() {
		if (mpInput)
			delete mpInput;
	}


	Input::Input() {
		//std::cout << "Input handler instantiated." << std::endl;
	}

	Input::~Input() {
		//std::cout << "Input handler destroyed." << std::endl;
	}

}