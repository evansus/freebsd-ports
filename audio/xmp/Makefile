# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	xmp
PORTVERSION=	4.0.6
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Player for many different Amiga and PC module formats

LICENSE=	GPLv2

LIB_DEPENDS=	xmp:${PORTSDIR}/audio/libxmp

USES=		pkgconfig
USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xmp.1

CONFIG_FILES=	xmp.conf modules.conf

OPTIONS_DEFINE=	ALSA PULSEAUDIO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--enable-alsa
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse-simple:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\ install-conf||' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${ETCDIR}
.for f in ${CONFIG_FILES}
	@test -f ${ETCDIR}/${f} || ${INSTALL_DATA} ${WRKSRC}/src/${f} ${ETCDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.mk>
