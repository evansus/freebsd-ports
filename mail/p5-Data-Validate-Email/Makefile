# New ports collection makefile for:	p5-Data-Validate-Email
# Date created:		2009-01-07
# Whom:			Murilo Opsfelder <mopsfelder@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Data-Validate-Email
PORTVERSION=	0.04
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	A common email validation written in Perl

RUN_DEPENDS=	p5-Data-Validate-Domain>=0:${PORTSDIR}/dns/p5-Data-Validate-Domain \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Net-Domain-TLD>=0:${PORTSDIR}/dns/p5-Net-Domain-TLD

PERL_CONFIGURE=	yes

MAN3=		Data::Validate::Email.3

.include <bsd.port.mk>
