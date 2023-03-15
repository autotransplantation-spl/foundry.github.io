
CC = cc
CFLAGS =  -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -Wall -g
CHECKPACKAGE = `pkg-config --cflags --libs check`
LDFLAGS =

OBJS =  test_suite.o InterfaceWithCoreFeature.o append.o  io.o  header.o  list.o  config.o  

all: Individual.x

InterfaceHeader.o:  FEATURE/InterfaceHeader.h

archiver.o:  FEATURE/archiver.h

%.o:  FEATURE/%.c
	$(CC) -c  $(CFLAGS)  $<
Individual.x: $(OBJS)
	$(CC) -o $@ $(OBJS) -lm $(CHECKPACKAGE) $(CFLAGS)

clean:
	rm -rf *.o Individual.x