# 'Make' calls targets makeobjects and main
all: makeobjects main

# Creates a folder called 'bin'
makeobjects:
	mkdir -p bin

# Compiles all .cpp files and creates the executable file

# Creates the executable file
main: bin/user.o bin/server.o bin/system.o bin/utils.o bin/main.o
	g++ bin/main.o -Wall -std=c++11 -o main

#Compiles all .cpp files
bin/user.o: ./src/user.cpp
	g++ ./src/user.cpp -Wall -std=c++11 -c -o bin/user.o

bin/server.o: ./src/server.cpp 
	g++ ./src/server.cpp -Wall -std=c++11 -c -o bin/server.o

bin/system.o: ./src/system.cpp bin/user.o bin/server.o
	g++ ./src/system.cpp -Wall -std=c++11 -c -o bin/system.o

bin/utils.o: ./src/utils.cpp bin/user.o bin/server.o bin/system.o
	g++ ./src/utils.cpp -Wall -std=c++11 -c -o bin/utils.o

bin/main.o: ./src/main.cpp bin/user.o bin/server.o bin/system.o bin/utils.o
	g++ ./src/main.cpp -Wall -std=c++11 -c -o bin/main.o

# Removes 'bin' folder and the executable file
clean:
	rm -rf bin
	rm main