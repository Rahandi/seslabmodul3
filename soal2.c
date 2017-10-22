#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[100];
int status = 0;

typedef struct arg_struct{
	int angkaawal;
	int angkaakhir;
	int stat;
} args;

void* primechecker(void *arguments){
	struct arg_struct *args = (struct arg_struct *)arguments;
	while(args->stat != status){}
	int a,b,c;
	for(a=args->angkaawal;a<=args->angkaakhir;a++){
		c=0;
		for(b=2;b<=a/2;b++){
			if(a==1){
				c=1;
				break;
			}
			if(a%b==0){
				c=1;
				break;
			}
		}
		if (c==0) printf("%d\n", a);
	}
	
	status++;
    free(arguments);
}

int main(){
	int T, a, N;
	scanf("%d", &N);
	scanf("%d", &T);
	int hitung = N/T;
	int awal = 1;
	int akhir = hitung;
	for(a=0;a<T;a++){
		struct arg_struct *args = malloc(sizeof(struct arg_struct));
		args->angkaawal = awal;
		args->angkaakhir = akhir;
		args->stat = a;

		awal = awal + hitung;
		akhir = akhir + hitung;

		pthread_create(&tid[a], NULL, primechecker, (void*)args);
	}

	for(a=0;a<T;a++){
		pthread_join(tid[a], NULL);
	}

	return 0;
}