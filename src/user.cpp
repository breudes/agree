#include "../include/user.h"

int id_count = 0;

User::User(){
    id_count++;
    this->id = id_count;
    this->name = "";
    this->email = "";
    this->password = "";
}
User::User(std::string name, std::string email, std::string password){
    id_count++;
    this->id = id_count;
    this->name = name;
    this->email = email;
    this->password = password;
}
User::~User(){
    this->name.clear();
    this->email.clear();
    this->password.clear();
}
int User::getUserId() const{
    return this->id;
}       
std::string User::getUserName() const{
    return this->name;
}
std::string User::getUserEmail() const{
    return this->email;
}
std::string User::getUserPassword() const{
    return this->password;
}
void User::setUserId(int new_id){
    this->id = new_id;
}
void User::setUserName(std::string new_name){
    this->name = new_name;
}
void User::setUserEmail(std::string new_email){
    this->email = new_email;
}
void User::setUserPassword(std::string new_password){
    this->password = new_password;
}