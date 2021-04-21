#include "../include/text_channel.h"

//Default Constructor
TextChannel::TextChannel() : Channel() {
    //This constructor its empty because the only properties is a vector object, is not necessary init this object.
}
//Destructor
TextChannel::~TextChannel(){
    //This destructor its empty because the only properties is a vector object, is not necessary destructs this object.
    //The vector object will be destroyed as soon this project stops its execution.
}
//Get Channel Type
std::string TextChannel::getChannelType() const{
    /** Returns the type of this text channel, i.e., type is equals 'text'.
        @return: string value.
    */
    return "text";
}
//Get TextChannel Messages
std::vector<Message> TextChannel::getTextChannelMessages() const{
    /** Returns the messages of this text channel.
        @return: vector of type Message with the messages.
    */
    return this->messages;
}
//Get TextChannel Messages
void TextChannel::setTextChannelMessages(std::vector<Message> new_messages){
    /** Set new messages for this text channel.
        @param new_messages: vector of type Message with the new messages.
    */
    this->messages = new_messages;
}
//Add Message
void TextChannel::addMessage(Message message){
    /** Updates messages by adding one new message for this text channel.
        @param new_messages: object of type Message with the new message.
    */
    this->messages.push_back(message);
}
//Set Last Message
void TextChannel::setVoiceChannelLastMessage(Message new_last_message){
}
//Get VoiceChannel Last Message
Message TextChannel::getVoiceChannelLastMessage() const{  
    Message message = Message();
    return message;
}