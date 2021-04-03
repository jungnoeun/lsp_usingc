#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>


int main(){
	int num,def;
	int fd1,fd2;
	int rcnt;
	int ip=0;
	char *fname1 = "bfile.txt";
	char *fname2 = "afile.txt";
	char *space = " ";
	
	printf("몇개의 난수를 입력하시겠습니까? : ");
	scanf("%d",&num);
	int arr1[1000] = {0,};
	char str[1000];
	

	srand(time(NULL));
	for(int i=0;i<num;i++){
		arr1[i] = rand()%100;
	}
	if((fd1 = open(fname1,O_WRONLY|O_CREAT,200))<0){
		fprintf(stderr,"open error for %s\n",fname1);
		exit(1);
	}


	//for(int i=0;i<num;i++){
	//	sprintf(str,"%s%d ",str, arr1[i]);
	//}
	
	for(int i=0;i<num;i++){
		sprintf(str,"%d",arr1[i]);
		write(fd1,str,strlen(str));
		write(fd1,space,1);
	}

	if(fchmod(fd1,S_IRWXU)<0){
		printf("error");
	}

	//write(fd1,str,strlen(str));

	close(fd1);


	if((fd1 = open(fname1,O_RDONLY))<0){
		fprintf(stderr,"open error for %s\n",fname1);
		exit(1);
	}
	

	//딱 read로 fd1읽어들여야 함
	read(fd1,str,1000);


	char *wh = strtok(str," ");
	while(wh!=NULL){
		arr1[ip] = atoi(wh);
		wh = strtok(NULL," ");
		ip++;
	}

	
	for(int i=0;i<num-1;i++){
		for(int j=0;j<num-i-1;j++){
			if(arr1[j]>arr1[j+1]){
				def = arr1[j];
				arr1[j] = arr1[j+1];
				arr1[j+1] = def;
			}
		}
	}

	
	
	if((fd2 = open(fname2,O_RDWR|O_CREAT,200))<0){
		fprintf(stderr, "open error for %s\n",fname2);
		exit(1);
	}
	
	for(int i=0;i<num;i++){
		sprintf(str,"%d",arr1[i]);
		write(fd2,str,strlen(str));
		write(fd2,space,1);
	}
	

	//write(fd2,str,strlen(str));
	
	close(fd1);
	close(fd2);
	exit(0);

}
