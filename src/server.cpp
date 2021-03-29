#include "../include/server.h"

//Constructor
Server::Server(){
    /**
        * Default constructor for Server Class. Enters null values for all properties, except for the vectors one,
        * considering the a vector inits and ends by itself;
    */
    this->ownerId = 0;
    this->name = "";
    this->description = "";
    this->inviteCode = "";
}
//Destructor
Server::~Server(){
    /**
        * Default destructor for Server Class. Ends, i.e., clear all string properties.
        * Considering the a vector ends by itself, is not required to use delete on it.
    */
    this->name.clear();
    this->description.clear();
    this->inviteCode.clear();
}
//Get Server Owner Id
int Server::getServerOwnerId() const{
    /** Returns this server's owner id.
        @return: the server owner id.
    */
    return this->ownerId;
}
//Get Server Name
std::string Server::getServerName() const{
    /** Returns this server's name.
        @return: the server name.
    */
    return this->name;
}
//Get Server Description
std::string Server::getServerDescription() const{
    /** Returns this server's description.
        @return: the server description.
    */
    return this->description;
}
//Get Server Invite Code
std::string Server::getServerInviteCode() const{
    /** Returns this server's invite code.
        @return: the server invite code.
    */
    return this->inviteCode;
}
//Get Server Channels Vector
std::vector<Channel> Server::getServerChannels() const{
    /** Returns this server's channels vector.
        @return: the server vector of channels.
    */
    return this->channels;
}
//Get Server Members Vector
std::vector<int> Server::getServerMembersId() const{
    /** Returns this server's members vector.
        @return: the server vector of members.
    */
    return this->membersId;
}
//Get Server One Member Id
int Server::getServerOneMemberId(int member_id) const{
    /** Returns 1 (one) if a given member's id is on this server's members vector, otherwise, returns 0 (zero).
        @return: integer value.
    */
    for(size_t i=0; i<this->membersId.size(); i++){
        if(this->membersId[i]==member_id) return 1;
    }
    return 0;
}
//Set Server Owner Id
void Server::setServerOwnerId(int new_id){
    /** Set a new owner id for this server.
        @param new_id: integer value of new id.
    */
    this->ownerId = new_id;
}
//Set Server Name
void Server::setServerName(std::string new_name){
    /** Set a new name for this server.
        @param new_name: string value of new name.
    */
    this->name = new_name;
}
//Set Server Description
void Server::setServerDescription(std::string new_description){
    /** Set a new description for this server.
        @param new_description: string value of new description.
    */
    this->description = new_description;
}
//Set Server Invite Code
void Server::setServerInviteCode(std::string new_code){
    /** Set a new invite code for this server.
        @param new_code: string value of new invite code.
    */
    this->inviteCode = new_code;
}
//Set Server Channels
void Server::setServerChannels(std::vector<Channel> new_channels){
    /** Set a new channels vector for this server.
        @param new_channels: channel vector of new channels.
    */
    this->channels = new_channels;
}
//Set Server Members
void Server::setServerMembersId(std::vector<int> new_members){
    /** Set a new members vector for this server.
        @param new_members: int vector of new members.
    */
    this->membersId = new_members;
}
//Set Server One Member Id
void Server::setServerOneMemberId(int member_id){
    /** Set a new member, on members vector, for this server.
        @param member_id: int value of new member.
    */
    this->membersId.push_back(member_id);
}