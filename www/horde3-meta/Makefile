# New ports collection makefile for:	horde
# Date created:			24 February 2007
# Whom:				Beech Rintoul <beech@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meta
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	www
MASTER_SITES=	# Empty
DISTFILES=	# None

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Meta port for the horde framework

NO_BUILD=	yes
LHORDEDIR?=	www/horde

OPTIONS=	ANSEL "Photo Gallery" off	\
		CHORA "CVS Web Viewer" off	\
		DIMP "Dynamic Imp" off	\
		GOLLEM "Web-Based File Manager" off	\
		HERMES "Time Tracking Application" off	\
		HPASSWD "Password Changing Module" off	\
		IMP "IMAP Webmail System" on	\
		INGO "Email-Filter Management" on	\
		JETA "Java SSH Applets" off	\
		KRONOLITH "Calendar Application" off \
		MIMP "Mobile Webmail System" off	\
		MNEMO "Notes and Memo Application" off	\
		NAG "Task List Manager" on	\
		NIC "Network Monitor" off	\
		TREAN "Bookmark Manager" off	\
		TURBA "Contact Management" on	\
		VACATION "Vacation & Auto Respond" off	\
		WHUPS "Bug Tracking/Ticket System" off	\
		KLUTZ "Comic Strip Viewer" off

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde3-base

.if !defined(WITHOUT_IMP)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/imp/index.php:${PORTSDIR}/mail/horde3-imp
.endif

.if defined(WITH_MIMP)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/mimp/index.php:${PORTSDIR}/mail/horde3-mimp
.endif

.if defined(WITH_DIMP)
RUN_DEPENDS+= ${LOCALBASE}/${LHORDEDIR}/dimp/compose.php:${PORTSDIR}/mail/horde3-dimp
.endif

.if !defined(WITHOUT_INGO)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/ingo/filters.php:${PORTSDIR}/mail/horde3-ingo
.endif

.if !defined(WITHOUT_TURBA)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/turba/minisearch.php:${PORTSDIR}/mail/horde3-turba
.endif

.if defined(WITH_KRONOLITH)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/kronolith/index.php:${PORTSDIR}/deskutils/horde3-kronolith
.endif

.if defined(WITH_MNEMO)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/mnemo/index.php:${PORTSDIR}/deskutils/horde3-mnemo
.endif

.if !defined(WITHOUT_NAG)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/nag/data.php:${PORTSDIR}/deskutils/horde3-nag
.endif

.if defined(WITH_CHORA)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/chora/index.php:${PORTSDIR}/devel/horde3-chora
.endif

.if defined(WITH_GOLLEM)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/gollem/index.php:${PORTSDIR}/ftp/horde3-gollem
.endif

.if defined(WITH_JETA)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/jeta/index.php:${PORTSDIR}/security/horde3-jeta
.endif

.if defined(WITH_HPASSWD)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/passwd/index.php:${PORTSDIR}/www/horde3-passwd
.endif

.if defined(WITH_VACATION)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/vacation/main.php:${PORTSDIR}/mail/horde3-vacation
.endif

.if defined(WITH_TREAN)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/trean/data.php:${PORTSDIR}/www/horde3-trean
.endif

.if defined(WITH_NIC)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/nic/status.php:${PORTSDIR}/net-mgmt/horde3-nic
.endif

.if defined(WITH_ANSEL)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/ansel/gallery.php:${PORTSDIR}/www/horde3-ansel
.endif

.if defined(WITH_WHUPS)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/whups/index.php:${PORTSDIR}/devel/horde3-whups
.endif

.if defined(WITH_HERMES)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/hermes/index.php:${PORTSDIR}/deskutils/horde3-hermes
.endif

.if defined(WITH_KLUTZ)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/klutz/index.php:${PORTSDIR}/deskutils/horde3-klutz
.endif

post-configure:
	@${CAT} ${FILESDIR}/post-configure-message

do-install:
	@${DO_NADA}

.include <bsd.port.post.mk>
