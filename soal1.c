#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[2];
FILE *satu, *dua, *tiga;
char *line=NULL;
size_t len=0;

void* jalanpertama(){
	satu = fopen("baca.txt", "r");
	dua = fopen("salin1.txt", "w+");

	while(getline(&line,&len,satu)!=-1){
		fprintf(dua, "%s", line);
	}

	fclose(satu);
	fclose(dua);
}

int main(){
	pthread_create(&(tid[0]), NULL, &jalanpertama, NULL);

	pthread_join(tid[0], NULL);
}
