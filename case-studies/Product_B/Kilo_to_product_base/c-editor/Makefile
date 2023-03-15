.POSIX:
.SUFFIXES:

CFLAGS = -Wall -Wextra -pedantic -std=c99

all: kilo
kilo: InterfaceWithCoreFeature.o kilo.o  
	gcc -std=gnu99 -o kilo kilo.o InterfaceWithCoreFeature.o  -lm $(CHECKPACKAGE) $(CFLAGS)

kilo.o:  kilo.h  InterfaceHeader.h kilo.c
	gcc -std=gnu99 -c -o kilo.o  kilo.c $(CFLAGS)

InterfaceWithCoreFeature.o:	InterfaceHeader.h InterfaceWithCoreFeature.c
	gcc -std=gnu99 -c -o InterfaceWithCoreFeature.o InterfaceWithCoreFeature.c $(CFLAGS)



clean:
	rm -f kilo

