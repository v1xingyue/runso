UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	test_cmd = export DYLD_LIBRARY_PATH=./common/lib && ./runso -m -d ./item
else
	test_cmd = export LD_LIBRARY_PATH=./common/lib && ./runso -m -d ./item
endif

all: so base runso

runso: runso.c
	gcc -ldl -lbase -L./common/lib -I./common/include runso.c -o runso -D buildnum=\"`date +%Y%m%d_%H%M%S`\"

test:so base runso
	$(test_cmd)

so:
	cd item ; make

base:
	cd common/base; make ; make install
