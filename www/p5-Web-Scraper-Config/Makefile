# New ports collection makefile for:	p5-Web-Scraper-Config
# Date created:		2008-01-30
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Web-Scraper-Config
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Run Web::Scraper From Config Files

BUILD_DEPENDS=	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Web-Scraper>=0:${PORTSDIR}/www/p5-Web-Scraper
RUN_DEPENDS=	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Web-Scraper>=0:${PORTSDIR}/www/p5-Web-Scraper

PERL_CONFIGURE=	yes

MAN3=		Web::Scraper::Config.3

.include <bsd.port.mk>
