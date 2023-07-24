DESTDIR?=
PREFIX?=	/usr/local
MANPREFIX?=	${PREFIX}/man

RM?=		rm -f
INSTALL?=	install

CFLAGS+=	-Wall -Wextra

all: lineup

clean:
	${RM} lineup

install: all
	${INSTALL} -d ${DESTDIR}${PREFIX}/bin
	${INSTALL} -d ${DESTDIR}${MANPREFIX}/man1
	${INSTALL} -m755 lineup   ${DESTDIR}${PREFIX}/bin/
	${INSTALL} -m644 lineup.1 ${DESTDIR}${MANPREFIX}/man1/

uninstall: all
	${RM} ${DESTDIR}${PREFIX}/bin/lineup
	${RM} ${DESTDIR}${MANPREFIX}/man1/lineup.1

.PHONY: all clean install uninstall
