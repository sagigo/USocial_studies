#include <iostream>
#include<algorithm>
#include<stdexcept>
#include "User.h"

unsigned long User::getId() const
{
	return _id;
}

std::string User::getName() const
{
	return _name;
}

void User::addFriend(User* user)
{
	if (std::find(_friends.cbegin(), _friends.cend(), user->getId()) == _friends.cend())
	{
		_friends.push_back(user->getId());
	}
	else
	{
		throw std::invalid_argument("The user provided is in friends list already");
	}
}

void User::removeFriend(User* user)
{
	if (std::find(_friends.cbegin(), _friends.cend(), user->getId()) != _friends.cend())
	{
		_friends.remove(user->getId());
	}
	else
	{
		throw std::invalid_argument("The user provided is not in friends list");
	}
}

void User::publishPost(std::string text)
{
	_posts.push_front(new Post(text));
}

void User::publishPost(std::string text, Media* media)
{
	_posts.push_front(new Post(text, media));
}

std::list<Post*> User::getPosts() const
{
	return _posts;
}

void User::viewFriendsPosts() const
{
	std::cout << "Displaying " << getName() << "\' friends posts:\n";
	for (auto friend_id : _friends)
	{
		User* friend_p = _usocial->getUserById(friend_id);
		std::list<Post*> friend_posts = friend_p->getPosts();
		std::cout << "\t" << friend_p->getName() << ":\n";
		for (auto post : friend_posts)
		{
			
			post->display();
		}
		std::cout << std::endl;
	}
}

void User::receivieMessage(Message* message)
{
	if (!message)
	{
		throw std::invalid_argument("got null message");
	}
	_receiviedMsgs.push_front(message);
}

void User::sendMessage(User* user, Message* message)
{
	if (!user)
	{
		throw std::invalid_argument("got null user");
	}

	if (!isUserMyFriend(user)) 
	{
		throw std::invalid_argument("cannot send message to user is'nt your friend");
	}

	user->receivieMessage(message);
}

void User::viewReceivedMessages() const
{
	std::cout << "Displaying " << getName() << "\'s messages:\n";
	for (auto msg : _receiviedMsgs)
	{
		std::cout << *msg << "\n";
	}
	std::cout << std::endl;
}

bool User::isUserMyFriend(User* user)
{
	for (auto friend_id : _friends)
	{
		if (_usocial->getUserById(friend_id) == user)
		{
			return true;
		}
	}
	return false;
}

User::User(unsigned long id, std::string name, USocial* usocial) : _id(id), _name(name)
{
	_usocial = usocial;
}

User::~User()
{
	for (auto post: _posts)
	{
		delete post;
	}
	for (auto msg : _receiviedMsgs)
	{
		delete msg;
	}
}

void BusinessUser::sendMessage(User* user, Message* message)
{
	if (!user)
	{
		throw std::invalid_argument("got null user");
	}
	user->receivieMessage(message);
}
