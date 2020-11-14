#pragma once
#include <string>
#include <list>
#include "Post.h"
#include "Message.h"
#include "USocial.h"
class USocial;

class User
{
	friend class USocial;
public:
	unsigned long getId() const;
	std::string getName() const;
	void addFriend(User*);
	void removeFriend(User*);
	void publishPost(std::string);
	void publishPost(std::string, Media*);
	std::list<Post*> getPosts() const;
	void viewFriendsPosts() const;
	void receivieMessage(Message*);
	virtual void sendMessage(User*, Message*);
	void viewReceivedMessages() const;



private:
	USocial* _usocial;
	bool isUserMyFriend(User*);
protected:

// USocial* usocial;
	explicit User(unsigned long, std::string, USocial*);
	~User();
	// user should not be copied
	User(User const&) = delete;
	User& operator=(User const&) = delete;

	unsigned long _id;
	std::string _name;
	std::list<unsigned long> _friends;
	std::list<Post*> _posts;
	std::list<Message*> _receiviedMsgs;

};

class BusinessUser : public User
{
	friend class USocial;
protected:
	explicit BusinessUser(unsigned long id, std::string name, USocial* usocial) :
		User(id, name, usocial) {}
public:
	virtual void sendMessage(User*, Message*) override;

};