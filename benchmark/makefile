all: benchmark.out
	@/usr/bin/time -p ./benchmark.out

benchmark.out: benchmark.c
	@cc benchmark.c -o benchmark.out -lm
