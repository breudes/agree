#ifndef TEXT_CHANNEL_H_
#define TEXT_CHANNEL_H_

#include <string>
#include <iostream>

class TextChannel{
    private:
        std::vector<Message> messages;
    public:
        //Constructors and Destructor
        TextChannel();
        ~TextChannel();
        //Getters and Setters
        std::vector<Message> getTextChannelMessages() const;
        void setTextChannelMessages(std::vector<Message> new_messages);
};
#endif