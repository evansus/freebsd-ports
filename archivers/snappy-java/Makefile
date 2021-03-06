# Created by: Radim Kolar <hsn@filez.com>
# $FreeBSD$

# Note to committers:
# With each version update, a new maven repository must be created and distributed
# so build is repeatable and cluster-safe.

PORTNAME=	snappy
PORTVERSION=	1.0.4.1
CATEGORIES=	archivers java
MASTER_SITES=	GITHUB:source1 \
		http://snappy.googlecode.com/files/:source2 \
		LOCAL/jgh/archivers/${PORTNAME}/:source3
PKGNAMESUFFIX=	java
DISTFILES+=	snappy-${PORTVERSION}.tar.gz:source1 \
		snappy-${PORTVERSION:R}.tar.gz:source2 \
		FreeBSD-snappy-${PORTVERSION}-maven-repository.tar.gz:source3
EXTRACT_ONLY=	snappy-${PORTVERSION}.tar.gz \
		FreeBSD-snappy-${PORTVERSION}-maven-repository.tar.gz

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Fast compressor/decompressor library

LICENSE=	AL2

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3

GH_ACCOUNT=	xerial
GH_PROJECT=	snappy-java
GH_TAGNAME=	snappy-java-${PORTVERSION}
GH_COMMIT=	487f82d
USE_GITHUB=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.7
USE_GMAKE=	yes

PLIST_FILES=	%%JAVAJARDIR%%/snappy-java.jar

post-patch-script:
	@${REINPLACE_CMD} -e 's|curl.*||g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|MVN:=mvn|MVN:=mvn -Dmaven.repo.local=${WRKDIR}/repository --offline|g' \
		${WRKSRC}/Makefile

pre-build:
	@${MKDIR} ${WRKSRC}/target
	@${CP} ${DISTDIR}/snappy-${PORTVERSION:R}.tar.gz ${WRKSRC}/target/

do-build: pre-build
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} \
	${GMAKE} && ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/repository --offline test

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${PORTVERSION}.jar ${JAVAJARDIR}/snappy-java.jar

.include <bsd.port.mk>
