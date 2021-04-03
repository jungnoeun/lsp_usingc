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
	char *fname1 = "bef_file.txt";
	char *fname2 = "aft_file.txt";
	
	printf("몇개의 난수를 입력하시겠습니까? : ");
	scanf("%d",&num);
	int arr1[1000] = {0,};
	char str[1000]="";
	char str2[1000] = "";
	srand(time(NULL));
	for(int i=0;i<num;i++){
		arr1[i] = rand();
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


	//write(fd1,(char*)arr1,sizeof(arr1));
	write(fd1,str,sizeof(str));


	//if(read(fd1,arr2,sizeof(arr1))>0){
		for(int i=0;i<num-1;i++){
			for(int j=0;j<num-i-1;j++){
				if(arr1[j]>arr1[j+1]){
					def = arr1[j];
					arr1[j] = arr1[j+1];
					arr1[j+1] = def;
				}
			}
		}
	//}

	
		
	for(int i=0;i<num;i++){
		sprintf(str2,"%s%d ",str2,arr1[i]);
	}
	
	//while((rcnt = read(fd2,(char*)arr1,num))>0){
	//write(fd2,(char*)arr1,rcnt);
	write(fd2,str2,sizeof(str2));
	//}

	
	close(fd1);
	close(fd2);
	exit(0);

}
