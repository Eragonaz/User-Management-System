#pragma once
#include <iostream>
#include "Input.h"

/*
* TODO:
*
* = Add Details
* = Modify Details
* = Print Details
* = Serialization
* 
*/

namespace MNGSYS {

	class User {
	public:

		virtual User* GetNonConst() const;
		virtual void SerializeData();

		User(const size_t userid, const std::string& username, const std::string& password, Input* inputHandler);
		~User();

	public:
		size_t userid;
		std::string username;
		std::string password;

	protected:
		Input* mInputHandler;

	private:
		User(const User& c) = delete;
		
	};

}