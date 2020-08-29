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

    return 0;
}