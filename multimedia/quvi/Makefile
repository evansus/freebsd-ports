# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	quvi
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool for parsing flash media stream URLs

LICENSE=	GPLv3

BUILD_DEPENDS=	libquvi>=0.4.0:${PORTSDIR}/multimedia/libquvi
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	libquvi>=0.4.0:${PORTSDIR}/multimedia/libquvi

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_XZ=		yes

MAN1=		quvi.1
PLIST_FILES=	bin/quvi

.include <bsd.port.mk>
