# $FreeBSD$

PORTNAME=	poudriere
PORTVERSION=	3.0.99.20130601
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://fossil.etoilebsd.net/poudriere/tarball/ \
		LOCAL/bdrewery/${PORTNAME}/
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz?uuid=${FSL_CHKIN}

# Also maintained by bdrewery@FreeBSD.org
MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD

FSL_CHKIN=	c61b908704

MANCOMPRESSED=	yes
MAN8=	poudriere.8

OPTIONS_DEFINE=	ZSH

CONFLICTS_INSTALL=	poudriere-[0-9]*

PLIST_FILES=	etc/poudriere.conf.sample \
		etc/poudriere.d/hooks/pkgbuild.sh.sample \
		etc/rc.d/poudriere \
		bin/poudriere \
		libexec/poudriere/dirwatch \
		libexec/poudriere/dirempty \
		libexec/poudriere/make_index \
		share/poudriere/awk/dependency_loop.awk \
		share/poudriere/awk/humanize.awk \
		share/poudriere/awk/json.awk \
		share/poudriere/awk/siginfo_buildtime.awk \
		share/poudriere/html/index.html \
		share/poudriere/html/jquery-1.9.1.min.js \
		share/poudriere/html/logo.jpg \
		share/poudriere/html/poudriere.css \
		share/poudriere/html/poudriere.js \
		share/poudriere/bulk.sh \
		share/poudriere/clean.sh \
		share/poudriere/common.sh \
		share/poudriere/daemon.sh \
		share/poudriere/distclean.sh \
		share/poudriere/jail.sh \
		share/poudriere/options.sh \
		share/poudriere/ports.sh \
		share/poudriere/queue.sh \
		share/poudriere/status.sh \
		share/poudriere/testport.sh

PLIST_DIRS=	libexec/poudriere \
		etc/poudriere.d/hooks \
		etc/poudriere.d \
		share/poudriere/awk \
		share/poudriere/html \
		share/poudriere

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZSH}
PLIST_FILES+=	share/zsh/site-functions/_poudriere
PLIST_DIRSTRY+=	share/zsh/site-functions
PLIST_DIRSTRY+=	share/zsh/
.endif

post-install:
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${PREFIX}/share/zsh/site-functions/
	@${INSTALL_DATA} ${WRKSRC}/zsh-completions ${PREFIX}/share/zsh/site-functions/_poudriere
.endif

.include <bsd.port.mk>
