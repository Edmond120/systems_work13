all: pipe_work.c
	gcc -o pipe_work pipe_work.c
run: all
	./pipe_work
clean:
	rm pipe_work
