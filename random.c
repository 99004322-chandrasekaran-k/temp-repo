#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int rand_max = 176, max_hashtag = 0, level = 3;
	int r = 0;
	int upper = 175, lower = 1;
	if (level == 1){
		max_hashtag = 3;
	}
	else if (level == 2){
		max_hashtag = 6;
	}
	else if (level == 3){
		max_hashtag = 9;
	}
	srand(time(0));
	char pattern1[7][25]={
		{"-------------------------"},
		{"-------------------------"},
		{"-----------|-------------"},
		{"-----------|-------------"},
		{"-------------------------"},
		{"-------------------------"},
		{"-------------------------"}
	};
	int i = 0;
	int j = 0;
	while (i <  max_hashtag){
		j = 0;
		while (j < 5){
			r = (rand() % (upper - lower + 1)) + lower;
			//r = (int)(rand() % rand_max);
			printf("%d ", r);
			if (((r != 62) && (r != 87)) && (r < 175)){
				printf("row value is %d  ", (r / 24) + 1);
				printf("col value is %d  ", (r % 24));
				pattern1[(r / 24)][(r % 24)] = '#';
				j++;
			}
			printf("%d \n", i);
		}
		i++;
	}

	for(int i = 0; i < 7;i++){
		for(int j = 0;j < 25;j++){
			printf("%c", pattern1[i][j]);
		}
		printf("\n");
	}
	return(0);
}








