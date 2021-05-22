// create a random array and shuffle it
// and take how much your level wants
#include<stdio.h>

// include files needed
#include<stdlib.h>
#include<time.h>

char pattern1[7][25]={
	{"-------------------------"},
	{"-------------------------"},
	{"-----------|-------------"},
	{"-----------|-------------"},
	{"-------------------------"},
	{"-------------------------"},
	{"-------------------------"}
};

int array[176];

int assign_max_hashtag(int level){
	int max_hashtag = 0;
	if (level == 1){
		max_hashtag = 15;
	}
	else if (level == 2){
		max_hashtag = 30;
	}
	else if (level == 3){
		max_hashtag = 45;
	}
	return max_hashtag;
}

void init_array(){
	for (int i = 0; i < 176; i++){
		array[i] = i;
	}
}

void shuffle_array(){
	// shuffling the numbers (indexs of our 2d char array)
	int i = 0, j = 0, k = 0, temp = 0;
    for (i = 0; i < (176 / 2);i++){
		j = rand() % 176;
		k = rand() % 176;
		temp = array[j];
        array[j] = array[k];
		array[k] = temp;
	}
}

void change_minus_into_hash(int max_hashtag){
	int i = 0, j = 0; 
	while (i < max_hashtag){
		if ((array[j] != 61) && (array[j] != 86)){
			printf("%d  %d\n", array[j], j);
			pattern1[(array[j] / 24)][(array[j] % 25)] = '#';
			i++;
		}
		j++;
	}
}

void gen_rand_hashes(int level){
	int max_hashtag = assign_max_hashtag(level);
	srand(time(0));
	init_array();
	shuffle_array();
	// assigning the pattern based on array values
	change_minus_into_hash(max_hashtag);
}



int main(){
	int input = 0; 
	printf("Enter the level ");
	scanf("%d", &input);
	gen_rand_hashes(input);
	for(int i = 0; i < 7;i++){
		for(int j = 0;j < 25;j++){
			printf("%c", pattern1[i][j]);
		}
		printf("\n");
	}
	return(0);
}








