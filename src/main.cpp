#include "./utils.cpp"

int main() {
  System agree;
  std::string output, command;
  while(command!="quit"){
      output = init(std::cin,std::cout);
      if(output!="empty") command = executeCommands(output,agree);
      if(command=="quit") break;
  }
  return 0;
}