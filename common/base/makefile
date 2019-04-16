all:
	gcc base.c -fPIC -shared -o base.so -I ../include

install:
	cp base.h ../include
	rm -f ../lib/*.so
	cp base.so ../lib
	ln -s ../lib/base.so ../lib/libbase.so
