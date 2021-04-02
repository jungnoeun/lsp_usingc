#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char fname[50] = {0,};
	char fcon[100] = {0,};
	int fd;

	printf("file의 이름을 적으시오 : ");
	scanf("%s",fname);
	printf("file의 내용을 적으시오 : ");
	scanf("%s",fcon);

	for(int i=0;i<sizeof(fname);i++){
		//대문자를 소문자로
		if(fname[i]>=65&&fname[i]<=90){
			fname[i]+=32;
		}
		//소문자를 대문자로
		else if(fname[i]>=97&&fname[i]<=122){
			fname[i]-=32;
		}
	}

	for(int j=0;j<sizeof(fcon);j++){
		if(fcon[j]>=65&&fname[j]<=90){
			fcon[j]+=32;
		}
		else if(fcon[j]>=97&&fcon[j]<=122){
			fcon[j]-=32;
		}
	}

	if(fd = open(fname,O_WRONLY|O_CREAT)<0){
		fprintf(stderr,"open error for %s\n",fname);
		exit(1);
	}

	write(fd,fcon,sizeof(fcon));
	close(fd);
	exit(0);


}



