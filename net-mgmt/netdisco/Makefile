# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	netdisco
PORTVERSION=	1.1
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Web-based network management tool for moderate to large networks

OPTIONS_DEFINE=	GRAPHVIZ OUIDL MIBS
OPTIONS_DEFAULT=GRAPHVIZ MIBS
MIBS_DESC=	Depend on net-mgmt/netdisco-mibs
OUIDL_DESC=	Download oui.txt file
GRAPHVIZ_DESC=	Install GraphViz for network map support

RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI	\
		p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-SNMP-Info>=0:${PORTSDIR}/net-mgmt/p5-SNMP-Info \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-DB_File-Lock>=0:${PORTSDIR}/devel/p5-DB_File-Lock \
		p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session \
		p5-Net-NBName>=0:${PORTSDIR}/net/p5-Net-NBName \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-MasonX-Request-WithApacheSession>=0:${PORTSDIR}/www/p5-MasonX-Request-WithApacheSession \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager

USERS=		netdisco
GROUPS=		netdisco

USE_PERL5=	yes
USE_PGSQL=	yes
USE_APACHE_RUN=	22+

USE_RC_SUBR=	netdisco

NO_BUILD=	yes

NETDISCO_RUNDIR=/var/run
NETDISCO_DBDIR=	/var/db/netdisco

SUB_FILES=	pkg-message
SUB_LIST=	NETDISCO_DBDIR=${NETDISCO_DBDIR} NETDISCO_RUNDIR=${NETDISCO_RUNDIR} NETDISCO_USER=${USERS}
PLIST_SUB=	NETDISCO_DBDIR=${NETDISCO_DBDIR} NETDISCO_RUNDIR=${NETDISCO_RUNDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALTER_FILES=	netdisco netdisco.conf netdisco_apache.conf \
		netdisco_apache_dir.conf netdisco.crontab sql/pg

CONFIG_FILES=	netdisco.conf netdisco.crontab netdisco-topology.txt \
		netdisco_apache.conf netdisco_apache_dir.conf

DOCS=		doc/*.pod doc/*.html INSTALL README* UPGRADE

.include <bsd.port.pre.mk>

MIBSDIR=	${PREFIX}/share/netdisco-mibs
.if ${PORT_OPTIONS:MMIBS}
RUN_DEPENDS+=	${MIBSDIR}/mib_index.txt:${PORTSDIR}/net-mgmt/netdisco-mibs
BUILD_DEPENDS+=	${MIBSDIR}/mib_index.txt:${PORTSDIR}/net-mgmt/netdisco-mibs
. include 	"${.CURDIR}/../netdisco-mibs/bsd.port.netdisco.mk"
MIBINCLUDES=
. for mib in ${MIBDIRS}
MIBINCLUDES+=	${MIBSDIR}/${mib},
. endfor
MIBINCLUDES:=${MIBINCLUDES:S/,$//}
.else
MIBINCLUDES="#please add here mibs dirs list (at least snmp and rfc ones)"
.endif

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	p5-Graph>=0:${PORTSDIR}/math/p5-Graph	\
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
.endif

.if ${PORT_OPTIONS:MOUIDL}
PLIST_SUB+=	OUIDL=""
.else
PLIST_SUB+=	OUIDL="@comment "
.endif

pre-install:
.	for i in ${ALTER_FILES}
		@(${MV} ${WRKSRC}/${i}.bak ${WRKSRC}/${i} 2>/dev/null || ${TRUE})
.	endfor

	cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's#%%WWWDIR%%#${WWWDIR}#g'		\
			-e 's#%%PREFIX%%#${PREFIX}#g'		\
			-e 's#%%DATADIR%%#${DATADIR}#g'		\
			-e 's#%%NETDISCO_RUNDIR%%#${NETDISCO_RUNDIR}#g'		\
			-e 's#%%NETDISCO_USER%%#${USERS}#g'		\
			-e 's#%%NETDISCO_GROUP%%#${GROUPS}#g'		\
			-e 's#%%NETDISCO_DBDIR%%#${NETDISCO_DBDIR}#g'		\
			-e 's#%%ETCDIR%%#${ETCDIR}#g'		\
			-e 's#%%SITE_PERL%%#${SITE_PERL}#g'	\
			-e 's#%%LOCALBASE%%#${LOCALBASE}#g'	\
			-e 's#%%APACHEMODDIR%%#${APACHEMODDIR}#g'	\
			-e 's#%%APACHEETCDIR%%#${APACHEETCDIR}#g'	\
			-e 's#%%MIBINCLUDES%%#${MIBINCLUDES}#g'	\
			${ALTER_FILES}

do-install:
.	for i in netdisco bin/parse_mac bin/port_control bin/parse_kismet_ap
		cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${PREFIX}/bin
.	endfor

	${MKDIR} ${WWWDIR}
	cd ${WRKSRC}/html && ${INSTALL_DATA} autohandler *.* ${WWWDIR}

	${MKDIR} ${WWWDIR}/doc
	cd ${WRKSRC}/html/doc && ${INSTALL_DATA} *.* ${WWWDIR}/doc

	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

	${MKDIR} ${WWWDIR}/mason

	${INSTALL_DATA} ${WRKSRC}/netdisco.pm ${SITE_PERL}

	${INSTALL} -d -m 750 -o ${USERS} -g ${GROUPS} ${ETCDIR}

.	for i in ${CONFIG_FILES}
		cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${ETCDIR}/${i}.sample
		@(if [ ! -f ${ETCDIR}/${i} ]; then	\
			${INSTALL} -m 640 -o ${USERS} -g ${GROUPS} ${ETCDIR}/${i}.sample ${ETCDIR}/${i};	\
		fi)
.	endfor

	${CHOWN} -R ${USERS}:${GROUPS} ${ETCDIR}
	${CHMOD} -R 660 ${ETCDIR}/*

	${INSTALL} -d ${DATADIR}/sql

	cd ${WRKSRC}/sql && \
	   ${INSTALL_DATA} *.sql pg ${DATADIR}/sql

	${INSTALL_DATA} ${WRKSRC}/Makefile ${DATADIR}

.	if !defined(PACKAGE_BUILDING)
		@(if [ -d ${LOCALBASE}/${APACHEETCDIR}/Includes ] ; then							\
			${ECHO_MSG} "===> Adding config in ${LOCALBASE}/${APACHEETCDIR}/Includes...";					\
			test -L ${LOCALBASE}/${APACHEETCDIR}/Includes/netdisco_apache.conf || \
				${LN} -s ${ETCDIR}/netdisco_apache.conf ${LOCALBASE}/${APACHEETCDIR}/Includes/netdisco_apache.conf; \
			test -L ${LOCALBASE}/${APACHEETCDIR}/Includes/netdisco_apache_dir.conf || \
				${LN} -s ${ETCDIR}/netdisco_apache_dir.conf ${LOCALBASE}/${APACHEETCDIR}/Includes/netdisco_apache_dir.conf;\
		fi)
.	endif

.	if ${PORT_OPTIONS:MOUIDL}
		${FETCH_CMD} -q -o ${DATADIR}/oui.txt http://standards.ieee.org/develop/regauth/oui/oui.txt
.	endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
