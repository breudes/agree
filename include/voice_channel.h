#ifndef VOICE_CHANNEL_H_
#define VOICE_CHANNEL_H_

#include "../src/text_channel.cpp"
#include <string>
#include <iostream>

/*
    * This class is a 'child' from Channel Class, i.e., a VoiceChannel Class also has the Channel Class properties,
    * plus its own propertie, that are a message class's object to storage the last message sended on a voice channel.
*/
class VoiceChannel : public Channel{
    private:
        Message lastMessage;
    public:
        //Constructors and Destructor
        VoiceChannel();
        ~VoiceChannel();
        //Getters and Setters
        void addMessage(Message message);
        std::string getChannelType() const;
        Message getVoiceChannelLastMessage() const;
        void setVoiceChannelLastMessage(Message new_last_message);
        std::vector<Message> getTextChannelMessages() const;
};
#endif