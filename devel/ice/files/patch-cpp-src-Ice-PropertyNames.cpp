--- cpp.orig/src/Ice/PropertyNames.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/Ice/PropertyNames.cpp	2012-03-04 19:55:44.000000000 +0100
@@ -8,7 +8,7 @@
 // **********************************************************************
 
 //
-// Generated by makeprops.py from file ..\config\PropertyNames.xml, Mon May 09 07:39:43 2011
+// Generated by makeprops.py from file ../config/PropertyNames.xml, Tue Jul 12 07:22:34 2011
 
 // IMPORTANT: Do not edit this file -- any edits made here will be lost!
 
@@ -335,6 +335,8 @@
     IceInternal::Property("IceGrid.Registry.PermissionsVerifier", false, 0),
     IceInternal::Property("IceGrid.Registry.ReplicaName", false, 0),
     IceInternal::Property("IceGrid.Registry.ReplicaSessionTimeout", false, 0),
+    IceInternal::Property("IceGrid.Registry.RequireNodeCertCN", false, 0),
+    IceInternal::Property("IceGrid.Registry.RequireReplicaCertCN", false, 0),
     IceInternal::Property("IceGrid.Registry.Server.ACM", false, 0),
     IceInternal::Property("IceGrid.Registry.Server.AdapterId", false, 0),
     IceInternal::Property("IceGrid.Registry.Server.Endpoints", false, 0),
