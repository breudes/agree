#ifndef VOICE_CHANNEL_H_
#define VOICE_CHANNEL_H_

#include <string>
#include <iostream>

class VoiceChannel{
    private:
        Message lastMessage;
    public:
        //Constructors and Destructor
        VoiceChannel();
        ~VoiceChannel();
        //Getters and Setters
        Message getVoiceChannelLastMessage() const;
        void setVoiceChannelLastMessage(Message new_last_message);
}
#endif