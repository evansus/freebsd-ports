# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Return-Value
PORTVERSION=	1.666002
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Return::Value - Polymorphic Return Values

PERL_CONFIGURE=	yes

MAN3=	Return::Value.3

post-patch:
	${PERL} -pi -e 's/^Carp::cluck/# Carp::cluck/' ${WRKSRC}/lib/Return/Value.pm

.include <bsd.port.mk>
