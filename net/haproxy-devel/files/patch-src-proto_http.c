--- src/proto_http.c.orig	2012-12-24 19:48:14.000000000 +0400
+++ src/proto_http.c	2012-12-26 00:10:46.000000000 +0400
@@ -3113,8 +3113,8 @@
 			}
 		}
 	}
-	return rule;
+	return NULL;
 }
 
 /* This stream analyser runs all HTTP request processing which is common to