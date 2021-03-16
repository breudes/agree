#include "./system.cpp"

#include <istream>
#include <ostream>
#include <sstream>
#include <queue>

std::string remainsLine(std::istringstream &inputStringStream){
    std::string remain;
    std::getline(inputStringStream, remain, '\0'); 
    if(remain!="" && (remain[0]== ' ' || remain[0] == '\t')) {
        remain = remain.substr(1); 
    }
    return remain;
}

std::string init(std::istream &inputStream, std::ostream &outputStream) {
  std::string line, output;
  if(std::getline(inputStream, line)) return line; 
  return "empty";
}

std::string executeCommands(std::string line, System &agree) {
  std::istringstream buf(line);
  std::string command;
  buf >> command;

  if(command=="quit"){
    std::cout << "Logging off from Agree System. Goodbye!" << std::endl;
    return "quit";
  } else if(command=="create-user"){
    std::string email, password, name;
    buf >> email;
    buf >> password;
    name = remainsLine(buf);
    User new_user = User(name,email,password);
    agree.createUser(new_user);
  } else if(command=="login"){
    std::string email, password;
    buf >> email;
    buf >> password;
    agree.login(email,password);
  } else if(command=="disconnect"){
    agree.disconnect();
  } else if(command=="create-server"){
    std::string name;
    buf >> name;
    agree.createServer(name);
  } else if(command=="set-server-desc"){
    std::string name, new_description;
    buf >> name;
    new_description = remainsLine(buf);
    agree.updateServerDescription(name,new_description);
  } else if(command=="set-server-invite-code"){
    std::string name, invite_code;
    buf >> name;
    buf >> invite_code;
    agree.updateServerInvite(name,invite_code);
  } else if(command=="list-servers"){
    agree.listServers();
  }
  return command;
}