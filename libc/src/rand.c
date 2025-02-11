int rand_seed = 5829466;

void srand(int seed) {
    rand_seed = seed;
}

int rand() {
	rand_seed = (164525 * rand_seed + 101390423) % 4294967296;
	return rand_seed;
}
