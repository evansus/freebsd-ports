# Created by: shadow@psoft.net
# $FreeBSD$

PORTNAME=	preps
PORTVERSION=	2.0.4
PORTREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/
PKGNAMESUFFIX=	-gui
DISTNAME=	preps-${PORTVERSION}
DIST_SUBDIR=	prep

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Problem reporting system

RUN_DEPENDS=	prepsdb_tool:${PORTSDIR}/devel/prepstools

USE_GMAKE=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix gtk20 gconf2 libgnomeui
USE_PGSQL=	yes
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	preps.schema

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pgsqldir=${LOCALBASE} \
			--with-plpgsqldir=${LOCALBASE} \
			--with-libprepsdir=${LOCALBASE} \
			--localstatedir=/var

post-patch:
	@${REINPLACE_CMD} -e 's|@PACKAGE@/gnome/help|gnome/help|g' \
		${WRKSRC}/help/C/Makefile.in

.include <bsd.port.mk>
