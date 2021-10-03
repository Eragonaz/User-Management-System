#include "Employee.h"

namespace EmployeeSys {
	
	Employee* Employee::GetNonConst() const {
		return (Employee*)this;
	}

	void Employee::ChangePassword(const std::string& newPassword) {
		password = newPassword;
	}

	Employee::Employee(const size_t userid, const std::string& username, const std::string& password) 
		: User(userid, username, password) {
		
		
	}

}