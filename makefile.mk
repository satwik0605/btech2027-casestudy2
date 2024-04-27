a.exe: functions.o main.o
    gcc functions.o main.o
functions.o: function.c header.h
    gcc -c functions.c
main.o: main.c head.h
    gcc -c main.c