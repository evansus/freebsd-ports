# Created by: Guixing Bai<khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	3.0.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

LICENSE=	AL2

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	31cef1a

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 300
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.post.mk>
