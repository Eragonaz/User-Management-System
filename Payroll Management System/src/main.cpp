#include <iostream>
#include "System.h"
#include "Employee.h"

using MNGSYS::Input;
using MNGSYS::System;
using MNGSYS::User;
	
using EmployeeSys::Employee;

int main() {
	Input* input = Input::InitInput();

	{
		System system(input);

		for (size_t i = 0; i < 10000; i++) {
			system.AddUser<User>("a" + std::to_string(i));
		}

		system.AddUser<User>("a");
		system.AddUser<Employee>("b", "c");
	}

	{
		System system(input);

		for (size_t i = 0; i < 10000; i++) {
			system.AddUser<User>("a" + std::to_string(i));
		}

		system.AddUser<User>("a");
		system.AddUser<Employee>("b", "c");
	}

	{
		System system(input);

		for (size_t i = 0; i < 10000; i++) {
			system.AddUser<User>("a" + std::to_string(i));
		}

		system.AddUser<User>("a");
		system.AddUser<Employee>("b", "c");
	}

	Input::DestroyInput();
	std::cin.get();
	std::cin.get();
	return 0;
}

#ifdef DX
#endif // DX
