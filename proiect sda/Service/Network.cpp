#include "Network.h"
#include  <fstream>
#include "iostream"
#include "Event/Event.h"
#include "User/User.h"

using namespace std;

Network::Network()
    : users(),
    friends(),
    events()
{
    loadUsersFromFile("useri.csv");
    loadEventFromFile("event.csv");
}

void Network::loadUsersFromFile(std::string filename) {
    ifstream f(filename);
    if (f.is_open()) {
        User user;
        while (loadUserFromCSV(f, user))
        {
            this->users.add(user);
        }
    }
}

void Network::loadEventFromFile(string filename) {
    ifstream f(filename);
    if (f.is_open())
    {
        Event event;
        while(loadEventFromCSV(f,event) )
        {
            this->events.add(event);
        }
    }
}

void Network::saveUsersToFile(std::string filename) {
    std::ofstream f(filename);
    auto vecOfUsers = this->users.getAll();

    if (f.is_open()) {
        for (int i = 0; i < vecOfUsers.size(); i++) {
            loadUserIntoCSV(f, *vecOfUsers[i]);

        }
    }
}

void Network::saveEventToFile(string filename) {
    ofstream f(filename);
    auto vecOfEvents = this->events.getAll();

    if(f.is_open()){
        for( int i = 0; i < vecOfEvents.size(); i++){
            loadEventIntoCSV(f,*vecOfEvents[i]);
        }
    }
}



Network& Network::getInstance() {
    static Network instance;
    return instance;
}

Network::~Network()
{
    saveUsersToFile("useri.csv");
    saveEventToFile("event.csv");
}


Set<User>& Network::getUsers() {
    return users;
}

Set<Event>& Network::getEvents() {
    return events;
}

MultiDictionary<User*, User*>& Network::getFriends() {
    return friends;
}


User* Network::findUser(std::string username) {
    vector<User*> vecOfUsers = users.getAll();
    for (auto& user : vecOfUsers) {
        if (user->getUsername() == username) {
            return user;
        }
    }

    return nullptr;
}

void Network::addUser(User* user) {
    users.add(*user);
}

Event* Network::findEvent(string event_name) {
    vector<Event*> vecOfEvents = events.getAll();
    for (auto& event : vecOfEvents) {
        if (event->getName() == event_name) {
            return event;
        }
    }

    return nullptr;
}

void Network::addEvent(Event* event) {
    events.add(*event);
}

void Network::addFriendship(User* user1, User* user2) {
    if (!friends.contains(user1, user2))
        friends.add(user1, user2);

    if (!friends.contains(user2, user1))
        friends.add(user2, user1);
}

void Network::signUpForEven(User* user, Event* event) {
    if (!attended_events.contains(user, event))
        attended_events.add(user, event);
}

void Network::addMessage(Message message) {
    messages.push_back(message);
}

void Network::modifyUser(User* user, User new_user) {
    user->setUsername(new_user.getUsername());
    user->setPassword(new_user.getPassword());
    user->setEmail(new_user.getEmail());
    user->setFirstName(new_user.getFirstName());
    user->setLastName(new_user.getLastName());

}

void Network::updateEvent(Event* event, Event new_event) {
    event->setName(new_event.getName());
    event->setDescription(new_event.getDescription());
    event->setStartDate(new_event.getStartDate());
    event->setEndDate(new_event.getEndDate());
    event->setLocation(new_event.getLocation());
}

void Network::removeUser(User* user) {
    auto vecOfFriends = friends.get(user);

    for (auto& friendss : vecOfFriends) {
        friends.deletee(friendss, user);
    }

    auto attended_events_vec = attended_events.get(user);

    for (auto& event : attended_events_vec) {
        attended_events.deletee(user, event);
    }

    attended_events.deletee(user);

    users.remove(*user);
}

void Network::removeEvent(Event* event) {
    auto vecOfUsers = users.getAll();

    for (auto& user : vecOfUsers) {
        attended_events.deletee(user, event);
    }

    events.remove(*event);
}

void Network::removeFriendship(User* user1, User* user2) {
    friends.deletee(user1, user2);
    friends.deletee
    (user2, user1);
}

void Network::removeAttendance(User* user, Event* event) {
    attended_events.deletee(user, event);
}

vector<User*> Network::getFriendsOf(User* user) {
    return friends.get(user);
}

vector<User*> Network::getCommonFriends(User* user1, User* user2) {
    vector<User*> common_friends;

    vector<User*> friends_of_user1 = getFriendsOf(user1);
    vector<User*> friends_of_user2 = getFriendsOf(user2);

    for (auto& friend_ptr : friends_of_user1) {
        for (auto& friend_ptr2 : friends_of_user2) {
            if (friend_ptr == friend_ptr2) {
                common_friends.push_back(friend_ptr);
            }
        }
    }

    return common_friends;
}

vector<Message> Network::getMessages(User* user) {
    vector<Message> user_messages;

    for (auto& message : messages) {
        if (message.getReceiver() == user || message.getSender() == user) {
            user_messages.push_back(message);
        }
    }

    return user_messages;
}

vector<Message> Network::getMessages(User* user1, User* user2) {
    vector<Message> user_messages;

    for (auto& message : messages) {
        if ((message.getReceiver() == user1 && message.getSender() == user2) || (message.getReceiver() == user2 && message.getSender() == user1)) {
            user_messages.push_back(message);
        }
    }

    return user_messages;
}



