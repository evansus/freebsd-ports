# New ports collection makefile for:	gtk-recordmydesktop
# Date created:				2010-07-16
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gtk-recordmydesktop
PORTVERSION=	0.3.8
PORTREVISION=	2
CATEGORIES=	multimedia deskutils
MASTER_SITES=	SF/recordmydesktop/gtk-recordMyDesktop/${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ frontend to recordMyDesktop

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PYTHON=	-2.7
USE_GNOME=	gtk20 pygtk2 desktopfileutils
INSTALL_ICONS=	yes

post-build:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/gtk-recordMyDesktop

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
