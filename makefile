all:
	gcc -ldl runso.c -o runso -D buildnum=\"`date +%Y%m%d%H%M%S`\"
