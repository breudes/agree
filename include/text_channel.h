#ifndef TEXT_CHANNEL_H_
#define TEXT_CHANNEL_H_

#include "./channel.h"
#include "../src/message.cpp"
#include <string>
#include <iostream>
#include <vector>

/*
    * This class is a 'child' from Channel Class, i.e., a TextChannel Class also has the Channel Class properties,
    * plus its own properties, that are a message class's vector to storage all messages sended on a text channel.
*/
class TextChannel : public Channel{
    private:
        std::vector<Message> messages;
    public:
        //Constructors and Destructor
        TextChannel();
        ~TextChannel();
        //Getters and Setters
        std::string getChannelType() const;
        std::vector<Message> getTextChannelMessages() const;
        void setTextChannelMessages(std::vector<Message> new_messages);
        void addMessage(Message message);
        void setVoiceChannelLastMessage(Message new_last_message);
        Message getVoiceChannelLastMessage() const;
};
#endif