output: Employee.o Manager.o Management.o main.o
	g++ Employee.o Manager.o Management.o main.o -o main.exe

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
