int singleNumber(int *num,int numSize) {
    int result = 0;

    for(int i = 0; i < numSize; i++){
        result ^= num[i];
    } 
    return result;
}