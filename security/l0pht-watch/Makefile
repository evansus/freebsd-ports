# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$
#

PORTNAME=	l0pht-watch
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vs
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to report on what goes on in /tmp

PLIST_FILES=	bin/temp-watch
WRKSRC=		${WRKDIR}/temp-watch

ALL_TARGET=	OpenBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/temp-watch ${PREFIX}/bin

.include <bsd.port.mk>
