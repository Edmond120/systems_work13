#include<stdio.h>
#include<unistd.h>

int main(){
	int pipe_to_child[2];
	int pipe_to_parent[2];
	int READ = 0;
	int WRITE = 1;
	pipe(pipe_to_child);
	pipe(pipe_to_parent);
	int f = fork();
	if(f){
		close(pipe_to_child[READ]);
		close(pipe_to_parent[WRITE]);
		int input = 5;
		write(pipe_to_child[WRITE],&input,sizeof(int));
		printf("[parent] sending :%d\n",input);
	}
	else{
		close(pipe_to_parent[READ]);
		close(pipe_to_child[WRITE]);
		int buffer;
		read(pipe_to_child[READ],&buffer,sizeof(int));
		printf("[child] doing maths on :%d\n",buffer);
	}
}
