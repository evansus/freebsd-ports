# New ports collection makefile for:	p5-File-Find-Rule-Filesys-Virtual
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	File-Find-Rule-Filesys-Virtual
PORTVERSION=	1.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	File::Find::Rule adapted to Filesys::Virtual

RUN_DEPENDS=	p5-File-Find-Rule>=0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Filesys-Virtual>=0:${PORTSDIR}/devel/p5-Filesys-Virtual \
		p5-Filesys-Virtual-Plain>=0:${PORTSDIR}/devel/p5-Filesys-Virtual-Plain

PERL_CONFIGURE=	yes

MAN3=		File::Find::Rule::Filesys::Virtual.3

.include <bsd.port.mk>
