# New ports collection makefile for:	tiarra
# Date Created:		Jul 27 2006
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tiarra
PORTVERSION=	20100212
PORTREVISION=	1
CATEGORIES=	japanese irc ipv6
MASTER_SITES=	http://www.clovery.jp/tiarra/archive/2010/02/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IRC Proxy software

RUN_DEPENDS=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6

USE_PERL5_RUN=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	tiarra
NO_BUILD=	yes

USERS=		${TIARRA_USER}
GROUPS=		${TIARRA_GROUP}

SUB_FILES=	pkg-message
SUB_LIST=	TIARRA_USER=${TIARRA_USER}

PLIST_SUB=	TIARRA_USER=${TIARRA_USER} \
		TIARRA_GROUP=${TIARRA_GROUP}

TIARRA_USER=	tiarra
TIARRA_GROUP=	tiarra

do-install:
	@${MKDIR} ${PREFIX}/tiarra
	@${TAR} cfC - ${WRKSRC} . | ${TAR} xfC - ${PREFIX}/tiarra
	@if [ ! -f ${PREFIX}/tiarra/tiarra.conf ]; then \
		${CP} -p ${PREFIX}/tiarra/sample.conf \
			${PREFIX}/tiarra/tiarra.conf; \
	fi
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/tiarra
	@${MKDIR} ${PREFIX}/tiarra/log
	@${CHOWN} -R ${TIARRA_USER}:${TIARRA_GROUP} ${PREFIX}/tiarra/log
	@${CHMOD} o-rwx ${PREFIX}/tiarra/log
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
