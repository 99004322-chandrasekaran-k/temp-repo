if (collectshash()){
	score += 10;
}
else if (collectat()){
	score -= 10;
}

if (score >= ((max_hashtag - 5) * 10)){
	return (1); // finished level
	level += 1;
}

level 1 - 15 hash
level 2 - 15# + 2@  
level 3 - 15# + 5@

level 4 - 30 hash
level 5 - 30# + 5@ 
level 6 - 30# + 10@

level 7 - 45 hash
level 8 - 45# + 10@ 
level 9 - 45# + 15@

bhooopathi gives hashtag points, at points
bhoopathi flag for collected all hashtags