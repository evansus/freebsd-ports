# Created by: mwlucas
# $FreeBSD$

PORTNAME=	mod_auth_xradius
PORTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_auth_xradius/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mwlucas@FreeBSD.org
COMMENT=	Enables RADIUS authentication

MAKE_JOBS_SAFE=  yes

USE_APACHE=	22
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	${APACHEMODDIR}/mod_auth_xradius.so

.include <bsd.port.mk>
