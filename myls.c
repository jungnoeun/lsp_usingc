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


char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

struct my_t{
	char fname[12];
	long mot;
};

void bubbleSort(int,struct my_t * );
int main(int argc, char *argv[]){

	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[1024];
	int cnt =0;
	struct my_t myt[1024] = {0}; 
	int i=0;
	char temp[12] ={0,};
	long itemp =0;

	//myls 
	if(argc == 1){
		dir = ".";
		
		if((dp = opendir(dir)) == NULL)
			perror(dir);
		while((d = readdir(dp)) != NULL){
			cnt++;
			printf("%-10s\t",d->d_name);
			if(cnt%8 == 0)printf("\n");
		}
		printf("\n");
		closedir(dp);
	}

	//myls -opt 이거나 myls filename/dirname
	else if(argc == 2){
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
				closedir(dp);
			}

			//myls -l 구현
			else if(strcmp(argv[1],"-l") == 0){
				if((dp = opendir(dir)) == NULL)
					perror(dir);
				while((d = readdir(dp)) != NULL){
					sprintf(path, "%s/%s",dir, d->d_name);
					if(lstat(path,&st)<0)
						perror(path);
					printStat(path,d->d_name,&st);
					//putchar('\n');
				}
				closedir(dp);
			}

			//myls -t 명령어 구현
			else if(strcmp(argv[1],"-t") == 0){
				if((dp = opendir(dir)) != NULL)
					perror(dir);
				while((d =  readdir(dp)) != NULL){
					sprintf(path, "%s/%s",dir,d->d_name);
					if(lstat(path,&st)<0)
						perror(path);
					
					strcpy(myt[i].fname,d->d_name);
					myt[i].mot = st.st_mtime;
					//printf("%s %ld\n",myt[i].fname,myt[i].mot);
					i++;
				}
				//bubbleSort(i,&myt);
				for(int j=0;j<i-1;j++){
					for(int k=0;k<i-1-j;k++){
						if(myt[k].mot<myt[k+1].mot){
							strcpy(temp,myt[k].fname);
							strcpy(myt[k].fname,myt[k+1].fname);
							strcpy(myt[k+1].fname,temp);
							itemp = myt[k].mot;
							myt[k].mot = myt[k+1].mot;
							myt[k+1].mot = itemp;
						}
					}
				}

				for(int j=0;j<i;j++){
					printf("%-14s",myt[j].fname);
					if((j%8==0)&&(j!=0))printf("\n");
				}

			}
		}
	
		else{
			//strncpy(path,argv[1],sizeof(argv[1]));
			if(lstat(argv[1],&st)<0)
				perror("lstat error\n");

			if(S_ISREG(st.st_mode)){
				printf("%s\n",argv[1]);
			}

			else if(S_ISDIR(st.st_mode)){
				dir = argv[1];
				if((dp = opendir(dir)) == NULL)
					perror(dir);
				while((d = readdir(dp)) != NULL){
					cnt++;
					printf("%-14s",d->d_name);
					if(cnt%8==0)printf("\n");
				}
				closedir(dp);
			}

		}

	
	}


	//closedir(dp);
	exit(0);

}


//파일 정렬
/*void bubbleSort(int num,struct my_t *myt){
	char temp[12] = {0,};
	long itemp = 0;
	
	for(int j=0;j<num-1;j++){
		for(int k=0;k<num-1-j;k++){
			if(myt[k].mot<myt[k+1].mot){
				strcpy(temp,myt[k].fname);
				//temp = myt[k].fname;
				strcpy(myt[k].fname,myt[k+1].fname);
				//myt[k].fname =myt[k+1].fname;
				//myt[k+1].fname = temp;
				strcpy(myt[k+1].fname,temp);

				itemp = myt[k].mot;
				myt[k].mot = myt[k+1].mot;
				myt[k+1].mot = itemp;
			}
		}
	}


	for(int j=0;j<num;j++){
		printf("%-14s",myt[j].fname);
		if(j%8==0)printf("\n");
	}

}*/







//파일 상태 정보를 출력
void printStat(char *pathname, char *file, struct stat *st){

	//printf("%5ld ",st->st_blocks);
	printf("%c%s ", type(st->st_mode),perm(st->st_mode));
	printf("%3ld ",st->st_nlink);
	printf("%s %s",getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
	printf("%9ld ",st->st_size);
	printf("%.12s ",ctime(&st->st_mtime)+4);
	printf("%s\n",file);
}

char type(mode_t mode){
	if(S_ISREG(mode))
		return('-');
	if(S_ISDIR(mode))
		return('d');
	if(S_ISCHR(mode))
		return('c');
	if(S_ISBLK(mode))
		return('b');
	if(S_ISLNK(mode))
		return('l');
	if(S_ISFIFO(mode))
		return('p');
	if(S_ISSOCK(mode))
		return('s');
}


char* perm(mode_t mode){
	int i;
	static char perms[10] = "---------";
	
	for(i=0;i<3;i++){

		if(mode&(S_IRUSR>>i*3))
			perms[i*3] = 'r';
		else perms[i*3] = '-';
		if(mode&(S_IWUSR>>i*3))
			perms[i*3+1] = 'w';
		else perms[i*3+1] = '-';
		if(mode&(S_IXUSR>>i*3))
			perms[i*3+2] = 'x';
		else perms[i*3+2] = '-';
	}
	return(perms);
}

