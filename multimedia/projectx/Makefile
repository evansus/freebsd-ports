# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	projectx
PORTVERSION=	0.91.0
CATEGORIES=	multimedia java
MASTER_SITES=	SF/project-x/project-x/ProjectX_${PORTVERSION}.00
DISTNAME=	ProjectX_${PORTVERSION}
DISTFILES=	ProjectX_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	DVB (mpeg) cutting/demux tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	project-x.sh
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/Project-X_${PORTVERSION}
EXTRACT_BEFORE_ARGS+=	-aq

do-configure:
	${SED} -e "s|^javac|${JAVAC}|" ${WRKSRC}/build.sh >${WRKSRC}/build-fbsd.sh

do-build:
	cd ${WRKSRC} && ${MKDIR} build && ${SH} build-fbsd.sh

do-install:
	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/ProjectX.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/commons-net-1.3.0.jar ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jakarta-oro-2.0.8.jar ${DATADIR}/lib
	${MKDIR} ${DATADIR}/htmls/images ${DATADIR}/htmls/de
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/htmls/*.html ${DATADIR}/htmls
	${INSTALL_DATA} ${WRKSRC}/htmls/de/*.html ${DATADIR}/htmls/de
	${INSTALL_DATA} ${WRKSRC}/htmls/images/* ${DATADIR}/htmls/images
	${INSTALL_SCRIPT} ${WRKDIR}/project-x.sh ${PREFIX}/bin/project-x

.include <bsd.port.mk>
