--- libraries/source/spidermonkey/build.sh.orig	2016-10-04 15:01:34 UTC
+++ libraries/source/spidermonkey/build.sh
@@ -96,6 +96,14 @@ cd js/src
 rm -rf build-debug
 rm -rf build-release
 
+cp jsnativestack.cpp jsnativestack.cpp.orig
+sed 's/#  include <pthread_np.h>/#pragma GCC visibility push(default)\
+#include <pthread_np.h>\
+#pragma GCC visibility pop/' jsnativestack.cpp.orig >jsnativestack.cpp
+
+cp configure configure.orig
+sed -e 's/"$ac_cv_have_visibility_class_bug" = "no"; then/"$ac_cv_have_visibility_class_bug" = "no" -a "$OS_ARCH" != "FreeBSD" ; then/' -e 's/-Werror=conversion-null//' configure.orig >configure
+
 # We want separate debug/release versions of the library, so we have to change
 # the LIBRARY_NAME for each build.
 # (We use perl instead of sed so that it works with MozillaBuild on Windows,
