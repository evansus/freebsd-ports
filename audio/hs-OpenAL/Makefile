# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	OpenAL
PORTVERSION=	1.4.0.2
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A binding to the OpenAL cross-platform 3D audio API

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	ObjectName StateVar Tensor
USE_OPENAL=	al

INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
