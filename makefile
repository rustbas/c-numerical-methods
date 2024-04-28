all: simple-methods runge-kutta simple
	gcc main.c -o main.out -lm -g3 -Lobj/ -lrunge-kutta -lsimple

simple-methods: 
	gcc -O3 src/integrate/simple-methods.c -o obj/libsimple-methods.so -c

runge-kutta: 
	gcc -O3 src/solvers/runge-kutta.c -o obj/librunge-kutta.so -c

simple: 
	gcc -O3 src/solvers/simple.c -o obj/libsimple.so -c

clean:
	rm obj/*.so
