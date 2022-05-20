output: Person.o Employee.o Manager.o Management.o main.o
	g++ Person.o Employee.o Manager.o Management.o main.o -o main.exe

Person.o: Person.cpp
	g++ -c Person.cpp

Employee.o: Employee.cpp
	g++ -c Employee.cpp

Manager.o: Manager.cpp
	g++ -c Manager.cpp

Management.o: Management.cpp
	g++ -c Management.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm*.o main.exe
