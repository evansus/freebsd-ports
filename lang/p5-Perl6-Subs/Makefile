# New ports collection makefile for:	lang/p5-Perl6-Subs
# Date created:				07 January 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl6-Subs
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl6::Subs - Define your subroutines in the Perl 6 style

BUILD_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Perl6::Subs.3

.include <bsd.port.mk>
