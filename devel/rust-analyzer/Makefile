# $FreeBSD$

PORTNAME=	rust-analyzer
DISTVERSION=	2020-06-08
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Experimental Rust compiler front-end for IDEs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_TUPLE=	rust-lang:chalk:329b7f3fdd2431ed6f6778cde53f22374c7d094c:chalkderive
CARGO_CRATES=	addr2line-0.12.1 \
		aho-corasick-0.7.10 \
		anyhow-1.0.31 \
		anymap-0.12.1 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		backtrace-0.3.48 \
		base64-0.12.1 \
		bitflags-1.2.1 \
		bstr-0.2.13 \
		cargo_metadata-0.10.0 \
		cc-1.0.54 \
		cfg-if-0.1.10 \
		chalk-derive-0.11.0 \
		chalk-engine-0.11.0 \
		chalk-ir-0.11.0 \
		chalk-solve-0.11.0 \
		clicolors-control-1.0.1 \
		cloudabi-0.0.3 \
		console-0.10.3 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.2 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.2 \
		crossbeam-utils-0.7.2 \
		difference-2.0.0 \
		drop_bomb-0.1.4 \
		dtoa-0.4.5 \
		either-1.5.3 \
		ena-0.14.0 \
		encode_unicode-0.3.6 \
		env_logger-0.7.1 \
		filetime-0.2.10 \
		fixedbitset-0.2.0 \
		fnv-1.0.7 \
		fs_extra-1.1.0 \
		fsevent-0.4.0 \
		fsevent-sys-2.0.1 \
		fst-0.4.4 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		getrandom-0.1.14 \
		gimli-0.21.0 \
		globset-0.4.5 \
		goblin-0.2.3 \
		heck-0.3.1 \
		hermit-abi-0.1.13 \
		home-0.5.3 \
		idna-0.2.0 \
		indexmap-1.4.0 \
		inotify-0.7.1 \
		inotify-sys-0.1.3 \
		insta-0.16.0 \
		iovec-0.1.4 \
		itertools-0.9.0 \
		itoa-0.4.5 \
		jemalloc-ctl-0.3.3 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		jod-thread-0.1.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		libc-0.2.71 \
		libloading-0.6.2 \
		linked-hash-map-0.5.3 \
		lock_api-0.3.4 \
		log-0.4.8 \
		lsp-server-0.3.2 \
		lsp-types-0.74.2 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memmap-0.7.0 \
		memoffset-0.5.4 \
		mio-0.6.22 \
		mio-extras-2.0.6 \
		miow-0.2.1 \
		net2-0.2.34 \
		notify-4.0.15 \
		num_cpus-1.13.0 \
		object-0.19.0 \
		once_cell-1.4.0 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		paste-0.1.16 \
		paste-impl-0.1.16 \
		percent-encoding-2.1.0 \
		petgraph-0.5.1 \
		pico-args-0.3.1 \
		plain-0.2.3 \
		ppv-lite86-0.2.8 \
		proc-macro-hack-0.5.16 \
		proc-macro2-1.0.18 \
		quote-1.0.7 \
		ra_vfs-0.6.1 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		redox_syscall-0.1.56 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		relative-path-1.0.0 \
		remove_dir_all-0.5.2 \
		rowan-0.10.0 \
		rustc-ap-rustc_lexer-661.0.0 \
		rustc-demangle-0.1.16 \
		rustc-hash-1.1.0 \
		ryu-1.0.5 \
		salsa-0.14.1 \
		salsa-macros-0.14.1 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		scroll-0.10.1 \
		scroll_derive-0.10.2 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.111 \
		serde_derive-1.0.111 \
		serde_json-1.0.53 \
		serde_repr-0.1.5 \
		serde_yaml-0.8.12 \
		slab-0.4.2 \
		smallvec-1.4.0 \
		smol_str-0.1.15 \
		superslice-1.0.0 \
		syn-1.0.30 \
		synstructure-0.12.3 \
		tempfile-3.1.0 \
		terminal_size-0.1.12 \
		termios-0.3.2 \
		text-size-1.0.0 \
		thin-dst-1.1.0 \
		thread_local-1.0.1 \
		threadpool-1.8.1 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.12 \
		unicode-segmentation-1.6.0 \
		unicode-xid-0.2.0 \
		url-2.1.1 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1 \
		yaml-rust-0.4.4

CARGO_USE_GITHUB=	yes
CARGO_GIT_SUBDIR=	chalkderive:chalk-ir:chalk-ir \
			chalkderive:chalk-rust-ir:chalk-rust-ir \
			chalkderive:chalk-solve:chalk-solve
CARGO_INSTALL_PATH=	crates/rust-analyzer

# attempts to install rustup toolchains
NO_TEST=	yes

PLIST_FILES=	bin/rust-analyzer
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rust-analyzer

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
