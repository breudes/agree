#include "../include/system.h"

System::System(){
    this->userLoggedId = 0;
    this->currentServerName = "";
    this->currentChannelName = "";
}
System::~System(){
    this->currentServerName.clear();
    this->currentServerName.clear();
}
std::vector<User> System::getSystemUsers() const{
    return this->users;
}
std::vector<Server> System::getSystemServers() const{
    return this->servers;
}
int System::getSystemUserLoggedId() const{
    return this->userLoggedId;
}
std::string System::getSystemCurrentName() const{
    return this->currentServerName;
}
std::string System::getSystemChannelCurrentName() const{
    return this->currentChannelName;
}
void System::setSystemUsers(std::vector<User> new_users){
    this->users = new_users;
}
void System::setSystemServers(std::vector<Server> new_servers){
    this->servers = new_servers;
}
void System::setSystemUserLoggedId(int new_user_logged){
    this->userLoggedId = new_user_logged;
}
void System::setSystemCurrentName(std::string server_name){
    this->currentServerName = server_name;
}
void System::setSystemCurrentChannelName(std::string channel_name){
    this->currentChannelName = channel_name;
}
int System::searchUserById(int id){
    std::vector<User> users_list = this->getSystemUsers();
    for(int i=0; i<users_list.size(); i++){
        if(users_list[i].getUserId() == id) return 1;
    }
    return 0;
}
int System::searchUserByEmail(std::string email){
    std::vector<User> users_list = this->getSystemUsers();
    for(int i=0; i<users_list.size(); i++){
        if(users_list[i].getUserEmail() == email) return 1;
    }
    return 0;
}
int System::searchServerByName(std::string name){
    std::vector<Server> servers_list = this->getSystemServers();
    for(int i=0; i<servers_list.size(); i++){
        if(servers_list[i].getServerName() == name) return 1;
    }
    return 0;
}
const User System::getUserById(int id){
    std::vector<User> users_list = this->getSystemUsers();
    for(int i=0; i<users_list.size(); i++){
        if(users_list[i].getUserId() == id) return users_list[i];
    }
    return users_list[0];
}
const User System::getUserByPassword(std::string password){
    std::vector<User> users_list = this->getSystemUsers();
    for(int i=0; i<users_list.size(); i++){
        if(users_list[i].getUserPassword() == password) return users_list[i];
    }
    return users_list[0];
}

Server* System::getServerByName(std::string name){
    for(int i=0; i<this->getSystemServers().size(); i++){
        if(this->getSystemServers()[i].getServerName() == name) return &this->getSystemServers()[i];
    }
    return &this->getSystemServers()[0];
}
void System::quit(){
    std::cout << "You're logging off from Agree System. Goodbye!\n" << std::endl;
}
void System::createUser(User user){
    int searchUserEmail = this->searchUserByEmail(user.getUserEmail());
    if(searchUserEmail == 0){ 
        this->users.push_back(user);
        std::cout << "Created user!\n" << std::endl;
    } else std::cout << "User already exists!\n" << std::endl;
}
void System::login(std::string email, std::string password){
    int searchUserEmail = this->searchUserByEmail(email);
    if(searchUserEmail == 1){ 
        const User searchUserPassword = getUserByPassword(password);
        if(searchUserPassword.getUserPassword()==password){
            this->setSystemUserLoggedId(searchUserPassword.getUserId());
            std::cout << "You're now logged as '" << email << "' on Agree System!\n" << std::endl;
        }else std::cout << "Invalid user's password!\n" << std::endl;
    } else std::cout << "User not found. You can try again!\n" << std::endl;
}
void System::disconnect(){
    std::cout << "Disconnecting user " << this->getUserById(this->getSystemUserLoggedId()).getUserEmail() << "\n\n";
    this->setSystemUserLoggedId(0);
    std::cout << "User is logging off but Agree System is still on!\n" << std::endl;
}
void System::createServer(std::string server_name){
    int searchServerName = this->searchServerByName(server_name);
    if(searchServerName == 0){
        Server new_server;
        new_server.setServerName(server_name);
        new_server.setServerOwnerId(this->getSystemUserLoggedId());
        new_server.setServerOneMemberId(this->getSystemUserLoggedId());
        this->servers.push_back(new_server);
        std::cout << "Created server!\n" << std::endl;
    } else std::cout << "Server already exists with this name!\n" << std::endl;
}
void System::updateServerDescription(std::string server_name, std::string new_server_description){
    int searchServerName = this->searchServerByName(server_name);
    if(searchServerName == 1){
        this->getServerByName(server_name)->setServerDescription(new_server_description);
        std::cout << "Modified '" << server_name << "' server description!\n" << std::endl;
    } else std::cout << "Server not found! You can try again!\n" << std::endl;
}
void System::updateServerInvite(std::string server_name, std::string invite){
    int searchServerName = this->searchServerByName(server_name);
    if(searchServerName == 1){
        this->getServerByName(server_name)->setServerInviteCode(invite);
        std::cout << "Set '" << server_name << "' server invite code!\n" << std::endl;
    } else std::cout << "Server not found! You can try again!\n" << std::endl;
}
void System::listServers(){
    std::vector<Server> servers_list = this->getSystemServers();
    std::cout << "List of all servers on Agree System: " << std::endl;
    for(int i=0; i<servers_list.size(); i++){
        std::cout << "\n-----------------------------------------------" << std::endl;
        std::cout << "Server name: " << servers_list[i].getServerName() << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Server description: " << servers_list[i].getServerDescription() << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        if(servers_list[i].getServerInviteCode()==""){
            std::cout << "This is an open server. Everyone can enter!" << std::endl;
        }else std::cout << "This is a closed server. You need an invite code to enter!" << std::endl;
        std::cout << "-----------------------------------------------\n" << std::endl;
    }
}