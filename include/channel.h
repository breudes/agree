#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <string>
#include <iostream>
#include <vector>
#include "./message.h"
/*
    * This class is a base class for another two classes on Agree. A channel class has a name channel.
*/
class Channel{
    protected:
        std::string name;
        std::string type;
    public:
        //Constructors and Destructor
        Channel() {}
        Channel(std::string name) { this->name = name; }
        Channel(std::string name, std::string type) { 
            this->name = name;
            this->type = type;
        }
        virtual ~Channel() {}
        //Getters and Setters
        std::string getChannelName() const{
            return this->name;
        }
        virtual std::string getChannelType() const{
            return this->type;
        }
        void setChannelName(std::string new_name){
            this->name = new_name;
        }
        void setChannelType(std::string new_type){
            this->type = new_type;
        }
        virtual void addMessage(Message message) = 0; 
        virtual void setVoiceChannelLastMessage(Message new_last_message) = 0;
        virtual Message getVoiceChannelLastMessage() const = 0;
        virtual std::vector<Message> getTextChannelMessages() const = 0;
};
#endif