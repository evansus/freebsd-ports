# New ports collection Makefile for:	telepathy-qt
# Date created:				2008-02-10
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	telepathy-qt
PORTVERSION=	0.14.1
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	SF/tapioca-voip/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Framework for VoIP and IP applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		cmake
CMAKE_SOURCE_PATH=	..
USE_QT4=	corelib qmake_build uic_build moc_build rcc_build xml dbus
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../CMakeLists.txt

.include <bsd.port.mk>
