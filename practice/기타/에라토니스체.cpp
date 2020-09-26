//확인을 하는 것은  루트 n으로 까지 확인을 할 수 있으나 에라토니스체를 하는
//것이 깔끔하다.

int main()
{
    int prime[100];
    int pn = 0;
    bool check[101];
    int n = 100; //자기가 원하는 숫자

    for (int i = 2; i <= n; i++)
    {
        if (check[i] == false)
        {
            prime[pn++] = i;
            for (int j = i * i; j <= n; j += i)
            { // 자기들의 배수를 제외한다.
                check[j] = true;
            }
        }
    }

    for (i = 2; i <= num; i++) {
        if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        //소수 찾았을때
        for (int j = i + i; j <= num; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            arr[j] = 0;
        }
    }

    return 0;
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)//i가 나누어떨어지면 소수가 아님
            return false;
    return true;
}
bool checked[101];

int main1(){
    for (int i = 2; i <=n ; i++) {
        if(checked[i]) continue;

        for (int j = i*i; j <= n; j+=i) {
            checked[j] = true;
        }
    }

}