# Created by: Andrew 'derfi' Sidorov <derfi@vei.ru>
# $FreeBSD$

PORTNAME=	nagvis
PORTVERSION=	1.7.2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/NagVis%201.7

MAINTAINER=	derfi@vei.ru
COMMENT=	Visualization addon for Nagios

LICENSE=	GPLv2

OPTIONS_DEFINE=	GRAPHVIZ
OPTIONS_SINGLE=	BROKER
OPTIONS_SINGLE_BROKER=	MKLIVESTATUS NDO2DB
OPTIONS_DEFAULT=	MKLIVESTATUS
MKLIVESTATUS_DESC=	Depend on mk-livestatus broker (preferred)
NDO2DB_DESC=	Depend on ndo2db broker
GRAPHVIZ_DESC=	Graphviz is needed for automaps

NO_BUILD=	yes
USE_PHP=	gd gettext mbstring session json pdo pdo_sqlite
WANT_PHP_WEB=	yes

.include <bsd.port.options.mk>

WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
DIRMODE?=	750
FILEMODE?=	640

SUB_LIST+=	WWW_OWNER=${WWW_OWNER} WWW_GROUP=${WWW_GROUP} \
		DIRMODE=${DIRMODE} FILEMODE=${FILEMODE}
SUB_FILES+=	pkg-install pkg-deinstall

.if ${PORT_OPTIONS:MNDO2DB}
USE_PHP+=	mysql
RUN_DEPENDS+=	ndo2db-3x:${PORTSDIR}/net-mgmt/ndoutils
.endif

.if ${PORT_OPTIONS:MMKLIVESTATUS}
RUN_DEPENDS+=	mk-livestatus>=0:${PORTSDIR}/net-mgmt/mk-livestatus
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

post-extract:
	@${RM} -f ${WRKSRC}/.gitignore ${WRKSRC}/install.sh ${WRKSRC}/INSTALL

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|@NAGVIS_WEB@|/nagvis|g' \
		-e 's|@NAGVIS_PATH@|${WWWDIR}|g' \
		${WRKSRC}/etc/apache2-nagvis.conf-sample
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/nagvis/|${WWWDIR}/|' \
		${WRKSRC}/etc/nagvis.ini.php-sample

do-install:
	@( cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}/ )

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL

.include <bsd.port.mk>
