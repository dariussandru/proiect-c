#include "UserInterface.h"


UserInterface::UserInterface()
    : network(Network::getInstance())
{}

UserInterface::~UserInterface()
{}

void UserInterface::start() {
    int command = -1;

    while (true) {
        cout << "1. User details" <<endl;
        cout << "2. List users" << endl;
        cout << "3. Add user" << endl;
        cout << "4. Update user" << endl;
        cout << "5. Delete user" << endl;
        cout << endl;
        cout << "6. Event details" << endl;
        cout << "7. List events" <<endl;
        cout << "8. Add event" << endl;
        cout << "9. Update event" << endl;
        cout << "10. Delete event" << endl;

        cout << endl;
        cout << "11. Add friendship" << endl;
        cout << "12. Remove friendship" << endl;
        cout << "13. List friends" << endl;
        cout << "14. List common friends" <<endl;
        cout << endl;
        cout << "15. Sign up for an even" << endl;
        cout << "16. Remove an event" << endl;
        cout << endl;
        cout << "17. Add message" << endl;
        cout << "18. List messages of user" << endl;
        cout << "19. List messages of 2 users" << endl;
        cout << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Enter option: ";
        cin >> command;


        switch (command) {
        case 1:
            userDetails();
            break;
        case 2:
            listUsers();
            break;
        case 3:
            addUser();
            break;
        case 4:
            modifyUser();
            break;
        case 5:
            deleteUser();
            break;
        case 6:
            eventDetails();
            break;
        case 7:
            listEvents();
            break;
        case 8:
            addEvent();
            break;
        case 9:
            updateEvent();
            break;
        case 10:
            deleteEvent();
            break;
        case 11:
            addFriendship();
            break;
        case 12:
            removeFriendship();
            break;
        case 13:
            listFriends();
            break;
        case 14:
            listCommonFriends();
            break;
        case 15:
            signUpForEven();
            break;
        case 16:
            removeAnEvent();
            break;
        case 17:
            addMessage();
            break;
        case 18:
            messagesOfUser();
            break;
        case 19:
            messagesBetweenUsers();
            break;
        case 0:
            return;
        default:
            cout << "Invalid option. Try again." << endl;
        }

        cin.ignore();



    }
}

void UserInterface::userDetails() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    User* user = network.findUser(username);
    if (user == nullptr) {
        cout << "User not found." << endl;
        return;
    }

    cout << *user << endl;
}

void UserInterface::listUsers() {
    auto vecOfUsers = network.getUsers().getAll();

        cout << "Users:" << endl;
    for (auto& users : vecOfUsers) {
        cout <<"Username: "<< users->getUsername() <<endl;
        cout<<"First name: "<< users->getFirstName() << endl;
        cout<<"Last name: "<< users->getLastName()<< endl;
        cout<<endl;
    }
    cout<<endl;
}

void UserInterface::addUser() {
    cin.ignore();

    User* user = new User();
    cin >> *user;

    network.addUser(user);

    cout << "User added." << endl;
}

void UserInterface::modifyUser() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        cout << "User not found" <<endl;

    }
    else{
    User new_user;
        cin >> new_user;

    network.modifyUser(user, new_user);

    cout << "User updated." << endl;}
}

void UserInterface::deleteUser() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        cout << "User not found" << endl;

    }
    else{
    network.removeUser(user);

    cout << "User deleted." << endl;}
}

void UserInterface::eventDetails() {
    string event_name;
    cout << "Enter event name: ";
    cin >> event_name;

    Event* event = network.findEvent(event_name);
    if (event == nullptr) {
        cout << "Event not found." << endl;

    }
    else
        cout << *event << endl;
}

void UserInterface::listEvents() {
    auto vecOfEvents = network.getEvents().getAll();

    cout << "Events:" << endl;
    for (auto& event : vecOfEvents) {
        cout << event->getName() << endl;
    }
}

void UserInterface::addEvent() {
    Event* event = new Event();
    cin >> *event;

    network.addEvent(event);
    cout << "Event added." << endl;
}

void UserInterface::updateEvent() {
    string event_name;
    cout << "Enter event name: ";
    cin >> event_name;

    Event* event = network.findEvent(event_name);

    if (event == nullptr) {
        cout << "Event not found" << endl;

    }
    else {
        Event new_event;
        cin >> new_event;

        network.updateEvent(event, new_event);

        cout << "Event updated." << endl;
    }
}

void UserInterface::deleteEvent() {
    string event_name;
    cout << "Enter event name: ";
    cin >> event_name;

    Event* event = network.findEvent(event_name);

    if (event == nullptr) {
        cout << "Event not found" << endl;

    }
    else {
        network.removeEvent(event);

        cout << "Event deleted." << endl;
    }
}

void UserInterface::addFriendship() {
    string username1;
    string username2;
    cout << "Enter username 1: ";
    cin >> username1;
    cout << "Enter username 2: ";
    cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr and user2 == nullptr) {
        cout << "User not found" << endl;

    }
    else
    {   network.addFriendship(user1, user2);
        cout << "Friendship added." << endl;}
}

void UserInterface::removeFriendship() {
    string username1;
    string username2;
    cout << "Enter username 1: ";
    cin >> username1;
    cout << "Enter username 2: ";
    cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr || user2 == nullptr) {
        std::cout << "User not found" << std::endl;

    }
    else{
    network.removeFriendship(user1, user2);

    cout << "Friendship removed." << endl;}
}

void UserInterface::listFriends() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        cout << "User not found" << endl;

    }
    else {
        auto vecOfFriends = network.getFriends().get(user);

       cout << "Friends of " << user->getUsername() << ":" << endl;
        for (auto &friends: vecOfFriends) {
            cout << friends->getUsername() << endl;
        }
    }
}

void UserInterface::listCommonFriends() {
    string username1;
    string username2;
    cout << "Enter username 1: ";
    cin >> username1;
    cout << "Enter username 2: ";
    cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr and user2 == nullptr) {
        cout << "User not found" << endl;
        return;
    }
    else {
        auto vecOfFriends = network.getCommonFriends(user1, user2);

        cout << "Common friends of " << user1->getUsername() << " and " << user2->getUsername() << ":" << endl;
        for (auto &friends: vecOfFriends) {
            cout << friends->getUsername() << endl;
        }
    }
}

void UserInterface::signUpForEven() {
    string event_name;
    string username;
    cout << "Enter event name: ";
    cin >> event_name;
    cout << "Enter username: ";
    cin >> username;

    Event* event = network.findEvent(event_name);
    User* user = network.findUser(username);

    if (event == nullptr and user == nullptr) {
       cout << "Event or user not found" << endl;
        return;
    }
    else {
        network.signUpForEven(user, event);

        cout << "Attendance added." << endl;
    }
}

void UserInterface::removeAnEvent() {
    string event_name;
    string username;
    cout << "Enter event name: ";
    cin >> event_name;
    cout << "Enter username: ";
    cin >> username;

    Event* event = network.findEvent(event_name);
    User* user = network.findUser(username);

    if (event == nullptr || user == nullptr) {
        cout << "Event or user not found" <<endl;
        return;
    }

    network.removeAttendance(user, event);

    cout << "Attendance removed." << endl;
}

void UserInterface::addMessage() {
    string sender_username;
    string receiver_username;
    string message;
    cout << "Enter sender username: ";
    cin >> sender_username;
    cout << "Enter receiver username: ";
    cin >> receiver_username;
    cout << "Enter message: ";
    cin >> message;

    User* sender = network.findUser(sender_username);
    User* receiver = network.findUser(receiver_username);

    if (sender == nullptr || receiver == nullptr) {
        cout << "User not found" << endl;
        return;
    }

    network.addMessage(Message(message, sender, receiver));

    cout << "Message sent." << endl;
}

void UserInterface::messagesOfUser() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    User* user = network.findUser(username);

    if (user == nullptr) {
        cout << "User not found" << endl;
        return;
    }

    auto messages = network.getMessages(user);

    cout << "Messages of " << user->getUsername() << ":" << endl;
    for (auto& message : messages) {
        cout << message.getSender()->getUsername() << " -> " << message.getReceiver()->getUsername() << ": " << message.getText() << endl;
    }
}

void UserInterface::messagesBetweenUsers() {
    string username1;
    string username2;
    cout << "Enter username 1: ";
    cin >> username1;
    cout << "Enter username 2: ";
    cin >> username2;

    User* user1 = network.findUser(username1);
    User* user2 = network.findUser(username2);

    if (user1 == nullptr || user2 == nullptr) {
        cout << "User not found" << endl;
        return;
    }

    auto messages = network.getMessages(user1, user2);

    cout << "Messages between " << user1->getUsername() << " and " << user2->getUsername() << ":" << endl;
    for (auto& message : messages) {
        cout << message.getSender()->getUsername() << " -> " << message.getReceiver()->getUsername() << ": " << message.getText() << endl;
    }
}

