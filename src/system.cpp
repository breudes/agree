#include "./user.cpp"

System::System(){
    this.currentServerName = "";
    this.currentChannelName = "";
}
System::~System(){
    delete this.users;
    delete this.servers;
    this.currentServerName.clear();
    this.currentServerName.clear();
}
std::vector<User> System::getSystemUsers() const{
    return this.users;
}
std::vector<Server> System::getSystemServers() const{
    return this.servers;
}
int System::getSystemUserLoggedId() const{
    return this.userLoggedId;
}
std::string System::getSystemCurrentName() const{
    return this.currentServerName;
}
std::string System::getSystemChannelCurrentName() const{
    return this.currentChannelName;
}
void System::setSystemUsers(std::vector<User> new_users){
    this.users = new_users;
}
void System::setSystemServers(std::vector<Server> new_servers){
    this.servers = new_servers;
}
void System::setSystemUserLoggedId(int new_user_logged){
    this.userLoggedId = new_user_logged;
}
void System::setSystemCurrentName(std::string server_name){
    this.currentServerName = server_name;
}
void System::setSystemCurrentChannelName(std::string channel_name){
    this.currentChannelName = channel_name;
}
int System::searchUserById(int id){
    for(auto users_index = this.getSystemUsers.cbegin(); users_index!=this.getSystemUsers.cend(); ++users_index){
        if((*users_index).getUserId() == id) return 1;
    }
    return 0;
}
int System::searchUserByEmail(std::string email){
    for(auto users_index = this.getSystemUsers.cbegin(); users_index!=this.getSystemUsers.cend(); ++users_index){
        if((*users_index).getUserEmail() == email) return 1;
    }
    return 0;
}
User System::searchUserByPassword(std::string password){
    for(auto users_index = this.getSystemUsers.cbegin(); users_index!=this.getSystemUsers.cend(); ++users_index){
        if((*users_index).getUserPassword() == password) return *users_index;
    }
    return NULL;
}
void System::quit(){
    std::cout << "You're logging off from Agree System. Goodbye!" << std::endl;
}
void System::createUser(User user){
    int searchUserEmail = searchUserByEmail(user.getUserEmail());
    if(searchUserEmail == 0){ 
        this.users.push_back(user);
        std::cout << "Created user!" << std::endl;
    } else std::cout << "User already exists!" << std::endl;
}
void System::login(std::string email, std::string password){
    int searchUserEmail = searchUserByEmail(user.getUserEmail());
    if(searchUserEmail == 1){ 
        User searchUserPassword = searchUserByPassword(password);
        if(searchUserPassword){
            this.setSystemUserLoggedId(searchUserPassword.getUserId());
            std::cout << "You're now logged on Agree System!" << std::endl;
        }else std::cout << "Invalid user's password!" << std::endl;
    } else std::cout << "User not found!" << std::endl;
}
//https://docs.google.com/document/d/1lBBdA6Hdg3IDH9xSCHmpHtqbK29lceFGFbUKv6c7BNQ/edit