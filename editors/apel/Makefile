# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apel
PORTVERSION=	10.8.${SNAPDATE}
PORTREVISION=	2
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Portable Emacs Library

LICENSE=	GPLv2

.if ${FLAVOR:U} == devel_full || ${FLAVOR:U} == devel_nox
BROKEN=		pces-e20.el:27:1: Error: Wrong type argument: stringp
.endif

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	wanderlust
GH_TAGNAME=	d146ddb

SNAPDATE=	20190407
NO_ARCH=	yes

ALL_TARGET=	elc
MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
	    ${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR} ; \
	done)

.include <bsd.port.mk>
