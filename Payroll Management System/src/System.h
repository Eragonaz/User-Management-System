#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

#include "Input.h"
#include "User.h"


/*
* TODO:
*
* = Admins
* = Serialization
* 
*/

namespace MNGSYS {
	constexpr size_t DEFAULT_MAX_USERS = 10;
	constexpr size_t PERSISTENT_LOGIN_ATTEMPTS = 5;

	const std::string USERID_NOT_FOUND = "USERID NOT FOUND";
	constexpr size_t USERNAME_NOT_FOUND = 0;
	constexpr User* USER_NOT_FOUND = nullptr;

	void printDiv(bool newlineAbove = false);

	struct SystemCache {
		struct ActiveUserInfo {
			size_t userid;
			std::string username;

			ActiveUserInfo() : userid(0), username("error") {
				std::cout << "Active user created" << std::endl;
			};
			ActiveUserInfo(const ActiveUserInfo& c) = delete;
		} userInfo;

		User* user;

		SystemCache() : userInfo(), user(USER_NOT_FOUND) {
			std::cout << "Cache created." << std::endl;
		}
		SystemCache(const SystemCache& c) = delete;
	};

	class System {
	public:

		const User* PromptSignIn(bool persistentMode = false);
		const User* UserSignIn(const std::string& username, const std::string& password);

		template<typename T>
		const T* PromptSignUp(bool persistentMode = false) {
			std::string username;
			std::string password;

			printDiv(true);
			std::cout << "[SYSTEM]: You are now signing up:" << std::endl;

			for (size_t i = 0; i < PERSISTENT_LOGIN_ATTEMPTS; i++) {
				mInputHandler->GetResponse<std::string>("username", username);
				mInputHandler->GetResponse<std::string>("password", password);

				const T* newUser = UserSignUp<T>(username, password);

				if (newUser != (T*)USER_NOT_FOUND || !persistentMode) {
					SetActiveUser(BaseUserType<T>(newUser));

					std::cout << "[SYSTEM]: Sign up succesful!" << std::endl;
					printDiv();
					return newUser;
				}
			}
			std::cout << "[FAILURE]: You have reached the max retry limit. Please try again later." << std::endl;
			printDiv();
			return (T*)USER_NOT_FOUND;
		}
		
		template<typename T>
		const T* UserSignUp(const std::string& username, const std::string& password) {
			if (!isUsernameTaken(username)) {
				return AddUser<T>(username, password);
			}
			std::cout << "[FAILURE]: Username already taken." << std::endl;
			return (T*)USER_NOT_FOUND;
		}

		template<typename T>
		const T* AddUser(const std::string& username, const std::string& password = "password") {
			if (!doesUserExist(username)) {
				const size_t userid = mUsers.size() + 1;

				if (!doesUserExist(userid)) {
					T* newT = new T(userid, username, password, mInputHandler);
					User* newUser = reinterpret_cast<User*>(newT);
					if (newUser) {
						mUsers.emplace_back(newUser);
						//const std::unique_ptr<User>& newUser = mUsers.back();
						return newT;
					}
					std::cout << "[FAILURE]: User Type is an incompatible type." << std::endl;
				}
				std::cout << "[FAILURE]: Unknown error occured." << std::endl;
				return (T*)USER_NOT_FOUND;
			}
			std::cout << "[FAILURE]: Username already exists." << std::endl;
			return (T*)USER_NOT_FOUND;
		};
		

		template<typename T>
		const User* BaseUserType(const T* user) {
			return reinterpret_cast<const User*>(user);
		}

		template<typename T>
		User* BaseUserType(T* user) {
			return reinterpret_cast<User*>(user);
		}

		template<typename T> 
		const T* DerivedUserType(const User* user) {
			return reinterpret_cast<T*>(user);
		}

		template<typename T>
		T* DerivedUserType(User* user) {
			return reinterpret_cast<T*>(user);
		}

		const User* AddAdministator(const std::string& username = "admin", const std::string& password = "admin");

		const SystemCache::ActiveUserInfo& GetActiveUserInfo() const;
		const User* GetActiveUser() const;
		void PrintActiveUser() const;

		System(Input* mInputHandler);
		~System();

	private:
		void SetActiveUser(const size_t& userid, const std::string& username);
		void SetActiveUser(const User* user);
		bool isUsernameTaken(const std::string& username) const;
		bool doesUserExist(const std::string& username) const;
		bool doesUserExist(const size_t& userid) const;

		const User* getUserFromUsername(const std::string& username) const;
		const User* getUserFromUserid(const size_t& userid) const;
		const std::string& getUsernameFromUserid(const size_t& userid) const;
		const size_t& getUseridFromUsername(const std::string& username) const;

		void Destroy();

		System(const System&) = delete;
		System(System&&) = delete;

	private:
		std::vector<User*> mUsers;
		struct SystemCache mCached;
		Input* mInputHandler;
	};

} 