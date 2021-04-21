#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <iostream>

/*
    * Class used on Agree System to create messages objects. Each object has a date, a sender and its content, i.e.,
    the message itself.
*/
class Message{
    private:
        std::string date;
        int sender; 
        std::string content;
    public:
        //Constructors and Destructor
        Message();
        Message(std::string date, int sender, std::string content);
        ~Message();
        //Getters and Setters
        std::string getMessageDate() const;
        int getMessageSender() const;
        std::string getMessageContent() const;
        void setMessageDate(std::string new_date);
        void setMessageSender(int new_sender);
        void setMessageContent(std::string new_content);
};
#endif