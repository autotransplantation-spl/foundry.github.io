
CC = cc
CFLAGS =  -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -Wall -g -DTEST_SUITE -UNEATVI_MAIN -DF_DIR_INIT -DF_DIR_INIT_TOO
CHECKPACKAGE = `pkg-config --cflags --libs check`
LDFLAGS =

OBJS =  test_suite.o InterfaceWithCoreFeature.o vi.o ex.o lbuf.o mot.o sbuf.o ren.o dir.o \
	syn.o reg.o led.o uc.o term.o rset.o regex.o cmd.o conf.o  

all: Individual.x

InterfaceHeader.o:  FEATURE/InterfaceHeader.h

archiver.o:  FEATURE/archiver.h

%.o:  FEATURE/%.c
	$(CC) -c  $(CFLAGS)  $<
Individual.x: $(OBJS)
	$(CC) -o $@ $(OBJS) -lm $(CHECKPACKAGE) $(CFLAGS)

clean:
	rm -rf *.o Individual.x
