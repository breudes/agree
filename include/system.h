#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "../src/user.cpp"
#include "../src/server.cpp"

#include <vector>
#include <string>
#include <iostream>

class System{
    public:
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
        int searchServerByName(std::string name);
        const User getUserById(int id);
        const User getUserByPassword(std::string password);
        Server* getServerByName(std::string name);
        //Commands
        void quit();
        void createUser(User new_user);
        void login(std::string email, std::string password);
        void disconnect();
        void createServer(std::string server_name);
        void updateServerDescription(std::string server_name, std::string new_server_description);
        void updateServerInvite(std::string server_name, std::string invite);
        void listServers();
};
#endif