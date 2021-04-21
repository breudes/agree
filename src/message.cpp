#include "../include/message.h"

//Default Constructor
Message::Message(){
    /** Default constructor for Message Class. It has two empty strings, date and content of message,
      * and int value, as the user sender's ID.
    */
    this->date = "";
    this->sender = 0;
    this->content = "";
}
//Constructor
Message::Message(std::string date, int sender, std::string content){
    /** Constructor for Message Class. It takes by user input all properties: date, sender and content of message.
        @param date: string value for message's date;
        @param sender: int value for message's sender ID;
        @param content: string value for message's content.
    */
    this->date = date;
    this->sender = sender;
    this->content = content;
}
//Destructor
Message::~Message(){
    /** Destructor for Message Class. It'll clear two strings: date and content of the message.
    */
    this->date.clear();
    this->content.clear();
}
//Get Message Date
std::string Message::getMessageDate() const{
    /** Returns this message's date. 
        @return: string value relative with message's date.
    */
    return this->date;
}
//Get Message Sender
int Message::getMessageSender() const{
    /** Returns this message's sender ID. 
        @return: int value relative with message's sender ID.
    */
    return this->sender;
}
//Get Message Content
std::string Message::getMessageContent() const{
    /** Returns this message's content. 
        @return: string value relative with message's content.
    */
    return this->content;
}
//Set Message Date
void Message::setMessageDate(std::string new_date){
    /** Set a new date to this message.
        @param new_date: string value relative with message's new date.
    */
    this->date = new_date;
}
//Set Message Sender
void Message::setMessageSender(int new_sender){
    /** Set a new sender to this message.
        @param new_sender: int value relative with message's new sender ID.
    */
    this->sender = new_sender;
}
//Set Message Content
void Message::setMessageContent(std::string new_content){
    /** Set a new content to this message.
        @param new_content: string value relative with message's new content.
    */
    this->content = new_content;
}