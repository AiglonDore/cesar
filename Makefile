WCC=g++
LCC=g++

ifeq ($(THREADS),FALSE)
	MACROS=-DTHREADS=false
endif

ifeq ($(OS), Windows_NT)
	LCC=wsl g++
	DEL=del
	SEP=\\
	DOC=wsl doxygen
else
	DEL=rm
	SEP=/
	WCC=x86_64-w64-mingw32-g++ -m64 -static
	DOC=doxygen
endif

ifeq ($(RELEASE),TRUE)
	CFLAGS= -s -O3 -Wall -Wextra
else
	CFLAGS=-g -Wall -Wextra
endif

all : windows linux

windows : obj/main.obj obj/cesar.obj obj/code.obj obj/vigenere.obj
	$(WCC) $(CFLAGS) -o bin/code.exe $^

obj/main.obj : src/main.cpp header/cesar.h header/code.h header/vigenere.h
	$(WCC) $(CFLAGS) -c -o $@ $<

obj/cesar.obj : src/cesar.cpp header/cesar.h header/code.h
	$(WCC) $(CFLAGS) -c -o $@ $<

obj/code.obj : src/code.cpp header/code.h
	$(WCC) $(CFLAGS) -c -o $@ $<

obj/vigenere.obj : src/vigenere.cpp header/vigenere.h header/code.h
	$(WCC) $(CFLAGS) -c -o $@ $<

linux : obj/main.o obj/cesar.o obj/code.o obj/vigenere.o
	$(LCC) $(CFLAGS) -o bin/code.out $^

obj/main.o : src/main.cpp header/cesar.h header/code.h header/vigenere.h
	$(LCC) $(CFLAGS) -c -o $@ $<

obj/cesar.o : src/cesar.cpp header/cesar.h header/code.h
	$(LCC) $(CFLAGS) -c -o $@ $<

obj/code.o : src/code.cpp header/code.h
	$(LCC) $(CFLAGS) -c -o $@ $<

obj/vigenere.o : src/vigenere.cpp header/vigenere.h header/code.h
	$(LCC) $(CFLAGS) -c -o $@ $<

clean :
	$(DEL) obj$(SEP)*.o
	$(DEL) obj$(SEP)*.obj
	$(DEL) bin$(SEP)*.exe
	$(DEL) bin$(SEP)*.out

doc : 
	$(DOC) Doxyfile