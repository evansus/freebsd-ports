# $FreeBSD$

PORTNAME=	ua
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Finds sets of identical files

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

MAN1=	kua.1 ua.1
PLIST_FILES=	bin/kua bin/ua
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
