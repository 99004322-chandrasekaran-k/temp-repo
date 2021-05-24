#include <stdio.h>

int global_score = 0;
int global_level = 1; 


#define __noofrows__ (25)
#define __noofcols__ (25)
#define __len_array__ (__noofrows__ * __noofcols__)

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

int score_updater(int hash_points, int atpoints){
	// going to be called at the level
	// if all the hashpoints are collected
	int level_score = ((hash_points - atpoints) * 10);
	int max_hashtag = assign_max_hashtag(global_level);
	int max_at = assign_max_at(global_level);
	if (level_score >= ((max_hashtag - (max_at / 2)) * 10)){
		if ((global_level == 9)){
			global_score += level_score;
		}
		else{
		global_level += 1;
		global_score += level_score; 
		}
	}
	else if (global_level != 1){
		global_level -= 1;
	}
	else{
		global_level = 1;
	}
}


int main(){
	int hash_points, atpoints;
	while (1){
		printf("\n Enter hashpoints atpoints ");
		scanf("%d %d", &hash_points, &atpoints);
		score_updater(hash_points, atpoints);
		printf("\n The level is %d", global_level);
		printf("\n The score is %d", global_score);
	}
}