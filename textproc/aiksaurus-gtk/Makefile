# $FreeBSD$

PORTREVISION=	11
CATEGORIES=	textproc deskutils
PKGNAMESUFFIX=	-gtk

COMMENT=	A GTK+2 front-end for Aiksaurus, a thesaurus

LIB_DEPENDS=	Aiksaurus-1.2.0:${PORTSDIR}/textproc/aiksaurus

MASTERDIR=	${.CURDIR}/../aiksaurus
PKGDIR=		${.CURDIR}

USE_GNOME=	gtk20
CONFIGURE_ARGS=--with-gtk

pre-install:
	@${REINPLACE_CMD} -e 's|base [$$][(]GTKSRCDIR[)] data|$$(GTKSRCDIR)|g' \
		${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
