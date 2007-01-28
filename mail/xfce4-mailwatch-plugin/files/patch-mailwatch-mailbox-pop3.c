--- panel-plugin/mailwatch-mailbox-pop3.c.orig	Thu Apr 20 11:24:36 2006
+++ panel-plugin/mailwatch-mailbox-pop3.c	Sat Jan 27 11:15:51 2007
@@ -176,10 +176,16 @@
 pop3_get_sockaddr(XfceMailwatchPOP3Mailbox *pmailbox, const gchar *host,
                   const gchar *service, struct sockaddr_in *addr)
 {
-    struct addrinfo hints = { 0, PF_INET, SOCK_STREAM, IPPROTO_TCP,
-            sizeof(struct sockaddr_in), NULL, NULL, NULL };
+    struct addrinfo hints;
     GError *error = NULL;
-    
+
+    memset(&hints, 0, sizeof(hints));
+ 
+    hints.ai_flags = 0;
+    hints.ai_family = PF_INET;
+    hints.ai_socktype = SOCK_STREAM;
+    hints.ai_protocol = IPPROTO_TCP;
+
     TRACE("entering (%s, %s, %p)", host, service, addr);
     
     g_return_val_if_fail(host && service && addr, FALSE);
