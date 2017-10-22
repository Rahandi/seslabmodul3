#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[2];
FILE *satu, *dua, *tiga;
char *line=NULL;
size_t len=0;
int status=2;

void* jalanpertama(){
	status = 1;

	satu = fopen("baca.txt", "r");
	dua = fopen("salin1.txt", "w+");

	while(getline(&line,&len,satu)!=-1){
		fprintf(dua, "%s", line);
	}

	fclose(satu);
	fclose(dua);

	status = 0;
}

void* jalankedua(){
	while(status != 0){}

	dua = fopen("salin1.txt", "r+");
	tiga = fopen("salin2.txt", "w");

	while(getline(&line,&len,dua)!=-1){
		fprintf(tiga, "%s", line);
	}

	fclose(dua);
	fclose(tiga);
}

int main(){
	pthread_create(&(tid[0]), NULL, &jalanpertama, NULL);
	pthread_create(&(tid[1]), NULL, &jalankedua, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
}