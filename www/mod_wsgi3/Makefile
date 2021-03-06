# $FreeBSD$

PORTNAME=	mod_wsgi
PORTVERSION=	3.4
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python WSGI adapter module for Apache

LICENSE=	AL2

MAKE_JOBS_SAFE=	yes

#LATEST_LINK=	mod_wsgi
CONFLICTS=	${PKGNAMEPREFIX}mod_wsgi-2.* mod_wsgi-2.*

PROJECTHOST=	modwsgi

USE_APACHE=	22+
USE_PYTHON=	2.5+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 300 && ${PYTHON_REL} < 310
IGNORE=		is unsupported with Python 3.0
.endif

pre-everything::
	@${ECHO_MSG} "======================= ATTENTION! ======================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to use daemon mode you will need to make sure"
	@${ECHO_MSG} "Apache and APR include thread support."
	@${ECHO_MSG}
	@${ECHO_MSG} "========================================================="

post-install:
	@${APXS} -e -a -n "${SHORTMODNAME}" "${APACHEMODDIR}/${MODULENAME}.so"
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
