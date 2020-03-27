#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SEED 1
#define DEFAULT_COEFFECIENT1 1234567891
#define DEFAULT_COEFFECIENT2 987654321
const uint64_t MODULUS_CONSTANT = 10;
const uint64_t DEFAULT_NUMBERS = 1;

uint64_t coeffecient1 = DEFAULT_COEFFECIENT1;
uint64_t coeffecient2 = DEFAULT_COEFFECIENT2;

// Don't change anything above this line
// Your code goes here
uint64_t Counter_func(uint64_t val){
    static uint64_t counter = 0;
    if (val == 0){
        counter = 0;
        //return counter;
    }
    else if (val>0){
        counter += val;
        //return counter;
    }
    return counter;
}

uint64_t actual_seed_func(uint64_t seedPass){
    static uint64_t ActualSeed = 0;
    ActualSeed += seedPass;
    return ActualSeed;
}

uint64_t coeffecient1_func(uint64_t coe1){
    static uint64_t stat_coe1 = 0;
    stat_coe1 += coe1;
    return stat_coe1;
}

uint64_t coeffecient2_func(uint64_t coe2){
    static uint64_t stat_coe2 = 0;
    stat_coe2 += coe2;
    return stat_coe2;
}

void seedMyRand(uint64_t input_seed, uint64_t input_coeffecient1, uint64_t input_coeffecient2){
    uint64_t actual_seed = 0;
    actual_seed = ((input_seed * input_coeffecient1) + input_coeffecient2);
    actual_seed_func(actual_seed);
    coeffecient1_func(input_coeffecient1);
    coeffecient2_func(input_coeffecient2);
}

uint64_t myRand(){ //return random number
    static uint64_t val_to_add = 0; 
    static uint64_t act_seed_add = 0; 
    static uint64_t coef1 = 0; 
    static uint64_t coef2 = 0; 
    static uint64_t rand_value = 0; 
    static uint64_t previous_rand = 0;
    uint64_t counter_val = Counter_func(val_to_add);
    uint64_t act_seed = actual_seed_func(act_seed_add);
    uint64_t coeff1 = coeffecient1_func(coef1);
    uint64_t coeff2 = coeffecient2_func(coef2);

    if (counter_val == 0){
        rand_value = act_seed;
        val_to_add += 1;
       // return rand_value;
    }
    else if(counter_val > 0){
        previous_rand = rand_value;
        rand_value = (previous_rand * coeff1) + coeff2;
        val_to_add += 1;
       // return rand_value;
    }
    return rand_value;
}
// Don't change anything below this line
uint64_t input_u64(uint64_t default_value) { //return unsigned long long int
    /* Read a u64 from the input, (user or file)
     * using default_value instead if the user enters 0
     */
    uint64_t input_value = 0; 
    int scanned = scanf("%llu", (long long unsigned int *) &input_value);
    if (scanned != 1) {
        abort();
    }
    if (input_value == 0) {
        return default_value;
    }
    return input_value;
}

int main() {
  printf("What is the seed?\n");
  uint64_t input_seed = input_u64(DEFAULT_SEED);

  printf("What is coeffecient1?\n");
  uint64_t input_coeffecient1 = input_u64(DEFAULT_COEFFECIENT1);

  printf("What is coeffecient2?\n");
  uint64_t input_coeffecient2 = input_u64(DEFAULT_COEFFECIENT2);

  printf("How many numbers?\n");
  uint64_t numbers = input_u64(DEFAULT_NUMBERS);

  seedMyRand(input_seed, input_coeffecient1, input_coeffecient2);

  for (uint64_t number = 0 ; number < numbers; number++) {
    printf("%llu\n", (unsigned long long) myRand() % MODULUS_CONSTANT);
  }

  return 0;
}
