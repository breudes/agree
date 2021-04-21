#include "../include/voice_channel.h"

//Default Constructor
VoiceChannel::VoiceChannel() : Channel(){
    /** Constructor for Voice Channel class, that has Channel class as its base class. It'll set the message object 
      * with its (Message class) default constructor. 
    */
    this->lastMessage = Message();
}
//Destructor
VoiceChannel::~VoiceChannel(){
    /** Constructor for Voice Channel class, that has Channel class as its base class. It'll set the message object 
      * with its null values for all properties on Message class. 
    */
    this->lastMessage.setMessageDate("");
    this->lastMessage.setMessageSender(0);
    this->lastMessage.setMessageContent("");
}
//Get Channel Type
std::string VoiceChannel::getChannelType() const{
    /** Returns the type of this voice channel, i.e., type is equals 'voice'.
        @return: string value.
    */
    return "voice";
}
//Get VoiceChannel Last Message
Message VoiceChannel::getVoiceChannelLastMessage() const{
    /** Returns the last message propertie of this VoiceChannel.
        @return: message object relative with 'last message' propertie.
    */
    return this->lastMessage;
}
//Set VoiceChannel Last Message
void VoiceChannel::setVoiceChannelLastMessage(Message new_last_message){
    /** Updates the last message propertie of this VoiceChannel.
        @param new_last_message: message object relative with new 'last message' propertie.
    */
    this->lastMessage = new_last_message;
}
//Add Message
void VoiceChannel::addMessage(Message message){
    /** Updates messages by adding one new message for this voice channel.
        @param new_messages: object of type Message with the new message.
    */
    this->lastMessage = message;
}
std::vector<Message> VoiceChannel::getTextChannelMessages() const{
    std::vector<Message> result;
    return result;
}