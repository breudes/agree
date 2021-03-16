#include "../include/server.h"

Server::Server(){
    this->ownerId = 0;
    this->name = "";
    this->description = "";
    this->inviteCode = "";
}
Server::~Server(){
    this->name.clear();
    this->description.clear();
    this->inviteCode.clear();
}
int Server::getServerOwnerId() const{
    return this->ownerId;
}
std::string Server::getServerName() const{
    return this->name;
}
std::string Server::getServerDescription() const{
    return this->description;
}
std::string Server::getServerInviteCode() const{
    return this->inviteCode;
}
std::vector<Channel> Server::getServerChannels() const{
    return this->channels;
}
std::vector<int> Server::getServerMembersId() const{
    return this->membersId;
}
void Server::setServerOwnerId(int new_id){
    this->ownerId = new_id;
}
void Server::setServerName(std::string new_name){
    this->name = new_name;
}
void Server::setServerDescription(std::string new_description){
    this->description = new_description;
}
void Server::setServerInviteCode(std::string new_code){
    this->inviteCode = new_code;
}
void Server::setServerChannels(std::vector<Channel> new_channels){
    this->channels = new_channels;
}
void Server::setServerMembersId(std::vector<int> new_members){
    this->membersId = new_members;
}
void Server::setServerOneMemberId(int member_id){
    this->membersId.push_back(member_id);
}