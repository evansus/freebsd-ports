# New ports collection makefile for:	linux-hicolor-icon-theme
# Date created:		7 February 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hicolor-icon-theme
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	x11-themes linux
MASTER_SITES=	# empty
PKGNAMEPREFIX=	linux-
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-color icon theme shell from the FreeDesktop project

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

CONFLICTS=	linux-f8-hicolor-icon-theme-[0-9]* linux-f10-hicolor-icon-theme-[0-9]*

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
PLIST_FILES=	usr/share/icons/hicolor

do-install:
	${INSTALL} -d ${PREFIX}/usr/share/icons
	${LN} -fs ${LOCALBASE}/share/icons/hicolor ${PREFIX}/usr/share/icons

.include <bsd.port.mk>
