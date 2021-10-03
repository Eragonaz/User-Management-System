#pragma once
#include "Employee.h"

// Combine the terminal with a login system to alternate between employee and managament
// Maybe a third party like system to control time etc

class Management {
public:
	Management(std::string companyName) {

	}

	void HireNewEmployee();

	void ClockIn(int EmployeeID) {
		/*
		* Verify ID 
		* Set start time
		* 
		*/
	}
private:
	std::vector<> activeContracts;
	std::vector<Employee::Employee> employeeList;
};

namespace Shared {
	
	struct DailyPayrollInfo {
		float d_basePay;
		float d_overtimePay;

		float d_transportAllowance;

		size_t day;
	};
	struct MonthlyPayrollInfo {
		float m_basePay;
		float m_overtimePay;

		//float t_prformanceIncentive;
		float m_transportAllowance;

		float m_bonuses;
		float totalPay;

		std::array<DailyPayrollInfo, 31> dailyPayBreakdown;

		time_t paymentTime;
		Months paymentMonth;
		size_t paymentYear;

		size_t bankAccountNo;
		float transactionRefID;
	};

	struct PersonalDetails {
		std::string surName;
		std::string firstName;
		std::string fullName;

		size_t id;

		struct Contact {
			size_t phoneNo;
			std::string emailAddress;
			std::string homeAddress;
		};

		struct NOKContact {
			std::string relationship;
			size_t phoneNo;
			std::string emailAddress;
			std::string homeAddress;
		};
	};
}