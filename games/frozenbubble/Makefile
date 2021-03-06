# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	frozenbubble
PORTVERSION=	2.2.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/
DISTNAME=	frozen-bubble-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Throw colourful bubbles to build groups and destroy the groups

BUILD_DEPENDS=	p5-SDL>=0:${PORTSDIR}/devel/p5-SDL
RUN_DEPENDS=	p5-SDL>=0:${PORTSDIR}/devel/p5-SDL

USE_SDL=	mixer sdl pango
USE_GMAKE=	yes
USE_BZIP2=	yes
PERL_CONFIGURE=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/c_stuff
REINPLACE_ARGS=	-i ""

MAN6=		frozen-bubble-editor.6 frozen-bubble.6

LEXECDIR=	${PREFIX}/libexec/${PORTNAME}

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
RUN_DEPENDS+=	p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		-e '/MANDIR/s|$$(DATADIR)|${PREFIX}|' \
		 ${WRKSRC}/settings.mk
	@${REINPLACE_CMD} -e 's|sdl-config|\${SDL_CONFIG}|g' \
		${WRKSRC}/c_stuff/Makefile.PL

pre-install:
	${REINPLACE_CMD} -E -e \
		"s,^(\\\$$FPATH[[:space:]]+=[[:space:]]+).*,\1'${DATADIR}';," \
		-e \
		"s,^(\\\$$FLPATH[[:space:]]+=[[:space:]]+).*,\1'${LEXECDIR}';,"\
		${WRKSRC}/c_stuff/lib/fb_config.pm
	${CP} ${WRKSRC}/c_stuff/lib/fb_config.pm ${WRKSRC}/c_stuff/blib/lib/

do-install:
	cd ${WRKSRC}/c_stuff && ${GMAKE} install
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/po && ${GMAKE} install
.endif
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/frozen-bubble ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/frozen-bubble-editor ${PREFIX}/bin/
	${INSTALL_MAN} ${MAN6:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man6/
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "gfx snd data" ${DATADIR}/)
	${MKDIR} ${LEXECDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/server/fb-server ${LEXECDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
