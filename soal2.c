#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[100];

typedef struct arg_struct{
	int angkaawal;
	int angkaakhir;
} args;

void* primechecker(void *arguments){
	struct arg_struct *args = (struct arg_struct *)arguments;
	printf("%d - ", args -> angkaawal);
    printf("%d\n", args -> angkaakhir);
}

int main(){
	int T, a;
	struct arg_struct *args = malloc(sizeof(struct arg_struct));
	scanf("%d", &T);
	for(a=0;a<T;a++){
		args->angkaawal = a;
		args->angkaakhir = T-a;

		pthread_create(&tid[a], NULL, primechecker, (void*)args);
		pthread_join(tid[a], NULL);
	}

	return 0;
}