# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	fabric
PORTVERSION=	1.6.1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Simple pythonic remote deployment tool

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.10.0:${PORTSDIR}/security/py-paramiko
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}fudge>0:${PORTSDIR}/devel/py-fudge \
		nosetests:${PORTSDIR}/devel/py-nose

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install nose for test suite
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:C/f/F/}

regression-test: build
	@cd ${WRKSRC} && nosetests -v

.include <bsd.port.mk>
