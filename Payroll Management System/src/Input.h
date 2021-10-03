#pragma once
#include <map>
#include <functional>
#include <string>
#include <iostream>

/*
* TODO:
*
* = Command while loop
* = Parse input
* 
*/

namespace MNGSYS {

	class Input {
	public:
		template <typename T>
		void GetResponse(std::string& rMsg, T& rResponse) {
			std::cout << "\nPlease input your " + rMsg + ":" << std::endl;
			WaitUntilInput(rResponse);
			std::cout << std::endl;
		}

		template <typename T>
		void GetResponseThen(std::string& rMsg, T& rResponse, void (*callback)(T& rResponse)) {
			std::cout << "\nPlease input " + rMsg + ":" << std::endl;
			WaitUntilInput(rResponse);
			std::cout << std::endl;
			callback(rResponse);
		}

		template <typename T>
		void GetResponseWithReq(std::string& rMsg, T& rResponse, bool (*callback)(T& rResponse)) {
			std::cout << "\nPlease input " + rMsg + ":" << std::endl;
			
			WaitUntilInput(rResponse);
			while (!callback(rResponse)) {
				WaitUntilInput(rResponse);
			};
			std::cout << std::endl;
		}

		static Input* InitInput();
		static void DestroyInput();

	private:

		template <typename T>
		void WaitUntilInput(T& inputVar) {
			while (true) {
				std::cin >> inputVar;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input. Please try again:" << std::endl;
				}
				else {
					break;
				}

			}
		}

		Input();
		~Input();
		Input(const Input&) = delete;
		Input(Input&&) = delete;


	private:
		static Input* mpInput;
	};

}