# Created by: olgeni@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/trunk/misc/shared-mime-info/Makefile 18394 2013-04-26 21:29:28Z kwm $

PORTNAME=	shared-mime-info
PORTVERSION=	1.1
CATEGORIES=	misc gnome
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MIME types database from the freedesktop.org project

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mimedb
USE_GMAKE=	yes
USES=		pathfix pkgconfig gettext
USE_GNOME=	glib20 libxml2 intltool intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

MAN1=		update-mime-database.1

SUB_FILES=	pkg-install
SUB_LIST=	MIMEDIRS="${MIMEDIRS:O:u}"

MIMEDIRS=	${LOCALBASE}/share/mime \
		${PREFIX}/share/mime
MIMESUBDIRS=	application audio image inode message model multipart \
		packages text video x-epoc x-content

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/update-mime-database.c

post-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
