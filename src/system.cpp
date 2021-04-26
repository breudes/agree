#include "../include/system.h"

//Constructor
System::System(){
    /** Default constructor of system. Enters all properties's values as null. The vectors doesn't require to be
      * initialized.
    */
    this->userLoggedId = 0;
    this->currentServerName = "";
    this->currentChannelName = "";
}
//Destructor
System::~System(){
    /** Default destructor of system. Clears all string properties. The vectors doesn't require to be
      * deleted.
    */
    this->currentServerName.clear();
    this->currentServerName.clear();
}
//Get System Users
std::vector<User> System::getSystemUsers(){
    /** Returns this system users.
        @return: an int vector.
    */
    return this->users;
}
//Get System Servers
std::vector<Server> System::getSystemServers(){
    /** Returns this system servers.
        @return: an server vector.
    */
    return this->servers;
}
//Get System User Logged Id
int System::getSystemUserLoggedId() const{
    /** Returns this system an id of the current user logged.
        @return: an int value.
    */
    return this->userLoggedId;
}
//Get System Current Server Name
std::string System::getSystemServerCurrentName() const{
    /** Returns this system a name of the current active server.
        @return: a string value.
    */
    return this->currentServerName;
}
//Get System Current Channel Name
std::string System::getSystemChannelCurrentName() const{
    /** Returns this system a name of the current active channel.
        @return: a string value.
    */
    return this->currentChannelName;
}
//Set System Users
void System::setSystemUsers(std::vector<User> new_users){
    /** Set a new int vector, with users's id, for this system's users.
        @param new_users: int vector.
    */
    this->users = new_users;
}
//Set System Servers
void System::setSystemServers(std::vector<Server> new_servers){
    /** Set a new server vector for this system's servers.
        @param new_servers: server vector.
    */
    this->servers = new_servers;
}
//Set System User Logged Id
void System::setSystemUserLoggedId(int new_user_logged){
    /** Set a new user logged for this system's (active) current user.
        @param new_user_logged: int value of new user logged's id.
    */
    this->userLoggedId = new_user_logged;
}
//Set System Current Server Name
void System::setSystemCurrentServerName(std::string server_name){
    /** Set a new server name for this system's (active) current server.
        @param server_name: string value of new current server's name.
    */
    this->currentServerName = server_name;
}
//Set System Current Channel Name
void System::setSystemCurrentChannelName(std::string channel_name){
    /** Set a new channel name for this system's (active) current channel.
        @param channel_name: string value of new current channel's name.
    */
    this->currentChannelName = channel_name;
}
//Search User By Id
int System::searchUserById(int id){
    /** Returns 1 (one) if one user matches a given id. Otherwise, returns 0 (zero). Search on all users of Agree System.
        @param id: int value of a given user's id;
        @return: int value to return if this command was successful.
    */
    std::vector<User> users_list = this->getSystemUsers();
    for(size_t i=0; i<users_list.size(); i++){
        if(users_list[i].getUserId() == id) return 1;
    }
    return 0;
}
//Search User By Email
int System::searchUserByEmail(std::string email){
    /** Returns 1 (one) if one user matches a given email. Otherwise, returns 0 (zero). Search on all users of Agree System.
        @param email: string value of a given user's email;
        @return: int value to return if this command was successful.
    */
    std::vector<User> users_list = this->getSystemUsers();
    for(size_t i=0; i<users_list.size(); i++){
        if(users_list[i].getUserEmail() == email) return 1;
    }
    return 0;
}
//Search Server By Name
int System::searchServerByName(std::string name){
    /** Returns 1 (one) if one server matches a given name. Otherwise, returns 0 (zero). Search on all servers of Agree System.
        @param name: string value of a given server's name;
        @return: int value to return if this command was successful.
    */
    std::vector<Server> servers_list = this->getSystemServers();
    for(size_t i=0; i<servers_list.size(); i++){
        if(servers_list[i].getServerName() == name) return 1;
    }
    return 0;
}
//Get User By Id
const User System::getUserById(int id){
    /** Returns an user object if user's id matches the given id. Otherwise, will return the first element
      * of users's vector (on Agree System).
        @param id: int value of a given id;
        @return: a const user object.
    */
    std::vector<User> users_list = this->getSystemUsers();
    for(size_t i=0; i<users_list.size(); i++){
        if(users_list[i].getUserId() == id) return users_list[i];
    }
    return users_list[0];
}
//Get User By Password
const User System::getUserByPassword(std::string password){
    /** Returns an user object if user's password matches the given password. Otherwise, will return the first element
      * of users's vector (on Agree System).
        @param password: string value of a given password;
        @return: a const user object.
    */
    std::vector<User> users_list = this->getSystemUsers();
    for(size_t i=0; i<users_list.size(); i++){
        if(users_list[i].getUserPassword() == password) return users_list[i];
    }
    return users_list[0];
}
//Updates Server Description
int System::updatesServerDescription(std::string server_name, std::string description){
    /** Updates a given server's description. This is only possible if the current logged user is also the owner of
      * this given server.
      @param server_name: string value of a given server's name;
      @param description: string value of a given server's new description;
      @return: int value to return if this command was successful.
    */
    for(size_t i=0; i<this->getSystemServers().size(); i++){
        if(this->getSystemServers()[i].getServerName() == server_name){
            if(this->getSystemServers()[i].getServerOwnerId()==this->getSystemUserLoggedId()){
                this->servers[i].setServerDescription(description);
                return 1;
            }else{
                std::cout << "You cannot change another user's server description!\n" << std::endl;
                return 0;
            }
        } 
    }
    return 0;
}
//Updates Server Invite Code
int System::updatesServerInviteCode(std::string server_name, std::string invite_code){
    /** Updates a given server's invite code. This is only possible if the current logged user is also the owner of
      * this given server.
      @param server_name: string value of a given server's name;
      @param invite_code: string value of a given server's new invite code;
      @return: int value to return if this command was successful.
    */
    for(size_t i=0; i<this->getSystemServers().size(); i++){
        if(this->getSystemServers()[i].getServerName() == server_name){
            if(this->getSystemServers()[i].getServerOwnerId()==this->getSystemUserLoggedId()){
                this->servers[i].setServerInviteCode(invite_code);
                if(invite_code==""){
                    std::cout << "Removed '" << server_name << "' server invitation code!\n" << std::endl;
                }else std::cout << "Modified '" << server_name << "' server invitation code!\n" << std::endl;
                return 1;
            }else{
                std::cout << "You cannot change another user's server invite code!\n" << std::endl;
                return 0;
            }
        } 
    }
    return 0;
}
//Removes Server
int System::removesServer(std::string server_name){
    /** Removes a given server using its name. This is only possible if the current logged user is also the owner of
      * this given server.
      @param server_name: string value of a given server's name;
      @return: int value to return if this command was successful.
    */
    for(auto index=this->servers.begin(); index!=this->servers.end(); ++index){
        if((*index).getServerName() == server_name){
            if((*index).getServerOwnerId()==this->getSystemUserLoggedId()){
                this->servers.erase(index);
                this->setSystemCurrentServerName("");
                std::cout << "Removed '" << server_name << "' server!\n" << std::endl;
                return 1;
            }else{
                std::cout << "You are not the owner of the '" << server_name << "' server!\n" << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
//Enters Server
int System::entersServer(std::string server_name, std::string invite_code){
    /** The current logged user on Agree System will enter a server, by using its name and invite code.
        @param server_name: string value of chosen server's name;
        @param invite_code: string value of chosen server's invite code;
        @return: int value to return if this command was successful.
    */
    for(size_t i=0; i<this->getSystemServers().size(); i++){
        if(this->getSystemServers()[i].getServerName() == server_name){
            if(this->getSystemServers()[i].getServerInviteCode()==""){
                int result = 0; 
                result = this->servers[i].getServerOneMemberId(this->getSystemUserLoggedId());
                std::cout << "This is an open server!" << std::endl;
                std::cout << "Entering '" << server_name << "' server!\n" << std::endl;
                if(result==1){
                    this->setSystemCurrentServerName(server_name);
                }else if(result==0){
                    this->servers[i].setServerOneMemberId(this->getSystemUserLoggedId());
                    this->setSystemCurrentServerName(server_name);
                }
                return 1;
            }else{
                std::cout << "This is a closed server. You need an invite code to enter!\n" << std::endl;
                if(this->getSystemServers()[i].getServerInviteCode()==invite_code){
                    int result = 0; 
                    result = this->servers[i].getServerOneMemberId(this->getSystemUserLoggedId());
                    std::cout << "Entering '" << server_name << "' server!\n" << std::endl;
                    if(result==1){
                        this->setSystemCurrentServerName(server_name);
                    }else if(result==0){
                        this->servers[i].setServerOneMemberId(this->getSystemUserLoggedId());
                        this->setSystemCurrentServerName(server_name);
                    }
                    return 1;
                }else std::cout << "Invalid invite code for this server. You can try again!\n" << std::endl;
            }
        } 
    }
    return 0;
}
//Return Server By Name
const Server System::returnServerByName(std::string server_name){
    /** Returns a server object if its name was equal to a giver string name. Otherwise, will return the first element of servers vector.
        @param server_name: string value of given name;
        @return: a const server's object.
    */
    for(size_t i=0; i<this->getSystemServers().size(); i++){
        if(this->getSystemServers()[i].getServerName() == server_name){
            return this->getSystemServers()[i];
        } 
    }
    return this->getSystemServers()[0];
}
//Quit
void System::quit(){
    /** This stops the execution of Agree System.
    */
    std::cout << "You're logging off from Agree System. Goodbye!\n" << std::endl;
}
//Create User
void System::createUser(User user){
    /** Creates a new user on Agree System, this user is not logged on system, only will be logged if press command login,
      * with all required info.
      @param user: an user class's object.
    */
    int searchUserEmail = this->searchUserByEmail(user.getUserEmail());
    if(searchUserEmail == 0){ 
        this->users.push_back(user);
        std::cout << "Created user!\n" << std::endl;
    } else std::cout << "User already exists!\n" << std::endl;
}
//Login
void System::login(std::string email, std::string password){
    /** Enters a user on Agree System by a given email and password. If this user exists, it'll now logged on Agree.
        @param email: string value of user's email;
        @param password: string value of user's password.
    */
    int searchUserEmail = this->searchUserByEmail(email);
    if(searchUserEmail == 1){ 
        const User searchUserPassword = getUserByPassword(password);
        if(searchUserPassword.getUserPassword()==password){
            this->setSystemUserLoggedId(searchUserPassword.getUserId());
            std::cout << "You're now logged as '" << email << "' on Agree System!\n" << std::endl;
        }else std::cout << "Invalid user's password!\n" << std::endl;
    } else std::cout << "User not found. You can try again!\n" << std::endl;
}
//Disconnect
void System::disconnect(){
    /** Disconnect the current user logged on Agree System.
    */
    if(this->getSystemUserLoggedId()!=0){
        std::cout << "Disconnecting user " << this->getUserById(this->getSystemUserLoggedId()).getUserEmail() << "\n";
        this->setSystemUserLoggedId(0);
    }else{
        std::cout << "Not connected!\n" << std::endl;
    }
    std::cout << "Note that Agree System is still on!\n" << std::endl;
}
//Create Server
void System::createServer(std::string server_name){
    /** Creates a new server, considering a given name. And this new server has the current logged user as its owner.
        @param server_name: string value of a given name.
    */
    int searchServerName = this->searchServerByName(server_name);
    if(this->getSystemUserLoggedId()!=0){
        if(searchServerName == 0){
        Server new_server;
        new_server.setServerName(server_name);
        new_server.setServerOwnerId(this->getSystemUserLoggedId());
        new_server.setServerOneMemberId(this->getSystemUserLoggedId());
        this->servers.push_back(new_server);
        std::cout << "Created server!\n" << std::endl;
        } else std::cout << "Server already exists with this name!\n" << std::endl;
    }else std::cout << "Enter with an user before create a server!" << std::endl;
}
//Update Server Description
void System::updateServerDescription(std::string server_name, std::string new_server_description){
    /** Updates a given server's description. Only if the logged user is also the owner of this server.
        @param server_name: a given server's name;
        @param new_server_description: a new description for given server.
    */
    if(this->getSystemUserLoggedId()!=0){
        int searchServerName = this->searchServerByName(server_name);
        if(searchServerName == 1){
            int result = this->updatesServerDescription(server_name,new_server_description);
            if(result==1) std::cout << "Modified '" << server_name << "' server description!\n" << std::endl;
        } else std::cout << "Server not found! You can try again!\n" << std::endl;
    }else std::cout << "Log with an user before create a server!" << std::endl;
}
//Update Server Invite
void System::updateServerInvite(std::string server_name, std::string invite){
    /** Updates a given server's invite code. Only if the logged user is also the owner of this server.
        @param server_name: a given server's name;
        @param invite: a new invite code for given server.
    */
    if(this->getSystemUserLoggedId()!=0){
        int searchServerName = this->searchServerByName(server_name);
        if(searchServerName == 1){
            this->updatesServerInviteCode(server_name,invite);
        } else std::cout << "Server not found! You can try again!\n" << std::endl;
    }else std::cout << "Log with an user before create a server!" << std::endl;
}
//List Servers
void System::listServers(){
    /** List all servers's name on Agree System.
    */
    std::vector<Server> servers_list = this->getSystemServers();
    std::cout << "List of all servers on Agree System: " << std::endl;
    for(size_t i=0; i<servers_list.size(); i++){
        std::cout << servers_list[i].getServerName() << std::endl;
    }
    std::cout << "\n";
}
//Remove Server
void System::removeServer(std::string server_name){
    /** The logged user removes a server, i.e., on Agree System the current active server is now empty.
        * This is only possible if the user is the owner of a given server, passed as input by its name.
        @param server_name: given server's name.
    */
    if(this->getSystemUserLoggedId()!=0){
        int searchServerName = this->searchServerByName(server_name);
        if(searchServerName == 1){
            this->removesServer(server_name);
        } else std::cout << "Server not found! You can try again!\n" << std::endl;
    }else std::cout << "You had to be logged on Agree System to remove a server of yours!" << std::endl;
}
//Enter Server
void System::enterServer(std::string server_name, std::string invite_code){
    /** The logged user enters a given server, i.e., on Agree System the current active server is now this server.
        * This is only possible if the user enters the server name and the invite code (if the server is a closed one).
        @param server_name: given server's name;
        @param invite_code: given server's invite code.
    */
    if(this->getSystemUserLoggedId()!=0){
        int searchServerName = this->searchServerByName(server_name);
        if(searchServerName == 1){
            this->entersServer(server_name, invite_code);
            this->setSystemCurrentServerName(server_name);
        } else std::cout << "Server not found! You can try again!\n" << std::endl;
    }else std::cout << "You had to be logged on Agree System to enter a server!" << std::endl;
}
//Leave Server
void System::leaveServer(){
    /** The logged user leaves a server, i.e., on Agree System the current active server is now empty.
    */
    if(this->getSystemUserLoggedId()!=0){
        int searchServerName = this->searchServerByName(this->getSystemServerCurrentName());
        if(searchServerName == 1){
            std::cout << "Leaving '" << this->getSystemServerCurrentName() << "' server!\n" << std::endl;
            this->setSystemCurrentServerName("");
        } else std::cout << "Server not found! You can try again!\n" << std::endl;
    }else std::cout << "You had to be logged on Agree System and to on server, to leave this server!" << std::endl;
}
//List Server Members
void System::listServerMembers(){
    /** Displays all members of the current active server on Agree System. 
    */
    if(this->getSystemServerCurrentName()!=""){
        const Server aux_server = this->returnServerByName(this->getSystemServerCurrentName());
        std::cout << "List of all members on server '" << aux_server.getServerName() << "': " << std::endl;
        for(size_t i=0; i<aux_server.getServerMembersId().size(); i++){
            const User aux_user = this->getUserById(aux_server.getServerMembersId()[i]);
            std::cout << aux_user.getUserName() << std::endl;
        }
        std::cout << "\n";
    }else{
        std::cout << "You have to log on a server first!\n\n";
        return;
    }
}
//List Server Channels
void System::listServerChannels(){
    if(this->getSystemServerCurrentName()==""){
        std::cout << "You have to log on a server before creates a channel on it!\n" << std::endl;
        return;
    }
    std::cout << "List of channels on the current server '" << this->getSystemServerCurrentName() << "'"<< std::endl;
    for(size_t i=0; i<this->servers.size(); i++){
        if(this->servers[i].getServerName() == this->getSystemServerCurrentName()){
            for(size_t j=0; j<this->servers[i].getServerChannels().size(); j++){
                std::cout << this->servers[i].getServerChannels()[j]->getChannelName() << std::endl;
            }
        }
    }
    std::cout << "\n\n" << std::endl;
}
//Create Server Channel
void System::createServerChannel(std::string name, std::string type){
    /** Creates a new channel for the current active server on Agree System. 
        @param name: string value for the new channel's name;
        @param type: string value for the new channel's type;
    */
    if(this->getSystemServerCurrentName()=="" && this->getSystemUserLoggedId()==0){
        std::cout << "You have to log on Agree System and log on a server before creates a channel on it!\n" << std::endl;
        return;
    }

    std::vector<Server>::iterator server_iterator;
    std::string current_server = this->getSystemServerCurrentName();
    server_iterator = std::find_if(this->servers.begin(), this->servers.end(), [current_server](Server server) {
        return current_server == server.getServerName();
    });

    if(server_iterator!=this->servers.end()){
        int result = server_iterator->checkChannelExists(name,type);
        if(result==0){
            Channel *new_channel;
            if(type=="voice"){
                new_channel = new VoiceChannel();
                new_channel->setChannelName(name);
                new_channel->setChannelType(type);
                server_iterator->addChannel(new_channel);
                std::cout << "A voice channel '"<< name << "' created on this server!\n" << std::endl;
            }else if(type=="text"){
                new_channel = new TextChannel();
                new_channel->setChannelName(name);
                new_channel->setChannelType(type);
                server_iterator->addChannel(new_channel);
                std::cout << "A text channel '"<< name << "' created on this server!\n" << std::endl;
            }
        }else{
            std::cout << "A text channel '"<< name << "' already exists on this server!\n" << std::endl;
            return;
        }
    }
}
//Enter Server Channel
void System::enterServerChannel(std::string name){
    /** Enters the current active user on an channel of current active server on Agree System. 
        @param name: string value for the channel's name that user will enters to.
    */
    if(this->getSystemServerCurrentName()==""){
        std::cout << "You have to log on a server before enters a channel on it!\n" << std::endl;
        return;
    }
    for(size_t i=0; i<this->servers.size(); i++){
       if(this->servers[i].getServerName() == this->getSystemServerCurrentName() && this->getSystemUserLoggedId() != 0){
            int result = this->servers[i].checkChannelExists(name,"");
            if(result) {
                this->setSystemCurrentChannelName(name);
                std::cout << "Entered the channel '"<< name << "' !\n" << std::endl;
            }else{
                std::cout << "Channel '"<< name << "' was not found on this server!\n" << std::endl;
            }
       }
    }
}
//Leave Server Channel
void System::leaveServerChannel(){
    /** Execute the 'leave-channel' command, i.e., set this system current active channel name to an empty string.
    */
    if(this->getSystemServerCurrentName()==""){
        std::cout << "You have to log on a server before leaves a channel on it!\n" << std::endl;
        return;
    }

    if(this->getSystemChannelCurrentName()==""){
        std::cout << "You have to log on a channel before leaves it!\n" << std::endl;
        return;
    }
    std::cout << "Leaving channel '" << this->getSystemChannelCurrentName() << "' of server '" << this->getSystemServerCurrentName() << "'" << std::endl;
    this->setSystemCurrentChannelName("");
}
//Send Message
void System::sendMessage(std::string content){
    /** Send a message on the current active channel, its content is passed by user input.
        @param content: string value for message's content.
    */
    if(this->getSystemServerCurrentName()=="" && this->getSystemUserLoggedId()==0){
        std::cout << "You have to log on a server before sends a message!\n" << std::endl;
        return;
    }

    if(this->getSystemChannelCurrentName()==""){
        std::cout << "You have to log on a channel before sends a message!\n" << std::endl;
        return;
    }

    char date[100];
    time_t s = time(nullptr);
    strftime(date, 50, "%m/%d/%Y - %R", localtime(&s));
    Message new_message = Message(date,this->getSystemUserLoggedId(),content);

    std::vector<Server>::iterator server_iterator;
    std::string current_server = this->getSystemServerCurrentName();
    std::string current_channel = this->getSystemChannelCurrentName();
    server_iterator = std::find_if(this->servers.begin(), this->servers.end(), [current_server](Server server) {
        return server.getServerName()==current_server;
    });

    if(server_iterator!=this->servers.end()){
        for(size_t i=0; i<server_iterator->getServerChannels().size(); i++){
            if(server_iterator->getServerChannels()[i]->getChannelName()==current_channel){
                if(server_iterator->getServerChannels()[i]->getChannelType()=="voice"){
                    server_iterator->getServerChannels()[i]->setVoiceChannelLastMessage(new_message);
                }else if(server_iterator->getServerChannels()[i]->getChannelType()=="text"){
                    server_iterator->getServerChannels()[i]->addMessage(new_message);
                }
                std::cout << "Message sended.\n\n";
            }
        }
    }else{
        std::cout << "Server not found!\n\n";
        return;
    }
}
//Display All Messages
void System::displayAllMessages(){
    /** Displays all messagens on the current active channel.
    */
    if(this->getSystemServerCurrentName()=="" && this->getSystemUserLoggedId()==0){
        std::cout << "You have to log on a server before creates a channel on it!\n" << std::endl;
        return;
    }
    if(this->getSystemChannelCurrentName()==""){
        std::cout << "You have to log on a channel before leaves it!\n" << std::endl;
        return;
    }
    std::vector<Server>::iterator server_iterator;
    std::string current_server = this->getSystemServerCurrentName();
    std::string current_channel = this->getSystemChannelCurrentName();
    server_iterator = std::find_if(this->servers.begin(), this->servers.end(), [current_server](Server server) {
        return server.getServerName()==current_server;
    });

    if(server_iterator!=this->servers.end()){
        for(size_t i=0; i<server_iterator->getServerChannels().size(); i++){
            if(server_iterator->getServerChannels()[i]->getChannelName()==current_channel){
                if(server_iterator->getServerChannels()[i]->getChannelType()=="voice"){
                    int user_id = server_iterator->getServerChannels()[i]->getVoiceChannelLastMessage().getMessageSender();                    
                    std::string message_date = server_iterator->getServerChannels()[i]->getVoiceChannelLastMessage().getMessageDate();
                    std::string message_content = server_iterator->getServerChannels()[i]->getVoiceChannelLastMessage().getMessageContent();
                    const User new_user = this->getUserById(user_id);
                    if(message_content!=""){
                       std::cout << "\n" << new_user.getUserName() <<  "<" << message_date << ">:" << message_content << std::endl;
                    }else std::cout << "There is no message to display.\n" << std::endl;
                }else if(server_iterator->getServerChannels()[i]->getChannelType()=="text"){
                    for(size_t j=0; j<server_iterator->getServerChannels()[i]->getTextChannelMessages().size(); j++){
                        int user_id = server_iterator->getServerChannels()[i]->getTextChannelMessages()[j].getMessageSender();
                        std::string message_date = server_iterator->getServerChannels()[i]->getTextChannelMessages()[j].getMessageDate();
                        std::string message_content = server_iterator->getServerChannels()[i]->getTextChannelMessages()[j].getMessageContent();
                        const User new_user = this->getUserById(user_id);
                        std::cout << new_user.getUserName() << "\n" << "<" << message_date << ">:" << message_content << std::endl;
                    }
                }
            }
        }
    }else{
        std::cout << "Server not found!\n\n";
        return;
    }
}
//Save
void System::save(std::string option){
    if(option=="users"){
        this->saveUsers();
    }else if(option=="servers"){
        this->saveServers();
    }else{
        std::cout << "\n\nInvalid option";
        return;
    }
}
//Save Users
void System::saveUsers(){
    /** This function saves all users created on Agree System.
    */
    std::ofstream users("./src/txt/data/users.txt");

    if(!users){
        std::cout << "\nFile was not open";
        exit(1);
    }else{
        users << this->getSystemUsers().size() << std::endl;
        for(size_t i=0; i<this->getSystemUsers().size(); i++){
            users << this->getSystemUsers()[i].getUserId() << std::endl;
            users << this->getSystemUsers()[i].getUserName() << std::endl;
            users << this->getSystemUsers()[i].getUserEmail() << std::endl;
            users << this->getSystemUsers()[i].getUserPassword() << std::endl;
        }
        users.close();
    }
} 
//Save Servers
void System::saveServers(){
    /** This function saves all servers created on Agree System.
    */
    std::ofstream servers("./src/txt/data/servers.txt");

    if(!servers){
        std::cout << "\nFile was not open";
        exit(1);
    }else{
        for(auto it_server = this->servers.begin(); it_server!=this->servers.end(); it_server++){
            servers << it_server->getServerOwnerId() << std::endl;
            servers << it_server->getServerName() << std::endl;
            servers << it_server->getServerDescription() << std::endl;
            servers << it_server->getServerInviteCode() << std::endl;
            servers << it_server->getServerMembersId().size() << std::endl;

            for(auto it_member = it_server->getServerMembersId().begin(); it_member!=it_server->getServerMembersId().end(); it_member++){
                servers << (*it_member) << std::endl;
            }

            servers << it_server->getServerChannels().size() << std::endl;

            for(size_t i=0; i<it_server->getServerChannels().size(); i++){
                servers << it_server->getServerChannels()[i]->getChannelName() << std::endl;
                servers << it_server->getServerChannels()[i]->getChannelType() << std::endl;

                if(it_server->getServerChannels()[i]->getChannelType() == "voice"){
                    servers << "1" << std::endl;
                    servers << it_server->getServerChannels()[i]->getVoiceChannelLastMessage().getMessageSender() << std::endl;
                    servers << it_server->getServerChannels()[i]->getVoiceChannelLastMessage().getMessageDate() << std::endl;
                    servers << it_server->getServerChannels()[i]->getVoiceChannelLastMessage().getMessageContent() << std::endl;
                }else if(it_server->getServerChannels()[i]->getChannelType() == "text"){
                    servers << it_server->getServerChannels()[i]->getTextChannelMessages().size() << std::endl;
                    for(size_t j=0; j<it_server->getServerChannels()[i]->getTextChannelMessages().size(); j++){
                        servers << it_server->getServerChannels()[i]->getTextChannelMessages()[j].getMessageSender() << std::endl;
                        servers << it_server->getServerChannels()[i]->getTextChannelMessages()[j].getMessageDate() << std::endl;
                        servers << it_server->getServerChannels()[i]->getTextChannelMessages()[j].getMessageContent() << std::endl;
                    }
                }
            }
        }
        servers.close();
    }
}
//Load
//Load Users
//Load Servers