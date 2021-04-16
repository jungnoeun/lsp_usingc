#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>



int main(int argc, char *argv[]){

	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[1024];
	int cnt =0;

	//myls 
	if(argc == 1){
		dir = ".";
		
		if((dp = opendir(dir)) == NULL)
			perror(dir);
		while((d = readdir(dp)) != NULL){
			cnt++;
			printf("%-10s\t",d->d_name);
			if(cnt%16 == 0)printf("\n");
		}
		printf("\n");
	}

	//myls -opt 이거나 myls filename/dirname
	if(argc == 2){
		dir = ".";
		if(argv[1][0] == '-'){
			if(strcmp(argv[1],"-i") == 0){
				if((dp = opendir(dir)) == NULL)
					perror(dir);
				while((d = readdir(dp)) != NULL){
					cnt++;
					sprintf(path, "%s/%s",dir, d->d_name);
					if(lstat(path,&st)<0)
						perror(path);
					printf("%d ",(int)d->d_ino);
					printf("%-14s",d->d_name);
					if(cnt%8==0)printf("\n");
				}
			}
		}
	
	}



	exit(0);

}
