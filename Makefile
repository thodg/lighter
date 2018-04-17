
CFLAGS = -O0 -ggdb -W -Wall -Werror -fpic

all:

LIGHTER = lighter
LIGHTER_LDFLAGS =
LIGHTER_LIBS =
LIGHTER_H = ../fb/fb.h easy.h
LIGHTER_OBJ = ../fb/fb.o lighter.o easy_trigonometry.o
${LIGHTER_OBJ}: ${LIGHTER_H}
${LIGHTER}: ${LIGHTER_OBJ}
	${CC} ${CFLAGS} ${LIGHTER_LDFLAGS} -o $@ ${LIGHTER_OBJ} ${LIGHTER_LIBS}
all: ${LIGHTER}
CLEANFILES += ${LIGHTER} ${LIGHTER_OBJ}

clean:
	rm -f ${CLEANFILES}

.PHONY: all clean
