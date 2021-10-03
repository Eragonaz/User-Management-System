#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <time.h>

#include "System.h"

namespace EmployeeSys {


	enum class Months {January, Februrary, March, April, May, June, July, August, September, October, November, December};

	struct DailyPayrollInfo {
		float d_basePay = 0;
		float d_overtimePay = 0;

		float d_transportAllowance = 0;

		size_t day;

		DailyPayrollInfo(const size_t day = 0) : day(day) {}
	};

	struct MonthlyPayrollInfo {
		float m_basePay = 0;
		float m_overtimePay = 0;

		//float t_prformanceIncentive;
		float m_transportAllowance = 0;

		float m_bonuses = 0;
		float totalPay = 0;

		std::array<DailyPayrollInfo, 31> dailyPayBreakdown;

		time_t paymentTime = 0;
		Months paymentMonth = Months::January;
		size_t paymentYear = 0;

		size_t bankAccountNo = 0;
		float transactionRefID = 0;

		MonthlyPayrollInfo() {
			for (size_t d = 0; d < 31; d++)
				dailyPayBreakdown[d].day = d;
		}
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

	struct ContractHourly {
		float h_basePay;
		float h_overtimePay;
		float h_transportAllowance;

	};

	class Employee : public MNGSYS::User {
	public:
		virtual Employee* GetNonConst() const;
		void ChangePassword(const std::string& newPassword);

		//void UpdateBankAccount();
		//void UpdateContactDetails();

		Employee(const size_t userid, const std::string& username, const std::string& password);

	public:

	private:
		Employee(const Employee& c) = delete;
		Employee(Employee&& m) = delete;

		//std::vector<MonthlyPayrollInfo> SalaryRecord;
		//PersonalDetails PersonalDetails;
	};

}