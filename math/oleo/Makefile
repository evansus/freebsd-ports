# Created by: mr
# $FreeBSD$

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU spreadsheet for X11 and terminals

USE_PERL5_BUILD=	yes
USES=		bison
USE_AUTOTOOLS=	autoconf213
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-x --without-xlt --without-SciPlot

INFO=		oleo
PORTDOCS=	AUTHORS FAQ

OPTIONS_DEFINE=	MOTIF NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOTIF}
LIB_DEPENDS+=	plot:${PORTSDIR}/graphics/plotutils \
		Xbae:${PORTSDIR}/x11-toolkits/xbae \
		XmHTML:${PORTSDIR}/x11-toolkits/xmhtml
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-motif
.else
USE_XORG=	xt ice sm
CONFIGURE_ARGS+=	--without-motif
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
.for pof in en fr nl
	@${REINPLACE_CMD} -e "s|CHARSET|ISO-8859-1|;s|ENCODING|8bit|"	\
		${WRKSRC}/po/${pof}.po
.endfor
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|am: install-docDATA|am:|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-info-am install-htmlDATA|install-info-am|" \
		${WRKSRC}/doc/Makefile.in
.endif

pre-build:
.for file in src/io-term.c
	cd ${WRKSRC} && ${MV} ${file} ${file}.pre_iconv \
		&& iconv -c -t ascii ${file}.pre_iconv > ${file} || ${TRUE}
.endfor

.include <bsd.port.mk>
