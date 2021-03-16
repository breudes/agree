#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <string>
#include <iostream>

class Channel{
    private:
        std::string name;
    public:
        //Constructors and Destructor
        Channel();
        //~Channel();
        //Getters and Setters
        std::string getChannelName() const;
        void setChannelName(std::string new_name);
};
#endif