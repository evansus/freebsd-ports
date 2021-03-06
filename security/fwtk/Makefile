# Created by: gpalmer
# $FreeBSD$
#

PORTNAME=	fwtk
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	# pet portlint. Restricted source.
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.Z fwtk-doc-only.tar.Z
DIST_SUBDIR=	fwtk

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Toolkit used for building firewalls based on proxy services

RESTRICTED=	No form of redistribution is allowed
BROKEN=		Won't fetch, ftp site mentioned in 'IGNORE' has no readme. Web site changed hands?

# from scheidell@.  Can't find sources (did, but checksums wrong), can't see the 'readme' you mention below. if you can
# update this so that it fetches, and/or give valid, reproducable instructions on how to get permission to discribute
# source, then put this back in.

EXPIRATION_DATE=2012-09-01

OPTIONS=	X11 "Build X11 programs" On \
		JUMBO_PATCH "Build with  the \"Jumbo\" patch kit" Off \
		SKEY "Build this package with S/Key support" Off \
		SNK "Buil this package with DigiPath SNK support" Off

WRKSRC=		${WRKDIR}/fwtk
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	fixmake

MAN3=		auth.3
MAN5=		netperm-table.5
MAN8=		authmgr.8 authsrv.8 ftp-gw.8 http-gw.8 login-sh.8 netacl.8 \
		plug-gw.8 rlogin-gw.8 smap.8 smapd.8 tn-gw.8 x-gw.8
DOCS=		sample-report.txt manpages.ps admin_guide.ps user_guide.ps \
		overview.ps presentation.ps
SBIN_BINS=	authdump authload authmgr
LIBEXEC_BINS=	authsrv ftp-gw http-gw netacl plug-gw rlogin-gw smap smapd \
		tn-gw x-gw

.include <bsd.port.pre.mk>

.if defined(WITH_SKEY)
IGNORE=		does not build on 5.x and above with WITH_SKEY set because it requires S/Key libraries and headers
.endif

.if !defined(WITHOUT_X11)
MAN8+=		x-gw.8
LIBEXEC_BINS+=	x-gw
USE_XORG=	x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.MAKEFLAGS+=	-DWITHOUT_X11
.endif

.if defined(WITH_JUMBO_PATCH)
PATCHFILES=	trg-jumbo-20001114.diff
PATCH_SITES=	http://www.fwtk.org/fwtk/patches/
PATCH_DIST_STRIP=	-p1
.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.Z) \
	|| !exists(${DISTDIR}/${DIST_SUBDIR}/fwtk-doc-only.tar.Z)
IGNORE=	please read ftp://ftp.tislabs.com/pub/firewalls/toolkit/dist/README for details of how to obtain the FTWK source.  Put the files ${DISTNAME}.tar.Z and fwtk-doc-only.tar.Z into the directory ${DISTDIR}/${DIST_SUBDIR} and run make again
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<varargs.h>|<stdarg.h>|' \
		${WRKSRC}/http-gw/http-gw.h
	@${REINPLACE_CMD} -E 's|(defined\(AIX\))|\1 \&\& !defined(__FreeBSD__)|' \
		${WRKSRC}/x-gw/sig.c
.if defined(WITH_SKEY)
	@${REINPLACE_CMD} -E 's|^/\* (#define	AUTHPROTO_SKEY) \*/|\1|' \
		${WRKSRC}/auth.h
.endif
.if defined(WITH_SNK)
	@${REINPLACE_CMD} -E 's|^/\* (#define	AUTHPROTO_SNK) \*/|\1|' \
		${WRKSRC}/auth.h
.endif

pre-configure:
	@${MV} ${WRKSRC}/Makefile.config ${WRKSRC}/Makefile.config.in
	@${SED} -e s:%%FWTKSRCDIR%%:${WRKSRC}: \
		-e s:%%BSD_PREFIX%%:${PREFIX}: \
		${WRKSRC}/Makefile.config.in > ${WRKSRC}/Makefile.config
	@${MV} ${WRKSRC}/firewall.h ${WRKSRC}/firewall.h.in
	@${SED} -e s:%%FWTKSRCDIR%%:${WRKSRC}: \
		-e s:%%BSD_PREFIX%%:${PREFIX}: \
		${WRKSRC}/firewall.h.in > ${WRKSRC}/firewall.h

post-install:
	cd ${PREFIX}/libexec ; ${STRIP_CMD} ${SBIN_BINS} ${LIBEXEC_BINS}
	cd ${PREFIX}/libexec ; ${MV} ${SBIN_BINS} mqueue ../sbin
	${INSTALL_DATA} ${WRKSRC}/config/netperm-table \
		${PREFIX}/etc/netperm-table.sample
	if [ ! -f ${PREFIX}/etc/netperm-table ]; then \
		${INSTALL_DATA} ${WRKSRC}/config/netperm-table \
		${PREFIX}/etc/netperm-table;\
	fi
.for file in ${LIBEXEC_BINS}
	@${RM} -f ${PREFIX}/libexec/${file}.old
.endfor
.for man in ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} ${PREFIX}/man/man3
.endfor
.for man in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} ${PREFIX}/man/man5
.endfor
.for man in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} ${PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.for files in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${files} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
