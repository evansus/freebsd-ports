# Created by: Stefan Zehl <sec@42.org>
# $FreeBSD$

PORTNAME=	libsidplay
PORTVERSION=	1.36.59
CATEGORIES=	audio emulators
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore SID-chip emulator library to play SID music files

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS=	--enable-optendian --enable-optfixpoint
.endif

.include <bsd.port.post.mk>
