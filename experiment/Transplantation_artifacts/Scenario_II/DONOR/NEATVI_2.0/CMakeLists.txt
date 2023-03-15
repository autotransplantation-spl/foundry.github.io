cmake_minimum_required(VERSION 3.15)
project(NEAVI C)

set(CMAKE_C_STANDARD 99)

add_executable(NEAVI cmd.c
        conf.c
        conf.h
        dir.c
        ex.c
        kmap.h
        lbuf.c
        led.c
        Makefile
        model.xml
        mot.c
        README
        reg.c
        regex.c
        regex.h
        ren.c
        rset.c
        sbuf.c
        syn.c
        term.c
        uc.c
        vi.c
        vi.h)