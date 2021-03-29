#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <string>
#include <iostream>

/*
    * This class is a base class for future features on this project. 
    * For now, this class is only used on Server class, for its 'channels' propertie.
*/
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