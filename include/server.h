#ifndef SERVER_H_
#define SERVER_H_

#include <vector>
#include <string>
#include <iostream>

class Server{
    private:
        int ownerId;
        std::string name;
        std::string description;
        std::string inviteCode;
        std::vector<Channel> channels;
        std::vector<int> membersId;
    public:
        //Constructors and Destructor
        Server();
        ~Server();
        //Getters and Setters
}
#endif