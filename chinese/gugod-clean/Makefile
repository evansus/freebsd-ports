# New ports collection makefile for:	gugod-clean
# Date Created:                         21 Jun 2001
# Whom:                                 Kang-min Liu <gugod@gugod.org>
# $FreeBSD$

PORTNAME=	gugod-clean
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/gugod/

MAINTAINER=	gugod@gugod.org
COMMENT=	A pretty font modifyed from X11 schumacher-clean that match kcfonts

RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTFILES=	gugod16.bdf gugod18.bdf gugod20.bdf gugod22.bdf

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
SHAREMODE=	644
XFONTDIR=	${LOCALBASE}/lib/X11/fonts/local

do-install:
	@${MKDIR} ${XFONTDIR}
.for i in ${FONTFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${XFONTDIR}
.endfor
	@cd ${XFONTDIR} ; mkfontdir

.include <bsd.port.mk>
