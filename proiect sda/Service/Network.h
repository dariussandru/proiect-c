#ifndef NETWORK_H
#define NETWORK_H

#include "Event/Event.h"
#include "User/User.h"
#include "TAD/MultiDictionary.h"
#include "Set.h"
#include "Messange/Message.h"
#include <vector>
#include "iostream"

using namespace std;


class Network {
private:
    Set<User> users;
    Set<Event> events;
    MultiDictionary<User*, User*> friends;
    MultiDictionary<User*, Event*> attended_events;
    vector<Message> messages;

    Network();

    void loadUsersFromFile(string filename);
    void saveUsersToFile(string filename);

    void loadEventFromFile(string filename);
    void saveEventToFile(string filename);

public:
    static Network& getInstance();
    ~Network();
    Set<User>& getUsers();
    Set<Event>& getEvents();
    MultiDictionary<User*, User*>& getFriends();
    User* findUser(string username);
    Event* findEvent(string event_name);
    void addUser(User* user);
    void addEvent(Event* event);
    void addFriendship(User* user1, User* user2);
    void signUpForEven(User* user, Event* event);
    void addMessage(Message message);
    void modifyUser(User* user, User new_user);
    void updateEvent(Event* event, Event new_event);
    void removeUser(User* user);
    void removeEvent(Event* event);
    void removeFriendship(User* user1, User* user2);
    void removeAttendance(User* user, Event* event);
    vector<Message> getMessages(User* user);
    vector<Message> getMessages(User* user1, User* user2);
    vector<User*> getFriendsOf(User* user);
    vector<User*> getCommonFriends(User* user1, User* user2);

};

#endif // NETWORK_H

