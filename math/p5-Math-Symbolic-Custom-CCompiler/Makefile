# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Symbolic-Custom-CCompiler
PORTVERSION=	1.03
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compile Math::Symbolic trees to C

BUILD_DEPENDS=	p5-Math-Symbolic>=0.509:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Inline>=0.44:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic::Custom::CCompiler.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
