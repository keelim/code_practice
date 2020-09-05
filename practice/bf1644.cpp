int main(){
    int i, j, num = 0;
    int prime[100] = { 0, };
    for (i = 2; i <= 100; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0)
                break;
        }
        if (i == j) {
            prime[num]= i;
            num++;
        }
    }
    
    return 0;
}