#include "User.h"
#include "iostream"
using namespace std;

#include "User.h"

#include <utility>


User::User()
        : username(""),
          password(""),
          email(""),
          firstName(""),
          lastName("")
{
}

User::User(std::string  username, std::string& password, std::string  email, const std::string& firstName, const std::string& lastName)
{
    this->username = username;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
}

User::User(const User& other)
        : username(other.username),
          password(other.password),
          email(other.email),
          firstName(other.firstName),
          lastName(other.lastName)
{
}

User::~User()
{
}

std::string User::getUsername()
{
    return username;
}

std::string User::getPassword()
{
    return password;
}

std::string User::getEmail()
{
    return email;
}

std::string User::getFirstName()
{
    return firstName;
}

std::string User::getLastName()
{
    return lastName;
}

void User::setUsername(const std::string& username)
{
    this->username = username;
}

void User::setPassword(const std::string& password)
{
    this->password = password;
}

void User::setEmail(const std::string& email)
{
    this->email = email;
}

void User::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void User::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

bool User::operator==(const User& other) const {
    return username == other.username;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Nume de utilizator: " << user.username << std::endl;
    os << "Parola: " << user.password << std::endl;
    os << "Email: " << user.email << std::endl;
    os << "Prenume: " << user.firstName << std::endl;
    os << "Nume: " << user.lastName << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, User& user) {
    std::string username;
    std::string password;
    std::string email;
    std::string firstName;
    std::string lastName;

    std::cout << "Nume de utilizator: ";
    is >> username;

    std::cout << "Parola: ";
    is >> password;

    std::cout << "Email: ";
    is >> email;

    std::cout << "Prenume: ";
    is >> firstName;

    std::cout << "Nume: ";
    is >> lastName;

    user.username = username;
    user.password = password;
    user.email = email;
    user.firstName = firstName;
    user.lastName = lastName;

    return is;
}



std::ostream& loadUserIntoCSV(std::ostream& os, const User& user) {
    os << user.username << ",";
    os << user.password << ",";
    os << user.email << ",";
    os << user.firstName << ",";
    os << user.lastName << "\n";
    return os;

}

std::istream& loadUserFromCSV(std::istream& is, User& user) {
    std::string username;
    std::string password;
    std::string email;
    std::string firstName;
    std::string lastName;
    std::string bio;
    std::string profilePicture;

    std::getline(is, username, ',');
    std::getline(is, password, ',');
    std::getline(is, email, ',');
    std::getline(is, firstName, ',');
    std::getline(is, lastName, ',');
    std::getline(is, bio, ',');
    std::getline(is, profilePicture, '\n');

    user.username = username;
    user.password = password;
    user.email = email;
    user.firstName = firstName;
    user.lastName = lastName;

    return is;
}