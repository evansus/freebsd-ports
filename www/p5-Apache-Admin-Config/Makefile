# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Apache-Admin-Config
PORTVERSION=	0.95
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manipulate Apache configuration files

PERL_CONFIGURE=	yes

MAN3=		Apache::Admin::Config.3

post-patch:
	${PERL} -pi -e 's/(!\$$)/0 && $1/;' \
		-e 's|(VERSION_FROM\s+=>\s+)(.*)(,.*)$$|$$1$$2$$3\nMAN3PODS=>{$$2=>q!\\\$$(INST_MAN3DIR)/${MAN3}!},|;' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
