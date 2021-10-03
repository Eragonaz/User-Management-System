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
		
		/*

		std::string surName;
		std::string firstName;
		std::string fullName;

		size_t id;

		struct Contact {
			size_t phoneNo;
			std::string emailAddress;
			std::string homeAddress;
		} contact;

		struct NOKContact {
			std::string relationship;
			size_t phoneNo;
			std::string emailAddress;
			std::string homeAddress;
		} NOKcontact;
		*/
	}

}