#include "USocial.h"
#include <stdexcept>

#define FIRST_ID 1000

USocial::USocial() : _next_id(FIRST_ID)
{
}

USocial::~USocial()
{
	for (auto user : _users)
	{
		delete user.second;
	}
}

User* USocial::registerUser(std::string name)
{
	return registerUser(name, false);
}

User* USocial::registerUser(std::string name, bool is_business)
{
	if (name.length() < 2)
	{
		throw std::invalid_argument("invalid name. must be at least 2 characters.");
	}
	User* new_user;
	if (is_business)
	{
		new_user = new BusinessUser(_next_id++, name, this);
	}
	else
	{
		new_user = new User(_next_id++, name, this);
	}

	_users.insert(std::make_pair(new_user->getId(), new_user));

	return new_user;
}

void USocial::removeUser(User* user)
{
	if (!_users[user->getId()])
	{
		throw std::invalid_argument("There is no such user here");
	}
	for (auto u : _users)
	{
		try
		{
		u.second->removeFriend(user);
		}
		catch (const std::invalid_argument&)
		{
			// pass - if the currenct user is not friend of his, move on.
		}

	}
	_users.erase(user->getId());
	delete user;
}

User* USocial::getUserById(unsigned long id)
{
	User* user = _users[id];
	if (!user)
	{
		throw std::invalid_argument("There is no user with this ID");
	}

	return user;
}
