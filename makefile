UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	test_cmd = export DYLD_LIBRARY_PATH=./common/lib && ./runso -m -d ./item
else
	test_cmd = export LD_LIBRARY_PATH=./common/lib && ./runso -m -d ./item
endif

all:
	gcc -ldl  runso.c -o runso -D buildnum=\"`date +%Y%m%d_%H%M%S`\"

test:so
	$(test_cmd)

so:
	cd item ; make
