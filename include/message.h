#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <iostream>

class Message{
    private:
        std::string date;
        int sender; 
        std::string content;
    public:
        //Constructors and Destructor
        Message();
        ~Message();
        //Getters and Setters
        std::string getMessageDate() const;
        int getMessageSender() const;
        std::string getMessageContent() const;
        void setMessageDate(std::string new_date);
        void setMessageSender(int new_sender);
        void setMessageContent(std::string new_content);
}
#endif