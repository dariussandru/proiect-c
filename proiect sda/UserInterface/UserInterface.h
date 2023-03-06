#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Service/Network.h"

class UserInterface {
public:
    UserInterface();
    ~UserInterface();

    void start();

private:
    Network& network;

    void userDetails();
    void listUsers();
    void addUser();
    void modifyUser();
    void deleteUser();

    void eventDetails();
    void listEvents();
    void addEvent();
    void updateEvent();
    void deleteEvent();

    void addFriendship();
    void removeFriendship();
    void listFriends();
    void listCommonFriends();

    void signUpForEven();
    void removeAnEvent();

    void addMessage();
    void messagesOfUser();
    void messagesBetweenUsers();
};

#endif // USERINTERFACE_H
