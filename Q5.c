#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>


int main(){
	int num,def;
	int fd1,fd2;
	char *fname1 = "bef_file.txt";
	char *fname2 = "aft_file.txt";
	printf("몇개의 난수를 입력하시겠습니까? : ");
	scanf("%d",&num);
	int *arr1 = (int*)malloc(sizeof(int)*num);
	int *arr2 = (int*)malloc(sizeof(int)*num);
	srand(time(NULL));
	for(int i=0;i<num;i++){
		arr1[i] = rand();
	}
	if((fd1 = open(fname1,O_RDWR|O_CREAT,0755))<0){
		fprintf(stderr,"open error for %s\n",fname1);
		exit(1);
	}
	write(fd1,arr1,sizeof(arr1));

	if(read(fd1,arr2,sizeof(arr1))>0){
		for(int i=0;i<num-1;i++){
			for(int j=0;j<num-i-1;j++){
				if(arr2[j]>arr2[j+1]){
					def = arr2[j];
					arr2[j] = arr2[j+1];
					arr2[j+1] = def;
				}
			}
		}
	}
	if((fd2 = open(fname2,O_RDWR|O_CREAT,0755))<0){
		fprintf(stderr,"open error for %s\n",fname2);
		exit(1);
	}

	write(fd2,arr2,sizeof(arr2));
	close(fd1);
	close(fd2);
	exit(0);

}
