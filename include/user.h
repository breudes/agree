#ifndef USER_H_
#define USER_H_

#include <string>
#include <iostream>

class User{
    private:
        int id;
        std::string name;
        std::string email;
        std::string password;
    public:
        //Constructors and Destructor
        User();
        User(std::string name, std::string email, std::string password);
        ~User();
        //Getters and Setters
        int getUserId() const;
        std::string getUserName() const;
        std::string getUserEmail() const;
        std::string getUserPassword() const;
        void setUserId(int new_id);
        void setUserName(std::string new_name);
        void setUserEmail(std::string new_email);
        void setUserPassword(std::string new_password);
};
#endif