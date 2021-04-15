#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


//argv[1]은 바꿀 모드 숫자, argv[2]는 파일이름

int main(int argc,char *argv[])
{
	struct stat statbuf;
	int opt;
	int mode=0;

	if(stat(argv[2],&statbuf)<0)
		fprintf(stderr, "stat error %s\n",argv[2]);

	//mode = atoi(argv[1]);
	sscanf(argv[1],"0%o",&mode);

	//printf("%d\n",mode);
	if(chmod(argv[2],mode)<0)
		fprintf(stderr, "chmod error %s\n",argv[2]);


	exit(0);

}
