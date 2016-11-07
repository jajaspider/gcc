gcc_ps : main.o proc.o qps.o
	gcc -o gcc_ps main.o proc.o qps.o
main.o : main.cpp qps.h
	gcc -c main.cpp
proc.o : proc.cpp proc.h
	gcc -c proc.cpp
qps.o : qps.cpp qps.h proc.h
	gcc -c qps.cpp
clean :
	rm -f gcc_ps main.o proc.o qps.o
