#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>


int main(){
	int num,def;
	int fd1,fd2;
	int rcnt;
	int ip=0;
	char *fname1 = "bef_file.txt";
	char *fname2 = "aft_file.txt";
	
	printf("몇개의 난수를 입력하시겠습니까? : ");
	scanf("%d",&num);
	int arr1[1000] = {0,};
	char str[1000]="";
	char *wh = "";

	srand(time(NULL));
	for(int i=0;i<num;i++){
		arr1[i] = rand()%100;
	}
	if((fd1 = open(fname1,O_RDWR|O_CREAT,0755))<0){
		fprintf(stderr,"open error for %s\n",fname1);
		exit(1);
	}
	if((fd2 = open(fname2,O_RDWR|O_CREAT,0755))<0){
		fprintf(stderr,"open error for %s\n",fname2);
		exit(1);
	}


	for(int i=0;i<num;i++){
		sprintf(str,"%s%d ",str, arr1[i]);
	}
	
	printf("정수배열을 문자열로 만든 후 %s\n",str);
	write(fd1,str,strlen(str));

	 
	//딱 read로 fd1읽어들여야 함
	read(fd1,wh,sizeof(wh));

	wh = strtok(str," ");
	while(wh!=NULL){
		arr1[ip] = atoi(wh);
		wh = strtok(NULL," ");
		ip++;
	}

	printf("문자를 다시 정수배열로 만든 후\n");
	for(int i=0;i<num;i++){
		printf("%d ",arr1[i]);
	}
	printf("\n");
	
	for(int i=0;i<num-1;i++){
		for(int j=0;j<num-i-1;j++){
			if(arr1[j]>arr1[j+1]){
				def = arr1[j];
				arr1[j] = arr1[j+1];
				arr1[j+1] = def;
			}
		}
	}

	
	printf("크기 순서대로 정렬한 후\n");
	for(int i=0;i<num;i++){
		printf("%d ",arr1[i]);
	}
	printf("\n");
		
	
	for(int i=0;i<num;i++){
		sprintf(str,"%s%d ",str,arr1[i]);
	}
	
	printf("문자열로 최종 만든 후 %s\n",str);

	write(fd2,str,strlen(str));
	

	
	close(fd1);
	close(fd2);
	exit(0);

}
