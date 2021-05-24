// create a random array and shuffle it
// and take how much your level wants
#include<stdio.h>

// include files needed
#include<stdlib.h>
#include<time.h>

#define __noofrows__ (25)
#define __noofcols__ (25)
#define __len_array__ (__noofrows__ * __noofcols__)

char pattern1[__noofrows__][__noofcols__];

void init_pattern1(){
	for (int i = 0; i < __noofrows__; i++){
		for (int j = 0; j < __noofcols__; j++){
			pattern1[i][j] = '-';
		}
	}
}

int array[__len_array__];

int assign_max_hashtag(int level){
	int max_hashtag = 0;
	if (level <= 3){
		max_hashtag = ((__len_array__  * 15) / 175);
	}
	else if (level <= 6){
		max_hashtag = ((__len_array__  * 30) / 175);
	}
	else if (level <= 9){
		max_hashtag = ((__len_array__  * 45) / 175);
	}
	else{
		max_hashtag = ((__len_array__  * 15) / 175);
	}
	return max_hashtag;
}

int assign_max_at(int level){
	int max_at = 0;
	switch (level){
		case 1 : 
			max_at = ((__len_array__ * 3) / 175);
			break;
		case 2:
			max_at = ((__len_array__ * 5) / 175);
			break;
		case 3:
			max_at = ((__len_array__ * 6) / 175);
			break;
		case 4: 
			max_at = ((__len_array__ * 8) / 175);
			break;
		case 5:
			max_at = ((__len_array__ * 10) / 175);
			break;
		case 6:
			max_at = ((__len_array__ * 13) / 175);
			break;
		case 7: 
			max_at = ((__len_array__ * 15) / 175);
			break;
		case 8:
			max_at = ((__len_array__ * 18) / 175);;
			break;
		case 9:
			max_at = ((__len_array__ * 20) / 175);;
			break;
		default:
			max_at = 3;
			break;
	}
	return (max_at);
}

void init_array(){
	for (int i = 0; i < __len_array__; i++){
		array[i] = i;
	}
}

void shuffle_array(){
	// shuffling the numbers (indexs of our 2d char array)
	int i = 0, j = 0, k = 0, temp = 0;
    for (i = 0; i < (__len_array__ / 2);i++){
		j = rand() % __len_array__;
		k = rand() % __len_array__;
		temp = array[j];
        array[j] = array[k];
		array[k] = temp;
	}
}

void change_minus_into_hash_and_at(int max_hashtag, int max_at){
	// /int up_cursort_start = 0, down_cursor_start = 0;
	//up_cursort_start = (__noofcols__ * ((__noofrows__ / 2) - 1)) + ((__noofcols__ / 2) - 1);
	//down_cursor_start = up_cursort_start + __noofcols__;
	int i = 0; 
	while (i < max_hashtag){
		pattern1[(array[i] / (__noofcols__ - 1))][(array[i] % (__noofcols__))] = '#';
		i++;
	}
	int j = i;
	while (j < (max_at + i)){
		pattern1[(array[j] / (__noofcols__ - 1))][(array[j] % (__noofcols__))] = '@';
		j++;
	}	
	pattern1[(array[j] / (__noofcols__ - 1))][(array[j] % (__noofcols__))] = '|';
	j++;
	pattern1[(array[j] / (__noofcols__ - 1))][(array[j] % (__noofcols__))] = '|';
}

void gen_rand_hashes(int level){
	int max_hashtag = assign_max_hashtag(level);
	int max_at = assign_max_at(level);

	srand(time(0));
	init_array();
	shuffle_array();
	init_pattern1();
	// assigning the pattern based on array values
	change_minus_into_hash_and_at(max_hashtag, max_at);
}



int main(){
	int input = 0; 
	printf("Enter the level ");
	scanf("%d", &input);
	gen_rand_hashes(input);
	for(int i = 0; i < __noofrows__;i++){
		for(int j = 0;j < __noofcols__;j++){
			printf("%c", pattern1[i][j]);
		}
		printf("\n");
	}
	return(0);
}








