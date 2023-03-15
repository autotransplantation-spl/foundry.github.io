CC = cc
CFLAGS = -Wall -O2
LDFLAGS =

OBJS = vi.o ex.o InterfaceWithCoreFeature.o lbuf.o mot.o sbuf.o ren.o dir.o syn.o reg.o led.o \
	uc.o term.o rset.o regex.o cmd.o conf.o list.o io.o \
	header.o config.o append.o

all: vi

conf.o: conf.h

archiver.o: archiver.h

InterfaceHeader.o: InterfaceHeader.h

%.o: %.c
	$(CC) -c $(CFLAGS) $<
vi: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
clean:
	rm -f *.o vi
