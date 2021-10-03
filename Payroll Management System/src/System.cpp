#include "System.h"

namespace MNGSYS {

	const User* System::PromptSignIn(bool persistent) {
		std::string username;
		std::string password;
		std::string msg1 = "username";
		std::string msg2 = "password";

		printDiv(true);
		std::cout << "[SYSTEM]: You are now signing in:" << std::endl;

		for (size_t i = 0; i < PERSISTENT_LOGIN_ATTEMPTS; i++) {
			mInputHandler->GetResponse<std::string>(msg1, username);
			mInputHandler->GetResponse<std::string>(msg2, password);
			
			const User* user = UserSignIn(username, password);

			if (user != USER_NOT_FOUND || !persistent) {
				std::cout << "[SYSTEM]: Sign in succesful!" << std::endl;
				printDiv();
				return user;
			}
		}
		std::cout << "[FAILURE]: You have reached the max retry limit. Please try again later." << std::endl;
		printDiv();
		return USER_NOT_FOUND;
	}

	const User* System::UserSignIn(const std::string& username, const std::string& password) {
		const User* user = getUserFromUsername(username);

		if (user != USER_NOT_FOUND) {
			if (user->password == password) {
				SetActiveUser(user);
				return user;
			}
			std::cout << "[FAILURE]: Incorrect password." << std::endl;
			return USER_NOT_FOUND;
		}
		std::cout << "[FAILURE]: Username not found." << std::endl;
		return USER_NOT_FOUND;
	}

	void System::SetActiveUser(const size_t& userid, const std::string& username) {
		mCached.user.userid = userid;
		mCached.user.username = username;
	}

	void System::SetActiveUser(const User* user) {
		mCached.user.userid = user->userid;
		mCached.user.username = user->username;
	}
 
	const SystemCache::ActiveUser& System::GetActiveUser() const {
		return mCached.user;
	}

	void System::PrintActiveUser() const {
		std::cout << "Active User ID: " << mCached.user.userid;
		std::cout << "\nActive User Name: " << mCached.user.username << std::endl;
	}

	const User* System::AddAdministator(const std::string& username, const std::string& password) {
		//AddUser(username, password);
		return USER_NOT_FOUND;
	}

	bool System::isUsernameTaken(const std::string& username) const {
		return doesUserExist(username);
	}

	bool System::doesUserExist(const std::string& username) const {
		return getUserFromUsername(username) ? true : false;
	}

	bool System::doesUserExist(const size_t& userid) const {
		return getUserFromUserid(userid) ? true : false;
	}

	const User* System::getUserFromUsername(const std::string& username) const {
		for (const User* user : mUsers) {
			if (user->username == username) {
				return mUsers[user->userid - 1];
			}
		}
		return USER_NOT_FOUND;
	}

	const User* System::getUserFromUserid(const size_t& userid) const {
		for (const User* user : mUsers) {
			if (user->userid == userid) {
				return mUsers[user->userid - 1];
			}
		}
		return USER_NOT_FOUND;
	}

	const std::string& System::getUsernameFromUserid(const size_t& userid) const {
		for (const User* user : mUsers) {
			if (user->userid == userid) {
				return user->username;
			}
		}
		return USERID_NOT_FOUND;
	}

	const size_t& System::getUseridFromUsername(const std::string& username) const {
		for (const User* user : mUsers) {
			if (user->username == username) {
				return user->userid;
			}
		}
		return USERNAME_NOT_FOUND;
	}


	System::System(Input* inputHandler) : mInputHandler(inputHandler) {
		mUsers.reserve(DEFAULT_MAX_USERS);
	}

	System::~System() {
		Destroy();
	}

	void System::Destroy() {
		for (const User* user : mUsers) {
			delete user;
		}
	}

	void printDiv(bool newlineAbove) {
		if (newlineAbove)
			std::cout << std::endl;
		std::cout << std::setfill('*') << std::setw(80 + 1) << " " << std::setfill(' ') << std::endl;
		if (!newlineAbove)
			std::cout << std::endl;
	}

}