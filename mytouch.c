#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>

//명령 방식은 mytouch filename형식이니 argv[1]은 파일이름이고 argc는 2이다
int main(int argc,char *argv[]){

	struct stat statbuf;
	time_t ntime;
	struct utimbuf ubuf;

	if(argc!=2){
		fprintf(stderr,"usage: %s <file>\n",argv[0]);
		exit(1);
	}

	if((stat(argv[1],&statbuf)<0)){
		fprintf(stderr,"stat error\n");
		exit(1);
	}

	if(utime(argv[1],NULL)==-1){
		fprintf(stderr,"utime error\n");
		exit(1);
	}
	//statbuf.st_atime = ctime(&ntime);
	//statbuf.st_mtime = ctime(&ntime);
	//statbuf.st_ctime = ctime(&ntime);



	exit(0);
}
