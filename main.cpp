#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "USocial.h"
#include "Media.h"
#include "Audio.h"
#include "Photo.h"

int main()
{
	USocial us;
	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");
	u1->publishPost("Hello world!");
	u2->publishPost("I'm having a great time here :)", new Audio());
	u3->publishPost("This is awesome!", new Photo());
	u5->addFriend(u1);
	u5->addFriend(u2);
	u5->viewFriendsPosts(); // should see only u1, u2 s' posts
	u4->sendMessage(u5, new Message("Buy Falafel!"));
	u5->viewReceivedMessages();
	try
	{
		u3->sendMessage(u5, new Message("All your base are belong to us"));
	}
	catch (const std::exception & e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	u5->viewReceivedMessages();
	u3->addFriend(u5);
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u5->viewReceivedMessages();

	us.removeUser(u1);
	u5->viewFriendsPosts();

	return 0;
}