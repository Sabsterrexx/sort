# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
# Use command "mingw32-make.exe" in git bash terminal to run

CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date

#Final executable file is linked here:
tcs: sort.o tcs.o catch2.o printElements.o tests-main.o
	$(CC) $(CFLAGS) -o tcs sort.o tcs.o catch2.o printElements.o tests-main.o
 
# The main.o target can be written more simply
 
#individual c++ files are linked here:
sort.o: sort.cpp sort.hpp
	$(CC) $(CFLAGS) -c sort.cpp
 
tcs.o: tcs.cpp sort.hpp printElements.hpp
	$(CC) $(CFLAGS) -c tcs.cpp 

catch2.o: catch2/catch_amalgamated.hpp catch2/catch_amalgamated.cpp
	$(CC) $(CFLAGS) -c catch2/catch_amalgamated.cpp -o catch2.o

tests-main.cpp: catch2/catch_amalgamated.hpp
	$(CC) $(CFLAGS) -c tests-main.cpp

printElements.o: printElements.cpp printElements.hpp
	$(CC) $(CFLAGS) -c printElements.cpp

clean :
	rm sort.o tcs.o tcs.exe tcs catch2.o printElements.o