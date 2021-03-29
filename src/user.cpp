#include "../include/user.h"

int id_count = 0;

//Default Constructor
User::User(){
    /**
        * Default constructor for User Class. Enters null values for all properties.
    */
    id_count++;
    this->id = id_count;
    this->name = "";
    this->email = "";
    this->password = "";
}
//Constructor
User::User(std::string name, std::string email, std::string password){
    /**
        * Constructor for User Class. Enters values for all properties, these values passed as input.
        @param name: string value for user's name;
        @param email: string value for user's email;
        @param password: string value for user's password.
    */
    id_count++;
    this->id = id_count;
    this->name = name;
    this->email = email;
    this->password = password;
}
//Destructor
User::~User(){
    /**
        * Default destructor for User Class. Clears all string properties.
    */
    this->name.clear();
    this->email.clear();
    this->password.clear();
}
//Get User Id
int User::getUserId() const{
    /** Returns this user id.
        @return: int value of this user id.
    */
    return this->id;
} 
//Get User Name      
std::string User::getUserName() const{
    /** Returns this user name.
        @return: string value of this user name.
    */
    return this->name;
}
//Get User Email
std::string User::getUserEmail() const{
    /** Returns this user email.
        @return: string value of this user email.
    */
    return this->email;
}
//Get User Password
std::string User::getUserPassword() const{
    /** Returns this user password.
        @return: string value of this user password.
    */
    return this->password;
}
//Set User Id
void User::setUserId(int new_id){
    /** Set a new id for this user.
        @param new_id: int value for this user id.
    */
    this->id = new_id;
}
//Set User Name
void User::setUserName(std::string new_name){
    /** Set a new name for this user.
        @param new_name: string value for this user name.
    */
    this->name = new_name;
}
//Set User Email
void User::setUserEmail(std::string new_email){
    /** Set a new email for this user.
        @param new_email: string value for this user email.
    */
    this->email = new_email;
}
//Set User Password
void User::setUserPassword(std::string new_password){
    /** Set a new password for this user.
        @param new_password: string value for this user password.
    */
    this->password = new_password;
}