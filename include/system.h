#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "../src/user.cpp"
#include "../src/server.cpp"

#include <iostream>
#include <sstream>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>    
#include <chrono>  
#include <time.h>
#include <fstream>
/*
    * This class is a system class similar to the application called as Discord.
    * Which means: it has users, servers, one user logged's id, current active server and its channel. 
*/
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
        std::vector<User> getSystemUsers();
        std::vector<Server> getSystemServers();
        int getSystemUserLoggedId() const;
        std::string getSystemServerCurrentName() const;
        std::string getSystemChannelCurrentName() const;
        void setSystemUsers(std::vector<User> new_users);
        void setSystemServers(std::vector<Server> new_servers);
        void setSystemUserLoggedId(int new_user_logged);
        void setSystemCurrentServerName(std::string server_name);
        void setSystemCurrentChannelName(std::string channel_name);
        //Search methods
        int searchUserById(int id);
        int searchUserByEmail(std::string email);
        int searchServerByName(std::string name);
        const User getUserById(int id);
        const User getUserByPassword(std::string password);
        Server* getServerByName(std::string name);
        const Server returnServerByName(std::string server_name);
        //Update methods
        int updatesServerDescription(std::string server_name, std::string description);
        int updatesServerInviteCode(std::string server_name, std::string invite_code);
        //Remove methods
        int removesServer(std::string server_name);
        //Enter methods
        int entersServer(std::string server_name, std::string invite_code);
        //Commands
        void quit();
        void createUser(User new_user);
        void login(std::string email, std::string password);
        void disconnect();
        void createServer(std::string server_name);
        void updateServerDescription(std::string server_name, std::string new_server_description);
        void updateServerInvite(std::string server_name, std::string invite);
        void listServers();
        void removeServer(std::string server_name);
        void enterServer(std::string server_name, std::string invite_code);
        void leaveServer();
        void listServerMembers();
        void listServerChannels();
        void createServerChannel(std::string name, std::string type);
        void enterServerChannel(std::string name);
        void leaveServerChannel();
        void sendMessage(std::string content);
        void displayAllMessages();
        void save(std::string option);
        void load();
    private:
        void saveUsers();
        void saveServers();
        void loadUsers();
        void loadServers();
};
#endif