# New ports collection makefile for:   vgb-bin
# Date created:		04 Aug 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	vgb
PORTVERSION=	3.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/VGB/
PKGNAMESUFFIX=	-bin
DISTNAME=	VGB${PORTVERSION:S/.//}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Nintendo GameBoy(tm) emulator (closed binary version of vgb)

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

IA32_BINARY_PORT=	yes
NO_BUILD=	no
NO_WRKSUBDIR=	no

INSTALL_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vgb ${PREFIX}/bin
	@${INSTALL_DIR} ${PREFIX}/share/vgb
	@${INSTALL_DATA} ${WRKSRC}/CART.GB ${PREFIX}/share/vgb
.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${PREFIX}/share/doc/vgb
	@${INSTALL_DATA} ${WRKSRC}/VGB.html ${PREFIX}/share/doc/vgb
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>
