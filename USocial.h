#pragma once
#include <map>
#include <string>
#include "User.h"

class User;

class USocial
{
public:
	USocial();
	~USocial();
	// social net should not be copied
	USocial(USocial const&) = delete;
	USocial& operator=(USocial const&) = delete;

	User* registerUser(std::string);
	User* registerUser(std::string, bool);
	void removeUser(User*);
	User* getUserById(unsigned long);

private:
	std::map<unsigned long, User*> _users;
	unsigned long _next_id;

};
