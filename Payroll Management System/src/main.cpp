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

		system.AddUser<Employee>("b", "c");
		system.PromptSignIn();

		Employee* e = system.DerivedUserType<Employee>(system.GetActiveUser()->GetNonConst());
	}

	Input::DestroyInput();
	std::cin.get();
	std::cin.get();
	return 0;
}

#ifdef DX
#endif // DX
