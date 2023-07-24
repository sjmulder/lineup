DESTDIR?=
PREFIX?=	/usr/local

RM?=		rm -f
INSTALL?=	install

CFLAGS+=	-Wall -Wextra

all: lineup

clean:
	${RM} lineup

install: all
	${INSTALL} -d ${DESTDIR}${PREFIX}/bin
	${INSTALL} -m755 lineup ${DESTDIR}${PREFIX}bin/

uninstall: all
	${RM} ${DESTDIR}${PREFIX}/bin/lineup

.PHONY: all clean install uninstall
