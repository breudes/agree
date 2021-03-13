#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <vector>
#include <string>
#include <iostream>

class System{
    private:
        std::vector<User> users;
        std::vector<Server> servers;
        int userLoggedId;
        std::string currentServerName;
        std::string currentChannelName;
    public:
        //Constructors and Destructor
        System();
        ~System();
        //Getters and Setters
        std::vector<User> getSystemUsers() const;
        std::vector<Server> getSystemServers() const;
        int getSystemUserLoggedId() const;
        std::string getSystemCurrentName() const;
        std::string getSystemChannelCurrentName() const;
        void setSystemUsers(std::vector<User> new_users);
        void setSystemServers(std::vector<Server> new_servers);
        void setSystemUserLoggedId(int new_user_logged);
        void setSystemCurrentName(std::string server_name);
        void setSystemCurrentChannelName(std::string channel_name);
        //Search methods
        int searchUserById(int id);
        int searchUserByEmail(std::string email);
        User searchUserByPassword(std::string password);
        //Commands
        void quit();
        void createUser(User new_user);
        void login(std::string email, std::string password);
}
#endif