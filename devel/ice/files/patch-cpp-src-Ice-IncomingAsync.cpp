--- cpp.orig/src/Ice/IncomingAsync.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Ice/IncomingAsync.cpp	2012-03-04 20:14:52.000000000 +0100
@@ -24,7 +24,7 @@
 using namespace IceInternal;
 
 IceUtil::Shared* IceInternal::upCast(IncomingAsync* p) { return p; }
-IceUtil::Shared* IceInternal::upCast(AMD_Object_ice_invoke* p) { return p; }
+IceUtil::Shared* Ice::upCast(AMD_Object_ice_invoke* p) { return p; }
 
 namespace
 {
