#include "User.h"

namespace MNGSYS {

	User* User::GetNonConst() const {
		return (User*)this;
	}

	void User::SerializeData() {
	}

	User::User(const size_t userid, const std::string& username, const std::string& password)
		: userid(userid), username(username), password(password) {
	}

	User::~User() {
	}

}