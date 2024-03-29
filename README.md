## Project Agree

## About this project

Agree is a project, made with C++, similar to a program called Discord. It has servers, users, channels and interactions between all of them. Each interaction is possible using one command by each line, this project has an executor to compile each valid command. To learn how to use this project, see sections 'Compiling' and 'Input and Output commands examples'.

This project uses a template code made by professor Isaac Franco Fernandes (https://github.com/isaacfranco). You can see his code on https://github.com/isaacfranco/lp1-concordo-base.

Agree Project is a task presents on class called 'Program Language I', taught by professor Renan Moioli, in the course of IT at Federal University of Rio Grande do Norte (Brazil). This project has three parts, for more details see section called 'Explanation about each part of this project'.

## Compiling

A Makefile is used to compile this project. From the project's root folder, assuming `$` is the terminal prompt, follow these steps:

    ```
    # Clone project
    $ git clone https://github.com/breudes/agree.git   
    # Compile project
    $ make     
    # Run 
    $ ./main < ./src/txt/script.txt
    ```

In this project, you have two options: 
    
1. You can use the 'script.txt' file to set all commands at once, therefore, this project will compile all commands at once too. To test different commands, you can alter the .txt file and type './main < ./src/txt/script.txt' again; and to know commands examples, see section 'Input and Output commands examples';
    
2. You can set just ./main and add commands, one command by line. In this case, an output will be displayed considering each command.
    
Ps: this 'script.txt' file has all commands by default, to facilitate the project execution test. But, feel free to change this file however you want.

## Explanation about each part of this project

1. Part One

First part is where some methods were implemented to interact with users and servers. Methods like create user or server, update server's info, remove or enter server. Each command and input's example is on the next topic called 'Input and Output commands examples', feel free to use this topic as a guide for you to use the system.

2. Part Two 

Second part is where some methods were implemented to interact with channels (text or voice type, of course). Which means that some methods were implemented to create, enter, leave a channel; the same way was implement some methods to send a message on some channel, to list all messages from a particular channel, list all channels on some active server, etc. All channels and messages are part of some server, so all of them will be saved or loaded on servers.

3. Part Three

On this third and last part two main methods were implemented : save and load, that reach out another 4 methods, they're, respectively: save users, save servers, load users and load servers. The first two are taken by method 'save', where Agree System saves all data from active users and servers. The same goes with the last two methods, taken by methods 'load', where Agree System loads all data from previous users and servers. This is only possible by creating two .txt files: users and servers, with those files the user can save and load any data of these classes on Agree System.

Ps: those .txt files are on the path: ./src/txt/data, in case you want to clear or wrote in them.

## Input and Output commands examples

Like it was said, this project has three parts, the first part takes examples 1-12 and part two takes examples 13-16. See all examples of input and output, titled by command:

1. quit
    This command can be typed any time while Agree is running, regardless of whether has an user logged or not.

    > quit 
    > You're logging off from Agree System. Goodbye!

2. create-user
    - structure: create-user <user's email> <user's password> <user's name>
    - example 01: 
        > create-user mareep@gmail.com 12345 mareep
        > Created user!
    - example 02: 
        > create-user mareep@gmail.com 12345 mareep de souza batista
        > Created user!
    - but if users already exists, here is the output:
        > User already exists!
    
3. login 
    - structure: login <user's email> <user's password>
    - example: 
        > login bulbasaur@outlook.com flower
        > You're now logged as 'bulbasaur@outlook.com' on Agree System!
    - but if email or password was invalid, here is the output:
        > User not found. You can try again!
    or 
        > Invalid user's password!

4. disconnect
    This command disconnect the current user logged, but Agree will be still running. It would only stop if the command was 'quit'.
        > disconnect
        > Disconnecting user "bulbasaur@outlook.com"
        > Note that Agree System is still on!
    - but if there is not a user logged, here is the output:
        > Not connected!
        > Note that Agree System is still on!

5. create-server
    First of all, a server has a name and an optional invite code, for future members enter with; but, when you create a server, the invite code isn't set yet, with another command you'll be able to set an invite code, if you want. 
        
    This command is only available if Agree System has at least one user logged to create a server. Otherwise, the output will be "Enter with an user before create a server!". After its creation, you'll be the only owner of the server.

    - structure: create-server <server's name>
    - example:
        > create-server pokemons
        > Created server!
    - but if there already is a server is this name, here is the output:
        > Server already exists with this name!

    The next commands is required that at least one user is logged on Agree, and also has to be the owner of a given server. This rule doesn't apply on command 'list-servers'.

6. set-server-desc
    - structure: set-server-desc <server's name> <server's new description>
    - example 01 (you're the owner of server): 
        > set-server-desc pokemons all pokemons that I really like
        > Modified 'pokemons' server description!
    - example 02 (you are not the owner):
        > set-server-desc pokemons all pokemons that I really like
        > You cannot change another user's server description!

    And if the server's name was invalid, the output will just be "Server not found! You can try again!".

7. set-server-invite-code
    - structure: set-server-invite-code <server's name> <server's new invite code>
    - example 01 (set a server as closed server): 
        > set-server-invite-code pokemons 123456
        > Set 'pokemons' server invite code!
    - example 02 (set a server as open server):
        > set-server-invite-code pokemons 
        > Set 'pokemons' server invite code!

    And if the server's name was invalid, the output will just be "Server not found! You can try again!".
        
8. list-servers
    > list-servers
    > List of all servers on Agree System: 
    > pokemons
    > earth
    > avatar
    > korra

9. remove-server
    - structure: remove-server <server's name>
    - example 01 (you're the owner of server):
        > remove-server pokemons
        > Removed 'pokemons' server!
    - example 02 (you are not the owner):
        > remove-server pokemons
        > You are not the owner of the 'pokemons' server
        
    And if the server's name was invalid, the output will just be "Server not found! You can try again!".

10. enter-server
    - structure: enter-server <server's name>
    - example 01 (server with no invite code): 
        > enter-server pokemons
        > This is an open server!
        > Entering 'pokemons' server!
    - example 02 (server with an invite code):
        > enter-server earth 123
        > This is a closed server. You need an invite code to enter!
        > Entering 'earth' server!
    - but if the invite code was invalid, here is the output:
        > This is a closed server. You need an invite code to enter!
        > Invalid invite code for this server. You can try again!

    And if the server's name was invalid, the output will just be "Server not found! You can try again!".

11. leave-server
        > leave-server
        > Leaving 'pokemons' server!
    - but if there is not server attached to the current user, here is the output:
        > You are not viewing any servers

    And if the server's name was invalid, the output will just be "Server not found! You can try again!".

12. list-participants

    This command will be only show the names of the members of the current active server, if the current user logged on Agree was on a given server. All names were taken by user's id. 

    > list-participants
    > List of all members on server 'pokemons'
    > mareep
    > bulbasaur
    > cyndaquil

    And if the server's name was invalid, the output will just be "Server not found! You can try again!".

Ps: For these commands, you'll have to be logged on some server on Agree System, otherwise, it won't let you execute them. 

13. list-channels
    > list-channels
    > List of channels on the current server 'pokemons'
    > earth
    > water
14. create-channel
    - structure: create-channel <'channel's name'> <'channel's type'>
    - example 01:
        > create-channel earth text 
        > A text channel 'earth' created on this server!
    - example 02:
        > create-channel water voice
        > A voice channel 'water' created on this server!
15. enter-channel
    - structure: enter-channel <'channel's name'>
        > enter-channel earth
        > Entered the channel 'earth' !
16. leave-channel
    > leave-channel
    > Leaving channel 'earth' of server 'pokemons'
17. send-message
    Note: this command is only available if you are logged on some server and channel, otherwise it won't execute.
    - structure: send-message <'message's content'>
    - example: 
        > send-message hi how are u?
18. list-messages
    Note: this command is only available if you are logged on some server and channel, otherwise it won't execute.
    > list-messages
    > mareep
    > <04/21/2021 - 14:40>:hi how are u?

    If there is no messages available, then the output will be "There is no messages to display."
    
## Feedback (Limitations and Difficulties)

This project was easier than the previous projects because on Agree we used vector as a data structure, using this structure on Server and System classes. The limitation was the inheritance subject because I studied this a long time ago so It was a little tricky to implement this part. 

## Author and Collaborators

This project was made by breudes (https://github.com/breudes). Full name author: Brenda Alexandra de Souza Silva. But, again, it was used a template base code from professor Isaac Franco Fernandes (https://github.com/isaacfranco), so Isaac is also a co-author or collaborator of this project. 

You can see his template code on https://github.com/isaacfranco/lp1-concordo-base.
    
## License

This project is under MIT license. See LICENSE for more details.
