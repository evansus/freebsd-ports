# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.6.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/xrdp/xrdp/${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}
DIST_SUBDIR?=	${PORTNAME}

PATCH_SITES=	http://www.club.kyutech.ac.jp/~meta/patches/xrdp/0.6.0/ \
		http://key2.jp/~meta/patches/xrdp/0.6.0/

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	An open source Remote Desktop Protocol (RDP) server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	x11 xfixes
USE_AUTOTOOLS=	autoconf:env automake:env libtool
GNU_CONFIGURE=	yes
USE_RC_SUBR=	xrdp

CONFIGURE_ARGS=	--localstatedir=/var
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFLICTS=	xrdp-devel-[0-9]*

USE_LDCONFIG=	${PREFIX}/lib/xrdp

OPTIONS_DEFINE=	DEBUG GATEWAY JP106
OPTIONS_DEFAULT=	JP106
GATEWAY_DESC=	Install xrdp as RDP gateway (no VNC backend)
JP106_DESC=	Install Japanese JP106 keymap

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-xrdpdebug
CFLAGS+=	-DXRDP_DEBUG
.endif

.if ${PORT_OPTIONS:MJP106}
PATCHFILES+=	patch-instfiles__Makefile.am \
	patch-instfiles__km-0411.ini \
	patch-instfiles__km-e0010411.ini \
	patch-instfiles__km-e0200411.ini \
	patch-instfiles__km-e0210411.ini
PLIST_SUB+=	JP106=""
.else
PLIST_SUB+=	JP106="@comment "
.endif

.if !${PORT_OPTIONS:MGATEWAY}
RUN_DEPENDS+=	Xvnc:${PORTSDIR}/net/vnc
.endif

MAN5=		sesman.ini.5 xrdp.ini.5
MAN8=		xrdp-sesman.8 xrdp-sesrun.8 xrdp.8

SUB_FILES=	pkg-message

post-patch:
.for f in sesman/sesman.ini sesman/startwm.sh xrdp/rsakeys.ini xrdp/xrdp.ini
	@${MV} ${WRKSRC}/$f ${WRKSRC}/$f.sample
.endfor

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-install:
.for f in rsakeys.ini sesman.ini startwm.sh xrdp.ini
	@if [ ! -f ${PREFIX}/etc/xrdp/$f ]; then \
		${CP} -p ${PREFIX}/etc/xrdp/$f.sample ${PREFIX}/etc/xrdp/$f ; \
	fi
.endfor
	@if cmp -s ${PREFIX}/etc/xrdp/rsakeys.ini.sample ${PREFIX}/etc/xrdp/rsakeys.ini; then \
		${PREFIX}/bin/xrdp-keygen xrdp ${PREFIX}/etc/xrdp/rsakeys.ini; fi
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
