all:
	gcc *.c -o main

run: all
	./main

run-clean: all
	./main && rm -f main

clean:
	rm -f main