# Created by: stephen@math.missouri.edu
# $FreeBSD$

PORTNAME=	open-axiom
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	A computer algebra system

BUILD_DEPENDS=	sbcl:${PORTSDIR}/lang/sbcl \
		noweb:${PORTSDIR}/devel/noweb

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=sbcl
USE_GMAKE=	yes
USE_XORG=	x11 ice sm xpm
USES=		gettext iconv
MAKE_JOBS_UNSAFE=yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_SUB=	AXIOM_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}

post-patch:
	${REINPLACE_CMD} 's/test x$$oa_has_qt = xyes/false/' ${WRKSRC}/configure

.include <bsd.port.mk>
