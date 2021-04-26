#include "./system.cpp"
#include <queue>

//Remains Line
std::string remainsLine(std::istringstream &inputStringStream){
  /** Get all remains characters on a given input string stream. 
    @param inputStringStream: input string stream reference;
    @return: string value.
  */
  std::string remain;
  std::getline(inputStringStream, remain, '\0'); 
  if(remain!="" && (remain[0]== ' ' || remain[0] == '\t')) {
    remain = remain.substr(1); 
  }
  return remain;
}
//Init
std::string init(std::istream &inputStream, std::ostream &outputStream){
  /** Get all characters on a given input string stream, in this case, on a line of a .txt file or line on command console. 
    @param inputStream: input string stream reference;
    @param outputStream: output string stream reference;
    @return: string value.
  */
  std::string line, output;
  if(std::getline(inputStream, line)) return line; 
  return "empty";
}
//Execute Commands
std::string executeCommands(std::string line, System &agree){
  /** Execute all commands on Agree System, considering one command by line. 
    @param line: string value;
    @param agree: system class reference;
    @return: string value.
  */
  std::istringstream buf(line);
  std::string command;
  buf >> command;
  /* ----------------- PART 1 ----------------- */
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
    agree.save("users");
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
    agree.save("servers");
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
  } else if(command=="remove-server"){
    std::string name;
    buf >> name;
    agree.removeServer(name);
  } else if(command=="enter-server"){
    std::string name, invite_code;
    buf >> name;
    buf >> invite_code;
    agree.enterServer(name, invite_code);
  } else if(command=="leave-server"){
    agree.leaveServer();
  } else if(command=="list-participants"){
    agree.listServerMembers();
  /* ----------------- PART 2 ----------------- */
  } else if(command=="list-channels"){
    agree.listServerChannels();
  } else if(command=="create-channel"){
    std::string name, type;
    buf >> name;
    buf >> type;
    agree.createServerChannel(name,type);
  } else if(command=="enter-channel"){
    std::string name;
    buf >> name;
    agree.enterServerChannel(name);
  } else if(command=="leave-channel"){
    agree.leaveServerChannel();
  } else if(command=="send-message"){
    std::string content;
    content = remainsLine(buf);
    agree.sendMessage(content);
  } else if(command=="list-messages"){
    agree.displayAllMessages();
  }
  return command;
}