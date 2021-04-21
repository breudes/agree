#ifndef SERVER_H_
#define SERVER_H_

#include "../src/voice_channel.cpp"

#include <vector>
#include <string>
#include <iostream>

/*
    * This class is a server class, i.e., similar to a Discord's server it has a name, description,
    * owner, members, an invite code and multiple channels.
*/
class Server{
    private:
        int ownerId;
        std::string name;
        std::string description;
        std::string inviteCode;
        std::vector<Channel*> channels;
        std::vector<int> membersId;
    public:
        //Constructors and Destructor
        Server();
        ~Server();
        //Getters and Setters
        int getServerOwnerId() const;
        std::string getServerName() const;
        std::string getServerDescription() const;
        std::string getServerInviteCode() const;
        std::vector<Channel*> getServerChannels();
        std::vector<int> getServerMembersId() const;
        int getServerOneMemberId(int member_id) const;
        void setServerOwnerId(int new_id);
        void setServerName(std::string new_name);
        void setServerDescription(std::string new_description);
        void setServerInviteCode(std::string new_code);
        void setServerChannels(std::vector<Channel*> new_channels);
        void setServerMembersId(std::vector<int> new_members);
        void setServerOneMemberId(int member_id);
        //Methods
        void displayAllChannels();
        int checkChannelExists(std::string name, std::string type);
        void addChannel(Channel* new_channel);
};
#endif