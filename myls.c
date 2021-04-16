#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


int main(int argc, char *argv[]){

	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[1024];

	//myls 
	if(argc == 1){
		dir = ".";
		if((dp = opendir(dir)) == NULL)
			perror(dir);
	}

	while((d = readdir(dp)) != NULL){
		printf("%s\t",d->d_name);
	}
	printf("\n");


	exit(0);

}
