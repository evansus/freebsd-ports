# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	gprbuild
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gprbuild-gpl-2012-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	draco@marino.st
COMMENT=	Adacore multi-language software build tool

LICENSE=	GPLv3

BUILD_DEPENDS+=	xmlada>=3.2:${PORTSDIR}/textproc/xmlada

EXAMPLESDIR=	share/examples/gprbuild
DOCSDIR=	share/doc/gprbuild
WRKSRC=		${WRKDIR}/gprbuild-2012-src
SNAPSHOT=	20120510
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES+=		ada

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:L}${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,@AUXPREFIX@,${PREFIX}/gcc-aux," \
	  ${WRKSRC}/share/gprconfig/compilers.xml

.include <bsd.port.post.mk>
