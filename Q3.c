#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	
	int num, pm, id=0;
	char ch;
	char fname[20] = {0,};
	int fd;
	char con[50]={0,};

	scanf("%d %c %s",&num, &ch, fname);
	
	if((fd = open(fname,O_RDWR|O_CREAT))<0){
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}
	
	if(num>0){
		for(int i=1;i<=num;i++){
			for(int j=1;j<=i;j++){
				con[id++]=ch;
			}
			con[id++]='\n';
		}
	}
	else{
		for(int i=num;i>0;i--){
			for(int j=i;j>0;j--){
				con[id++]=ch;
			}
			con[id++]='\n';
		}
	}
	write(fd, con, sizeof(con));
	close(fd);
	exit(0);

}

