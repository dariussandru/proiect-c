#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
private:

    std::string username;
    std::string password;
    std::string email;
    std::string firstName;
    std::string lastName;

public:
    User();
    User(std::string  username, std::string& password, std::string  email, const std::string& firstName, const std::string& lastName);
    User(const User& other);
    ~User();

    std::string getUsername();
    std::string getPassword();
    std::string getEmail();
    std::string getFirstName();
    std::string getLastName();

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setEmail(const std::string& email);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);

	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);

	friend std::ostream& loadUserIntoCSV(std::ostream& os, const User& user);
	friend std::istream& loadUserFromCSV(std::istream& is, User& user);

	bool operator==(const User& other) const;
};


#endif // USER_H
