# ex:ts=8
# New ports collection makefile for:	libdbi
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi
PORTVERSION=	0.8.4
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Database Independent Abstraction Layer for C

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-O20|${CFLAGS}|g" -e "s|-std=gnu99||g" \
		 ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/driver-guide
	${INSTALL_DATA} ${WRKSRC}/doc/driver-guide/*.html \
		${DOCSDIR}/driver-guide
	@${MKDIR} ${DOCSDIR}/programmers-guide
	${INSTALL_DATA} ${WRKSRC}/doc/programmers-guide/*.html \
		${DOCSDIR}/programmers-guide
.endif

.include <bsd.port.mk>
