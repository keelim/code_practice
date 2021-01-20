# 알고리즘

## 목차

### [1. 강의링크(Link)](#1-강의링크)

### [2. 팁/키워드정리(Tip/Keywords)](#2-팁-키워드정리)

### [3. 구현 (Implementation)](#3-구현-implementation)

### [4. 수학/숫자 (Mathematics/Numerical)](#4-수학-숫자-Mathematics-Numerical)

### [5. 문자열 (Strings)](#5-문자열-Strings)

### [6. 정렬 (Sorting)](#6-정렬-Sorting)

### [7. 재귀 (Recursion)](#7-재귀-Recursion)

### [8. 동적 프로그래밍=n (Dynamic Programming)](#8-동적-프로그래밍-Dynamic-Programming)

### [9. 탐색 (Search)](<#9-탐색-(Search)>)

### [10. 그래프 (Graph)](<#10-그래프-(Graph)>)

### [11. 그리디 (Greedy)](#11-그리디-Greedy)

### 1 강의링크

권오흠 교수님 알고리즘 : <https://www.youtube.com/watch?v=ln7AfppN7mY&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l>

권오흠 교수님 자료구조 :
https://www.youtube.com/watch?v=-XbHQQ8pUQY&list=PL52K_8WQO5oXIATx2vcTvqwxXxoGxxsIz

삼성 swea : https://www.swexpertacademy.com/
백준(코드플러스) : https://code.plus/
인프런 : https://www.inflearn.com/


### 2 팁 키워드정리

### ■ 문자 코드(Ascii/Unicode)

대문자 > 소문자
32 - space(공백)  
65 - A  
90 - Z  
97 - command  
122 - z


### 3 구현 (Implementation)

### ■ 야근지수

최고값을 줄어야하는 문제 일때 내가 생각한 방법인데 최고값 순으로 정렬 후 계단을 잘라가는 식으로
그 비용이 줄일 수 있는 값보다 작으면 한번에 싹둑한 후
비용이 클 때 for문 나와서 남은 줄일 수 있는 수를 사람들이 생각하는 -1 씩 줄이고 오름차순 정렬하고를 반복했음
(최대값을 찾아서 빼는게 더 효율적이긴하겠지만)
요점은 계단식 줄이기

```c++
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int wSize = works.size();
    int gonnaWorkTime;
    long long workValue;

    sort(works.rbegin(), works.rend());

    for(int i=1; i<wSize; i++)
    {
        gonnaWorkTime = (works[i-1] - works[i])*i;
        if(gonnaWorkTime > n) break;

        for(int k=0; k<i; k++)
            works[k] = works[i];

        n -= gonnaWorkTime;
    }

    while(n>0)
    {
        if(works[0]==0) break;
        works[0] -= 1;
        sort(works.rbegin(), works.rend());
        n--;
    }

    for(int i=0; i<wSize; i++)
    {
        workValue = works[i];
        answer += workValue * workValue;
    }

    return answer;
}
```

### ■ 원의 교집합 구하기 (NumberOfDiscIntersections)

평면 상의 디스크들의 접점의 수를 구하라

가장 단순하게 각 디스크의 Left/Right가 다른 디스크의 Left, Right 사이에 포함되는 지 비교했다.
당연하게도 O(n^2)의 복잡도로는 O(n \* lg(n))의 성능 테스트를 통과할 수 없었다.

Left와 Right가 각각 정렬되어 있을 때, 가장 작은 Right(O 마크)보다
작은 Left(strings 마크)들은 반드시 가장 작은 Right(O 마크)보다 큰 Right를 갖는다. 즉, 접점을 갖는다.
O 마크의 Right가 가장 작으니까 당연히 나머지 Right들은 그보다 크다.

이 작업을 각 Right마다 새로 하는 것이 아니라 Accumulate하게 진행한다.

r > l 인 L의 수(current)를 구한다.
–current;
current는 반드시 자기 자신을 포함한다.
또한 다음 R에서 겹치지 않을 수 있는 경우의 수를 제거한다.
current는 초기화하지 않고 계속해서 사용한다.

[코드]

```c++
#include <vector>
#include <algorithm>

int solution(vector<int> &A)
{
	unsigned int n = A.size();
	std::vector<long long>left(n), right(n);
    // 계산되는 값들의 타입을 맞춰주도록 한다
	for (unsigned long long i = 0; i < n; ++i)
	{
		left[i] = i - A[i];
		right[i] = i + A[i];
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	long long result{}, current{};
	unsigned long long lIndex{}, rIndex{};
	for (auto i = 0; i < n; ++i)
	{
		while (lIndex < n && left[lIndex] <= right[rIndex])
		{
		    ++current;
			++lIndex;
		}
		--current;
		result += current;
		++rIndex;
	    std::cout << current << " ";
		if (result > 10000000)
			return -1;
	}
	return result;
}
```

# 4 수학 숫자 (Mathematics Numerical)

### ■ 소수 (Prime number)

> 자기 자신보다 작은 수들을 나누어봐서, 하나라도 나누어지면 소수가 아닌 것

확장하기 > 입력받은 수보다 작은 수의 소수들만 나누어보면 되는 것이다. (ArrayList에 소수를 넣어놓고 나누어보는 방식으로~) n까지의 소수를 다 구해야할 때 더 유리한 코드가 된다.

```java
public class PrimeNumber1 {
	public static void getPrime(int room, ArrayList<Integer> prime) {
		prime.add(2);
		for (int i = 2; i <= room; i++) {
			for (int j = 0; prime.size() > j; j++) {
				if (i % prime.get(j) == 0) break; // 소수가 아닌 경우 pass
				if (j + 1 == prime.size()) // 소수일 때
					prime.add(i);
			}
		}

		for (Integer result : prime) {
			System.out.println(result);
		}
	}

	public static void main(String[] args) {
		ArrayList<Integer> prime = new ArrayList<Integer>();
		long start = System.currentTimeMillis();
		getPrime(30000, prime);
		long end = System.currentTimeMillis();
		System.out.println("수행시간 : " + (end - start));
	}
}
```

확장하기 > 주어진 자연수 N이 소수이기 위한 필요충분 조건은 N이 N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다.  
수가 수를 나누면 몫이 발생하게 되는데 몫과 나누는 수, 둘 중 하나는 반드시 N의 제곱근 이하이기 때문이다.  
즉, 2부터 N의 제곱근 까지 나눠보면 된다.

```c++
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    unsigned int room;
    cout << "소수를 구할 수를 입력하세요 : ";
    cin >> room;
    bool isPrime = true;

    // 2부터 N의 제곱근까지의 수로 나눠서 나눠지는 수가 있으면 반복문 종료
    for (int i=2; i<=sqrt(room); i++) {
        if (room % i == 0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime) {
        cout << room << "은 소수입니다." << endl;
    }
    else {
        cout << room << "은 소수가 아닙니다." << endl;
    }

    return 0;
}
```

확장하기 > 에라토스테네스의 체 (Sieve of Eratosthenes) 나눌 필요가 없이 배수를 체크하는 식으로 진행

```c++
void getChe(int room) {
    int *command;
    command = (int *)malloc(sizeof(int) * room);
    int i = 2;

    // 입력받은 수 만큼 배열에 모두 초기화 해둔다
    for (i = 2; i <= room; i++) {
        command[i] = i;
    }

    for (i = 2; i <= room; i++) {
        if (command[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        //소수 찾았을때
        for (int j = i + i; j <= room; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            command[j] = 0;
        }
    }

    // print
    for (i = 2; i <= room; i++) {
        if (command[i] != 0)
            cout << command[i] << " ";
    }
}
```

프로그래머스 소수 찾기 - n까지의 소수 개수 구하기 (내 코드)

```c++
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int command[1000000];
    int i = 2;

    for(i=2; i<=n; i++)
        command[i] = i;

    for(i=2; i<=n; i++)
    {
        if(command[i]==0) continue;
        answer++;
        for(int j=i+i; j<=n; j+=i)
            command[j] = 0;
    }

    return answer;
}
```

### ■ 약수 (Divisor)

> % 나눠서 나머지가 0이면 약수.

확장하기 > n의 1/2 제곱까지만 측정해서 i \* i 제곱약수 걸러주고 그 외는 n/i로 약수의 짝을 구하면 반복문을 줄일 수 있다.

```c++
#include<cmath>
int sum = 0;
  for(int i=1; i<=sqrt(n); i++) if(n%i==0) { sum += i; if(n!=i*i) sum += n/i; }
return sum;
```

확장하기 > 소수 구해서 n = 2^command _ 3^b _ 5^c일때 약수의 총합은 (command+1)(b+1)(c+1)이다.

### ■ 최대공약수 (GCD

(54, 24) (24, 54/24..6) (6, 24/6..0) -> 6

예제) #1

```c++
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> gcdlcm(int command,int b)
{
	vector<int> answer;
    if(min(command,b)==command) swap(command,b);
    int mod = command%b;
    int c = command;
    int n = b;
    while(mod>0) {
        c = n;
        n = mod;
        mod = c%n;
    }
    answer.push_back(n);
    answer.push_back(command*b/n);
	return answer;
}
```

#2

```c++
int main()
{
	int command=3, b=12;
	vector<int> testAnswer = gcdlcm(command,b);

	cout<<testAnswer[0]<<" "<<testAnswer[1];
}

int Euclidean(int command, int b)
{
    return b ? Euclidean(b, command%b) : command;
}

vector<int> gcdlcm(int command,int b)
{
    vector<int> answer;
    // 유클리드 호제법
  answer.push_back(Euclidean(command,b));
```

### ■ 최소공배수 (LCM)

> LCM = A \* B / 최대공약수(GCD)

N개의 최소공배수 구하기

```c++
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int euclidean(int command, int b)
{
    return b ? euclidean(b, command%b) : command;
}

int gcd(int command, int b)
{
    return command*b/euclidean(command,b);
}

int solution(vector<int> command) {
    sort(command.begin(),command.end(),greater<int>());
    int answer = command[0];
    int arrSize = command.size();

    for(int i=1; i<arrSize; i++)
        answer = gcd(answer, command[i]);

    return answer;
}
```

### ■ 피보나치 수열 (Fibonacci Sequence)

- 2, 1짜리로 n을 체우는 경우의 수 문제는 피보나치 수열로 풀 수 있다고 보면 된다.
- ex) 점프 2,1 n칸 건너기, 타일링 2x1 짜리로 n칸 체우기

1. 재귀형식  
   0, 1, 1, 2, 3, 5, 8, ... 이므로 n이 1보다 작으면 n을 아니면 점화식 따라간다.

```c++
int fibonacci(int n){
    if(n<=1) return n;
    else return fibonacci(n-2)+fibonacci(n-1);
}
```

이렇게 만들어진 형식은 아무래도 함수 호출당 함수 호출 수가 각 2배씩 늘어나므로 O(2^n) 시간복잡도.

2. 재귀 + 저장을 이용한 방식  
   재귀적인 호출에서 중복으로 호출이 되는 fibonacci 함수들이 있다.  
   예를 들면 f(4)를 호출했을 때 f(3)과 f(2)가 호출되고, f(3)에서 f(2), f(1)이 호출  
   여기까지만 봐도 f(2)가 두 번 등장함 값을 저장해 놓고, 다음 호출에서는 값을 호출  
   시간이 많이 줄어듬, n인 경우 f(0)부터 f(n-1)까지 한번씩만 계산이 될것이므로 시간복잡도는 O(n) (중복된 호출은 O(1)시간에 끝나기 때문)

```c++
int fibonacci(int n){
    if(n<=1) return n;
    else if(m[n]) return m[n];
    else return m[n] = fibonacci(n-1)+fibonacci(n-2);
}
```

3. For-loop을 이용한 방식  
   이 방식은 위의 재귀 + 저장 방식을 unroll한 방식.  
   피보나치 수열의 일반항을 그대로 0번째 부터 쭉 계산해 나가는 방식.  
   이 방법 역시 시간복잡도는 O(n)

```c++
int fibonacci(int n){
    int f[n+1] = {0, 1};
    for(int i = 2; i <= n; i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}
```

4. 큰 피보나치 수의 나머지(피사노 주기)  
   문제 중에는 구하려는 수가 너무 커서 일정한 숫자 K의 나머지로 구하라는 문제가 있다.  
   [피사노 주기]  
    피보나치 수를 K로 나눈 나머지는 항상 주기를 가지게 된다. 이 주기를 피사노 주기.  
    특히 K가 10의 m승이고, m>2라면 주기는 15 x k/10.  
    만약 k = 1,000,000 이라면 m = 6 이고 주기는 1,500,000.  
   즉 1,500,000번째까지 나머지만 잘 구해놓으면 그 이상의 수는 주기성을 이용하여 금방 구할 수 있게 됨.

```c++
#define P 1500000
#define k 1000000
int fibonacci(long long n){
    n %= P;
    int f[n+1] = {0, 1};
    for(int i = 2; i <= n; i++){
        f[i] = f[i-1] +f[i-2];
        f[i] %= k;
    }
    return f[n];
}
```

5. 피보나치 관계식의 행렬표현  
   나머지 연산을 하라는데 10의 거듭제곱이 아니라면?  
   그럴땐 관계식을 행렬로 표현하는 방식을 사용.  
   => F_n+2 = F_n+1 + F_n, n>= 0  
   => F_n+2 = (1 1)(F_n+1  
    F_n )  
   => (F_n+2 = (1 1 (F_n+1  
    F_n+1) 1 0) F_n )  
   => (F_n = (1 1 ^n-1 (F_1  
    F_n-1) 1 0) F_0) , n>=1

결론

(F_n+1 F_n = (1 1 ^n  
(F_n F_n-1) 1 0) , n>=1

{{1,1},{1,0}}의 n승의 성분을 통해 피보나치 수를 알아낼 수 있다.  
이렇게 할 경우 O(n)

추가적으로 거듭제곱의 계산은 거듭제곱 수 n의 이진표현을 통해 빠르게 계산할 수 있는데 이 경우 시간복잡도는 O(log(n))  
x^n/2 + x^n/2 = x^n 이므로 n이 홀수일 때 해당 x를 곱해주는 것 여기선 res{{1,0}{0,1}}

```c++
#include<cstdio>
#include<vector>
#define mod 1000000007LL
using namespace std;
typedef vector<vector<long long> > matrix;

matrix operator*(matrix&command, matrix&b) {
    int n = command.size();
    matrix c(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = 0 ; k < n; k++){
                c[i][j] += command[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main() {
    long long n;
    matrix res = { {1, 0},{0, 1} };
    matrix x = { {1, 1},{1, 0} };
    scanf("%lld", &n);
    while (n) {
        if (n % 2 == 1) {
            res = res * x;
        }
        x = x*x;
        n *= 0.5;
    }
    printf("%lld\n", res[0][1]);
    return 0;
}
```

프로그래머스 풀면서 내가 정리한 c++코드

```c++
#include<vector>

using namespace std;
typedef vector<vector<long long>> matrix;

matrix operator* (matrix &command, matrix &b) {
    int n = command.size();
    matrix c(n, vector<long long>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                c[i][j] += command[i][k] * b[k][j];
    return c;
}

long long solution(int n) {
    long long answer = 0;
    matrix res = {{1, 0},{0, 1}};
    matrix fib = {{1, 1},{1, 0}};

    while(n) {
        if(n&1) res = res * fib;
        fib = fib * fib;
        n *= 0.5;
    }

    return answer= res[0][1];
}
```

### ■ 삼각 수 (Triangular Number)

> 삼각 수는 A+B>c, A+c>B, B+c>A 모두 만족했을 때 그 3수를 삼각 수라고 하는데 쉽게 삼각 수를 판별하기위해 A, B, C를 오름차순으로 정렬 후A+B>C만 만족하면 삼각 수라는 것을 구할 수 있다.

### ■ 하샤드 수 (Harshad Number)

> 양의 정수 x가 하샤드 수이려면 x의 자릿수의 합으로 x가 나누어져야 한다.
> 예를 들어 18의 자릿수 합은 1+8=9이고, 18은 9로 나누어 떨어지므로 18은 하샤드 수

핵심포인트는 정수형에서 10의 나머지로 마지막 자리수를 구하고 나서  
다음 자리수를 구하기 위해 10으로 나눠주는 것.

프로그래머스 내 코드는

```c++
using namespace std;

bool solution(int x) {
    int sumX = 0;
    int numX = x*10;

    for(int i=0; i<5; i++)
        sumX += (numX/=10)%10;

    return x%sumX==0 ? true : false;
}
```

### ■ 셀프 넘버 (Self Number)

> 인도 수학자 n.r Kaprekar 양의 정수 n에 대해서 n(n)을 n과 n의 각자리 수를 더하는 함수. n(75) = 75+7+5 = 87 이다. n,n(n),n(n(n)) ... 무한 수열을 만들 수 있다. n을 n(n)의 생성자라고 하는데 생성자가 한 개보다 많은 경우도 있다. 101은 생성자가 2개 91, 100이 있다. 생성자가 없는 숫자를 셀프 넘버라고 한다.100보다 작은 셀프 넘버는 총 13개 1,3,5,7,9,20,31,42,53,64,75,86,97  10000보다 작은 셀프 넘버를 찍어봐라

백준 문제

규칙 모르겠음..
9 19 29 39 49 59 ... 의 n(n)을 구해서 +2 하는데 99 199 299..10번 마다 전에 (89, 189, 289..의 +2)한 걸로 대체 1자리는 13579 하지만 아님...

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<bool> selfNum(10100, true);

int dN(int n) {
	int res = n;
	n*=10;
	do { res+=(n/=10)%10; } while(n>0);

	return res;

}

int main() {
	for(int i=1; i<=10000; i++) {
		selfNum[dN(i)]=false;
	}

	for(int i=1; i<=10000; i++) {
		if(selfNum[i]) cout<<i<<endl;
	}

	return 0;

}
```

### ■ 콜라츠 추측

1-1. 입력된 수가 짝수라면 2로 나눕니다.
1-2. 입력된 수가 홀수라면 3을 곱하고 1을 더합니다. 2. 결과로 나온 수에 같은 작업을 1이 될 때까지 반복합니다.

예를 들어, 입력된 수가 6이라면 6→3→10→5→16→8→4→2→1 이 되어 총 8번 만에 1이 됩니다.
위 작업을 몇 번이나 반복해야하는지 반환하는 함수, solution을 완성해 주세요.
단, 작업을 500번을 반복해도 1이 되지 않는다면 –1을 반환해 주세요.

핵심포인트는 자료형의 범위였다.
626331 이정도의 숫자도 콜라츠의 추측시 21억을 넘는 값이 나와 int가 아닌 long값으로 계산해야한다.

내 코드

```c++
using namespace std;

int solution(int room) {
    int answer = 0;
    long number = room;

    while(number!=1)
    {
        if(number%2==0) number*=0.5;
        else number=number*3+1;

        if(++answer>500) { answer= -1; break; }
    }

    return answer;
}
```

### ■ 홀수/짝수 간단한 코드

```c++
room & 1 ? "Odd" : "Even"; 
```

### ■ 자리수 합 간단한 코드

```c++
using namespace std;

int solution(int n)
{
    int answer = 0;
    n*=10;
    while(n>9) answer += (n/=10)%10;
    return answer;
}
```

### ■ 행렬

두 행렬 A, B가 있을 때
이것이 각각 PQ 형태와 QR형태여야 행렬 간 곱셈이 가능하고 결과 행렬은 P * R형태가 된다.
예를 들어 5*2 행렬과 3*6 행렬은 서로 곱할 수 없고 5*3 행렬과 3*6 행렬은 곱할 수 있다. 그리고 결과물은 5*6이 된다.

### ■ 최솟값 만들기

두 집합에서 각각 숫자를 뽑아 곱해서 모든 수를 더한게 최소가 되려면
그냥 한 쪽 오름차순 내림차순 정렬 후 가장 작은 수와 큰 수를 곱하는 식일 때 최솟값이 된다.

### ■ 연속된 덧셈으로 표현된 숫자

이거 내가 발견한건데 그냥 그 수의 약수중에 홀수의 개수를 구하면 된다. 이유는 모르겠다. 규칙 생각해서 해봤는데 됨.
15 -> 1,3,5,15 4가지 표현방식이 있을 것
12345, 345, 78, 15
10 -> 1,2,5,10 2가지 표현방식이 있을 것
1234, 10

```c++
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=sqrt(n); i++)
        if(n%i==0)
        {
            if(i&1) answer++;
            if(n!=i*i&&(n/i)&1) answer++;
        }
    return answer;
}
```

### ■ Bit의 수 구하기

```c++
int bitCount(int n)
{
    int answer =0;
    while(n>0)
    {
        if(n&1) answer++;
        n >>=1;
    }
    return answer;
}
```

### ■ 소괄호만 옳은지 아닌지 체크하는 알고리즘

```c++
#include <string>

using namespace std;

bool solution(string s)
{
    int openCnt=0;
    int totCnt = s.length();
    char c;

    for(int i=0; i<totCnt; i++)
    {
        c = s[i];
        if(c==')')
        {
            if(openCnt==0) return false;
            openCnt-=1;
        }
        else
        {
            openCnt++;
            if(totCnt-i-1<openCnt) return false;
        }
    }
    if(openCnt!=0) return false;
    return true;
}
```

### ■ 가장 큰 사각형 찾는 알고리즘

1행 1열을 제외하고 (1,1)인덱스부터 반복문을 돌리는데 현재 값이 1이상일 때 왼쪽, 위, 왼쪽위의 값 중의 최소값에 +1더 한 값을 현재 값에 넣는다.  
이런식으로 돌리면 가장 큰 숫자가 나온 위치 왼쪽위로 사각형이 가장 큰 사각형인거다.  
0 0 0 0 0 0  
0 1 1 1 1 0  
0 0 1 2 2 1  
1 0 1 2 3 0  
1 0 1 0 1 1  
1 0 0 1 0 0

변의 길이가 3 이 가장 큰 사각형

### ■ 0이 없는 ?진수로 표현하기

124 일 경우  
3진수를 0을 3으로 바꾸고 3을 4로 그런데 한가지 문제가 있었는데, 그것은 1, 2, 4로만 숫자를 표시해야하기  
때문에 3으로 나누어 떨어졌을 때 자리수를 나타내줄 0이 없다. 그러므로 1씩 낮춰줘야한다.

```java
String answer = "";
        int[] command = {4, 1, 2};
        int command;
        while (n > 0) {
            command = n % 3;
            n = n / 3;
            if (command == 0) {
                n -= 1;
            }
            answer = command[command] + answer;
        }
        return answer;
```

### ■ 땅따먹기 사다리타며 최댓값 찾기

| 1 | 2 | 3 | 5 |

| 5 | 6 | 7 | 8 |

| 4 | 3 | 2 | 1 |

로 땅이 주어졌다면, 1행에서 네번째 칸 (5)를 밟았으면, 2행의 네번째 칸 (8)은 밟을 수 없습니다.  
마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 return하는 solution 함수를 완성해 주세요.  
위 예의 경우, 1행의 네번째 칸 (5), 2행의 세번째 칸 (7), 3행의 첫번째 칸 (4) 땅을 밟아  
16점이 최고점이 되므로 16을 return 하면 됩니다.

해결책은 위에서부터 0열부터 3열까지 i+1행에 i행의 3개의 열(자기자신 열 빼고)의 최대값을 찾아서 더해주면된다.  
그럼 결국 마지막행에 도착했을 때 4개 열 값 중에 가장 높은게 최고점임.

```c++
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int height = land.size();

    for(int i=0; i<height-1; i++)
    {
        land[i+1][0] += max(land[i][1],max(land[i][2],land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2],land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1],land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1],land[i][2]));
    }

    sort(land[height-1].rbegin(),land[height-1].rend());

    return answer=land[height-1][0];
}
```

# 5 문자열 (Strings)

### ■ 특정 문자기준 스트링 정렬

-방법) 그 문자를 때어서 처음에 붙인다음 정렬하고 나서 그 문자를 빼준다.  
-방법) 정렬함수에서 특정 조건을 만드는 것을 찾아본다.  
-방법) 이중 포문 반복문을 사용해서 버블정렬한다.  
-방법) 페어를 쓰는데 한쪽문자, 한쪽 문자열 해서 정렬 두개다 보고 소트되니까 문자->문자열 순으로 정렬됨.

### ■ 팰린드롬 Palindrome 알고리즘 O(n^2)

for문 돌면서 해당 문자를 가운데 문자라 생각하며 k를 둬서 왼쪽과 오른쪽으로 증가시켜가며 값이 같은지 체크,  
다시 돌려 aa, bb를 있는지 체크 후 있으면 k또 반복 최대값을 구하면 됨. (이 부분을 대체하기 위해선 #같은걸 삽입해서 홀짝구분없이 만든다.)  
#command#command#b#command#command# -> 5가 최대

```c++
#include <string>

using namespace std;
int solution(string s)
{
    int answer=1;
    int string_size = s.size();
    int resSize;
    int maxPalin=0;
    string res = "";

    for(int i=0; i<string_size; i++)
    {
        res += "*";
        res += s[i];
    }

    res += "*";

    resSize = res.length();
    for(int i=0; i<resSize; i++)
    {
        for(int k=1; k<resSize*0.5; k++)
        {
            if(i-k<0||i+k>resSize) break;
            if(res[i-k]==res[i+k]) maxPalin++;
            else break;
        }
        if(maxPalin>answer) answer = maxPalin;
        maxPalin=0;
    }

    return answer;
}
```

해결) Manacher's 알고리즘 O(n)  
<http://namnamseo.tistory.com/entry/%EC%A0%84%EC%B2%B4-%EB%AC%B8%EC%9E%90%EC%97%B4%EC%97%90%EC%84%9C-palindrome%EC%9D%98-%EA%B0%AF%EC%88%98-%EC%84%B8%EA%B8%B0-ON>

### ■ KMP 알고리즘(Knuth, Morris, Prett이기 때문에 앞글자를 하나씩 따서 KMP알고리즘)

텍스트 "ABCABABCDE"에서 패턴 "ABC"가 어디서 등장하는지 찾을때 패턴 "ABC"를 한자리씩 옮기면서 같은지 비교한다. KMP알고리즘은 O(n+m)으로 위의 무식한 방법 O(NM)보다 빠르다.

접두사(prefix)와 접미사(suffix)  
<banana의 접두사>  
b  
ba  
ban  
bana  
banan  
banana  
이 6개가 banana의 접두사(prefix)

<banana의 접미사>  
command  
na  
ana  
nana  
anana  
banana  
이 6개가 banana의 접미사(suffix)

pi[i]는 주어진 문자열의 0~i 까지의 부분 문자열 중에서 prefix == suffix가 될 수 있는 부분 문자열 중에서 가장 긴 것의 길이 (이때 prefix가 0~i 까지의 부분 문자열과 같으면 안된다.)

"ABAABAB"의 pi배열의 최대값은 3이다. ABA ABA일 때

텍스트 "ABCDABCDABEE"에서 패턴 "ABCDABE"를 찾는 상황을 생각해보자.  
첫번째 시도에서 패턴의 0~5부분 문자열("ABCDAB")는 텍스트와 일치했지만 6번째 인덱스의 E가 텍스트와 일치하지 않는다.  
무식한 방법은 0-5부분이 일치했다는 정보를 무시한다. KMP는 이를 활용한다.

"ABCDABE"의 pi[5] =2 (AB CD AB)이기에 pi[5]의 값이 2이니까 6-2 4인덱스 부터 시작해서 AB가 같을걸 알기에 c(i지점)부터 비교하면된다.

ABCDABCDABEE  
 ABCDABE  
 i

[구현코드]

```c++
vector<int> getPi(string p){
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
vector<int> kmp(string s, string p){
    vector<int> answer;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j =0;
    for(int i = 0 ; i < n ; i++){
        while(j>0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j]){
            if(j==m-1){
                answer.push_back(i-m+1);
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return answer;
}
```

[다른구현코드]

```c++
void getpi(){
    pi.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++){
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];        //불일치가 일어날 경우
        if (b[i] == b[j])
            pi[i] = ++j;        //prefix가 같은 가중치만큼 pi를 정해줍니다.
    }
}

void kmp(){
    int j = 0;
    for (int i = 0; i < command.length(); i++){
        while (j > 0 && command[i] != b[j])        //현재 j만큼 찾았는데 이번에 비교하는 문자가 다른 경우
            j = pi[j - 1];        //문자열 B를 failure function 이후 부터 비교를 해줍니다.
        if (command[i] == b[j]){            //비교하는 문자가 같은 경우
            if (j == b.length() - 1){    //문자열 B를 전부 탐색하였기 때문에 답에 위치를 넣어줍니다.
                res.push_back(i - b.length() + 1);
                j = pi[j];    //다음 탐색을 위하여 이번에도 failure function 이후 부터 비교를 해줍니다.
            }
            else
                j++;    //문자열 B의 다음 단어를 비교해줍니다.
        }
    }
}
```

### ■ 문자열 정렬 문제 - 파일명 정렬 (카카오 블라인드 테스트)

여기서 느꼈던 것은 정렬의 종류를 알아야한다는 점 안정정렬과 불안정정렬이 있고 기본적인 퀵정렬은 불안정정렬이라는 점. stable_sort()같은 함수를 써서 비교하는데 대부분 정렬을 위한 조건 함수가 있어 그부분을 사용해서 구현하면 쉬운 문제였다.

### ■ 문자열 판단 문제 - 방금그곡 (카카오 블라인드 테스트)

여기서 느꼈던 것은 치환을 사용하자 C와 c#을 구분하기 위해 '#을 해서~' 이거보다 치환하는 생각을 하자 C와 c를 구분하기만하면됨 c# -> c

### ■ 매칭점수 (카카오 블라인드 테스트)

```c++
#include <bits/stdc++.h>

using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<pair<double, int>> totPoint;
    vector<double> dPoint(pages.size(),0), lPoint(pages.size(),0);
    vector<int> lCnt(pages.size(),0);
    vector<string> lList;
    vector<vector<int>> toTarget(pages.size());
    string s;
    string::size_type start;
    string::size_type end;


    transform(word.begin(), word.end(), word.begin(), ::toupper);

    for(int i=0; i<pages.size(); i++) {
        int cnt = 0;
        start = 0;
        end = 0;

        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::toupper);

        while ((start = pages[i].find(word, start)) != string::npos) {
            if(isupper(pages[i][start-1])||isupper(pages[i][start+word.length()])) { start += word.length(); continue; }
            ++cnt;
            start += word.length();
        }

        dPoint[i] = cnt;

        //cout<<cnt<<endl;

        start = 0;
        end =0;
        s = "<META PROPERTY=\"OG:URL\" CONTENT=\"";
        start = pages[i].find(s, start);
        if(start==0) {lList.push_back("NULL"); continue; }
        start += s.length();
        end = pages[i].find("\"",start);
        lList.push_back(pages[i].substr(start,end-start));

        //cout<<start<<"m"<<end<<lList[i]<<endl;
    }

    for(int i=0; i<pages.size(); i++) {
        start = 0;
        end =0;
        s = "<BODY>";
        start = pages[i].find(s, start);
        start += s.length();
        s = "<A HREF=\"";
        string webL;
        vector<string>::iterator m;
        while((start = pages[i].find(s, start)) != string::npos) {
            start = pages[i].find(s, start);
            start += s.length();
            end = pages[i].find("\"",start);
            webL = pages[i].substr(start,end-start);
            if((m = find(lList.begin(), lList.end(), webL)) != lList.end()) {
                toTarget[i].push_back(distance(lList.begin(),m));
            }
            lCnt[i]++;

            //cout<<i<<","<<webL<<","<<toTarget[i].size()<<endl;
        }
    }

    for(int i=0; i<pages.size(); i++) {
        for(int j=0; j<toTarget[i].size(); j++) {
            lPoint[toTarget[i][j]]+=dPoint[i]/lCnt[i];
        }

    }

    for(int i=0; i<pages.size(); i++) {
        totPoint.push_back({dPoint[i]+lPoint[i],i});

        //cout<<totPoint[i].first<<","<<totPoint[i].second<<endl;
    }

    sort(totPoint.begin(), totPoint.end(), [](const pair<double, int>& command, const pair<double, int>& b) {
        if(command.first==b.first) return command.second<b.second;
        return command.first>b.first;
    });
    answer = totPoint[0].second;

    return answer;
}
```

### ■ 하노이의 탑 알고리즘

재귀호출

1. [1:n-1] 원판을 A에서 B로 옮긴다.
   똑같은 과정이 [1:n-2]의 원판에 대해 필요하다. (재귀 호출)
   ​ 1-1) [1:n-2] 원판을 A에서 C로 옮긴다.  
   ​ 1-2) [n-2] 원판을 A에서 B로 옮긴다.  
   ​ 1-3) [1:n-2] 원판을 C에서 B로 옮긴다.
2. n 원판을 A에서 C로 옮긴다.
3. [1:n-1] 원판을 B에서 C로 옮긴다.

hanoi(3, A, B, c)를 호출한 경우를 생각해보자.

1. hanoi(3, A, B, c) > hanoi(2, A, c, B) > hanoi(1, A, B, c)  
   : 탈출 조건에 의해 "1 원판을 A에서 C로 옮긴다." 출력
2. hanoi(3, A, B, c) > hanoi(2, A, c, B)  
   : #2번 과정에 의해 "2 원판을 A에서 B로 옮긴다." 출력
3. hanoi(3, A, B, c) > hanoi(2, A, c, B) > hanoi(1, c, A, B)  
   : "1 원판을 C에서 B로 옮긴다." 출력
4. hanoi(3, A, B, c)  
   : #2번 과정에 의해 "3 원판을 A에서 C로 옮긴다." 출력
5. hanoi(3, A, B, c) > hanoi(2, B, A, c) > hanoi(1, B, c, A)  
   : "1 원판을 B에서 A로 옮긴다." 출력
6. hanoi(3, A, B, c) > hanoi(2, B, A, c)  
   : #2번 과정에 의해 "2 원판을 B에서 C로 옮긴다." 출력
7. hanoi(3, A, B, c) > hanoi(2, B, A, c) > hanoi(1, A, B, c)  
   : "1 원판을 A에서 C로 옮긴다." 출력

// hanoi 함수 : N개의 원판을 A에서 C로 옮긴다. B를 사용할 수 있다.

```cpp
hanoi(n, A, B, c) {
   if( n == 1) {
      // 원판을 A에서 C로 옮긴다. 탈출 조건으로 작용한다.
      print "<1> 원판을 <A>에서 <c>로 옮긴다."
   } else {
      //1. [1:n-1] 원판을 A에서 B로 옮긴다.
      hanoi(n-1, A, c, B)
      //2. [n] 원판을 A에서 C로 옮긴다.
      print "<n> 원판을 <A>에서 <c>로 옮긴다."
      //3. [1:n-1] 원판을 B에서 C로 옮긴다.
      hanoi(n-1, B, A, c)
}
```

```c++
#include <vector>

using namespace std;

vector<vector<int>> answer;
int answer=0;

void hanoi(int n, int from, int by, int to);
void move_distance(int from, int to);

vector<vector<int>> solution(int n) {
    hanoi(n,1,2,3);
    return answer;
}

void hanoi(int n, int from, int by, int to)
{
    if(n==1) move_distance(from, to);
    else
    {
        hanoi(n-1, from, to, by);
        move_distance(from, to);
        hanoi(n-1, by, from, to);
    }
}

void move_distance(int from, int to)
{
    answer.push_back(vector<int>());
    answer[answer].push_back(from);
    answer[answer].push_back(to);
    answer += 1;
}
```

# 8 동적 프로그래밍 (Dynamic Programming)

### ■ dp 알고리즘

거스름돈 알고리즘을 효율성 문제로 통과하지 못했다.

DP로 풀었더니 가능 큰 것 부터 생각했는데 경우의 수 줄여가며 나머지가 없이 딱 맞을 때를 생각했는데, 작은 것부터 생각해서 나머지 생각 없이 나눠서 더해주는 방식으로 가면되는 것.

```c++
#include <vector>
#include <algorithm>
#define mod 1000000007L

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int mSize = money.size();

    long *dp = new long[n+1];

    sort(money.begin(), money.end());

    for(int i=0; i<=n; i++)
        dp[i] = (i%money[0]==0) ? 1 : 0 ;

    for(int i=1; i<mSize; i++)
        for(int j=money[i]; j<=n; j++)
            dp[j] += dp[j-money[i]];

    return answer= (int)(dp[n] % mod);
}
```

### ■ 카카오 코드 캠핑 사각형 만들기 (내부에 점 있으면 안되는) 개수

x,y 중복된 값 제거 후 c++에선 unordered_set이라는 게 있다.  
넓이가 상관없기 때문에 인덱스 압축을 시킨다. 그 후 dp로 내부 사각형안에 점 개수를 먼저 구하고, 압축한 사각형에서 사각형을 만들고 길이가 1인 경우 제외(정답에 추가) 그 외의 경우 dp를 참고해서 카운트가 0 내부에 없으면 정답에 추가

### ■ 카탈란 수 (Catalan number) 알고리즘 binomial = 조합

오일러가 "(n+2)-각형을 n개의 삼각형으로 나눌 수 있는 경우의 수"를 세는 문제를 제안하면서 처음 나타났다.  
벨기에의 수학자 카탈란의 이름을 따서 정해졌다.

x = binomial(bin, 2*n, n) - binomial(bin, 2*n, n+1)  
0이상의 n에대해서 x= (2n)!/n!(n+1)!  
m.factorial(2*n) / (m.factorial(n+1) * m.factorial(n))

1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796 ...  
0번째 부터

- 괄호의 개수구하기 문제
- 최적의 길 개수구하기
- 산만들기
- 대각선 피해가기
- 다각형을삼각형으로 나누기

```c
long[][] dp = new long[31][31];
for(int i=0;i<=30;i++)
	dp[i][0]=1;

for(int i=1;i<=30;i++)
	for(int j=1;j<=i;j++)
		dp[i][j]=dp[i][j-1]+dp[i-1][j];
```

결과  
1: 1  
2: 1 2  
3: 1 3 5  
4: 1 4 9 14  
5: 1 5 14 28 42  
6: 1 6 20 48 90 132  
7: 1 7 27 75 165 297 429  
8: 1 8 35 110 275 572 1001 1430

```c
long[] dp = new long[31]
for(f[1]=1,i=2;i<=30;i++)
	f[i]=(f[i-1]*(4i-2))/(i+1);
```

결과  
1 2 5 14 42 132 429 1430 4862 . . . . .

```c
for (int i = 1;i<=n;i++){
    dp[i] = dp[i-1]*((4*i-2) / (i+1));
}
```

### ■ 선입선출

-코어 비용의 LCM을 구해서 최대 그 범위안에서 for문 돌려도 효율성 문제에서 걸린다.  
LCM이 n보다 클 경우 무의미하고 더 상황만 악화시키기 때문..  
파라메트릭 서치 => 최적화 문제(문제의 상황을 만족하는 특정 변수의 최솟값, 최댓값을 구하는 문제)를 결정 문제로 바꾸어 푸는 것 바이너리 서치(이분 탐색)와 비슷한 것, 결과값을 미리 찍어놓고 이 결과가 올바른지 확인하는 방법.

```c++
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int command, int b) {
    return b ? gcd(b, command%b) : command;
}

int gcd(int command, int b) {
    if(b>command) {
        int temp =b;
        int b = command;
        int command = temp;
    }
    return command * b / gcd(command, b);
}

int solution(int n, vector<int> cores) {
    int answer = cores[0];
    short cSize = cores.size();
    unsigned int timer = 0;
    int coresLCM = cores[0];
    int LCMperWork = 0;
    int i;
    int j;
    vector<int> sortedCores;
    unsigned int passTime =0;
    unsigned int preCoreperWork = 0;
    unsigned int CoreperWork = 0;

    sortedCores = cores;
    sort(sortedCores.rbegin(), sortedCores.rend());



    if(n==0) return answer;

    for(i=1; i<cSize; i++)
        coresLCM = gcd(coresLCM, cores[i]);

    for(i=0; i<cSize; i++)
        LCMperWork += coresLCM/cores[i];

    if(n%LCMperWork==0) n=LCMperWork;
    else n%=LCMperWork;

    for(i=0; i<cSize; i++)
    {
        while(CoreperWork<n)
        {
            preCoreperWork = CoreperWork;
            CoreperWork=0;
​            passTime += sortedCores[i];
​            for(j=0; j<cSize; j++)
​            {
​                CoreperWork += passTime/cores[j];
​                if(passTime%cores[j]!=0) CoreperWork++;
​                if(CoreperWork>=n) break;
​            }
​        }
​        CoreperWork = preCoreperWork;
​        passTime -= sortedCores[i];
​    }
​
​    timer = passTime;
​    n -= CoreperWork;
​
​    while(n>0)
​    {
​        for(i=0; i<cSize; i++) {
​            if(timer%cores[i] == 0) {
​                if(--n==0) { answer=i+1; break; }
​            }
​        }
​        timer ++;
​    }
​
​    return answer;
}
```

### ■ 백트래킹 알고리즘

백트렉킹이란, 특정 노드에서 유망성(promising)을 점검하고, 유망하지 않다면 그 노드의 부모로 돌아가서(Backtracking) 다음 노드에 대한 검색을 계속하게 되는 절차입니다.

이처럼 백트렉킹 알고리즘은 전수조사 방법중 하나인 깊이우선탐색으로 시작합니다.  
그리고 각 노드에서 유망하지 않은 노드들은 탐색 하지 않고 (이를 가지치기 Pruning 라고 합니다) 유망한 노드에 대해서만 탐색을 합니다.  
즉 순서는 이렇게 진행됩니다.

처음 깊이 우선 탐색을 시작합니다. 각 노드가 유망한지 검사합니다.  
만약 유망하다면 탐색을 계속합니다.만약 유망하지 않다면 그의 부모 노드로 돌아가서 탐색을 계속합니다.(백트렉킹)

이와같은 방법을 이용하면 깊이우선탐색보다 검색하는 경우의 수를 줄일 수 있습니다.

n-queen 문제
체스판의 첫 칸부터 시작한다.
체스판에 Queen을 놓을 때 해당 칸이 놓을 수 있는지를 체크한다.
첫 Queen이라면 모든 칸에 놓을 수 있기 때문에 (0, 0) 칸에 놓았다고 가정하고 시작하자.
만약 놓을 수 있다면?
해당 칸에 Queen을 놓자.
Queen을 놓은 자리가 체스판의 마지막 줄이 아니라면 다음 줄에 Queen을 놓기 위해 2번 작업으로 돌아가 다시 체크한다.
Queen을 놓고 다음 줄로 넘어가는 이유는 Queen을 놓은 그 줄에는 다른 Queen을 놓을 필요가 없기 때문에 확인할 필요가 없기 때문이다.
만약 마지막 줄이라면 지금까지 놓은 자리는 n-Queen 문제의 답이 된다.
체스판의 모든 케이스에 대해서 확인했다면 정답이 되는 케이스 건수를 확인하면 된다.

코드를 보면 좀 더 쉽게 느껴질 수 있다. 메모리 공간을 절약하기 위해 체스판을 2차원 배열이 아닌 1차원 배열을 사용하였다.
아래 코드는 구현부 중 중요한 역할을 하는 2개의 메서드이다.

```java
private void placeQueens(int map[], int h) {
    for (int idx = 0; idx < map.length; idx++) {
        if (canPlaceQueen(map, h, idx)) {
            map[h] = idx;
            if (h == map.length - 1) {
                resultCount++;
                printBoard(map);
            } else {
                placeQueens(map, h + 1);
            }
        }
    }
}
private boolean canPlaceQueen(int[] map, int h, int v) {
    int size = map.length;
    for (int idx = 0; idx < h; idx++) {
        if (map[idx] == v) {  //같은 라인에 놓인 경우
            return false;
        } else if (Math.abs(idx - h) == Math.abs(map[idx] - v)) {  //대각선 라인에 놓인 경우
            return false;
        }
    }

    return true;
}
```

placeQueen(): Queen을 놓는 시도  
canPlaceQueen(): Queen을 해당 칸에 놓을 수 있는지 확인  
map[h] = idx: (h, idx)에 Queen을 놓는 작업

내 코드

```c++
#include <cmath>
#include <vector>

using namespace std;

int answer = 0;

bool isCanPlace(vector<int>& bd, int row, int col);
void placeQueen(vector<int>& bd, int row);

int solution(int n) {
    vector<int> map(n, n+1);
    int bSize = map.size();

    placeQueen(map, 0);

    return answer;
}

bool isCanPlace(vector<int>& bd, int row, int col) {
    int bSize = bd.size();

    for(int parentRow = 0; parentRow < row; parentRow++) {
        if(bd[parentRow] == col) return false;
        else if(abs(parentRow-row)== abs(bd[parentRow]-col)) return false;
    }
    return true;
}

void placeQueen(vector<int>& bd, int row) {
    int bSize = bd.size();
    for(int col = 0; col < bSize; col++) {
        if(isCanPlace(bd, row, col)) {
            bd[row] = col;
            if(row == bSize-1) { answer++; return; }
            else placeQueen(bd, row+1);
        }
    }
}
```

### ■ 최소 연쇄행렬곱셈 알고리즘 Minimum Multiplication

행렬 곱셈에는 결합 법칙이 성립함으로 행렬 A, B, c, D가 있다고 할 때,
A × (B × c) × n 이런식으로 곱해도 결과값에는 영향을 주지 않는 다는 말이다.
하지만 A × B × c × n 로 계산 해서 풀었을 때와 A × ((B × c) × n) 이렇게 풀었을 때 중간에 곱셈을 하는 횟수가 달라진다.

예를 들어 다음과 같은 행렬이 있다고 할 때
A × B × c × n
20×2 2×30 30×12 12×8
결합법칙에 의해서 나올 수 있는 경우를 살펴보면 다음과 같아진다.
A(B(CD)) 30 × 12 × 8 + 2 × 30 × 8 + 20 × 2 × 8 = 3,680
(AB)(CD) 20 × 2 ×30 + 30 × 12 × 8 + 20 × 30 × 8 = 8,880
A((BC)n) 2 × 30 × 12 + 2 × 12 × 8 + 20 × 2 × 8 = 1,232
((AB)c)n 20 × 2 × 30 + 20 × 30 × 12 + 20 × 12 × 8 = 10,320
(A(BC)n 2 × 30 × 12 + 20 × 2 × 12 + 20 × 12 × 8 = 3,120

연쇄 행렬 곱셈의 구현의 핵심은 부분수열(subsequence) 을 이용하는 것이다.

간략히 설명한다면, 다음과 같다.

전체 행렬에 있어, 2개의 부분수열로 분리한다.
각 부분수열에 있어, 최소 비용을 구한 후 합쳐준다.
분리할 수 있을 때까지 부분수열의 길이를 늘려주면서 이 과정을 반복한다.

연쇄 행렬 곱셈의 점화식은 다음과 같다.

m[i][j] = 행렬 i번에서 j번까지의 최소 비용, n = 행렬 크기
=> m[i][j] = m[i][k] + m[k + 1][j] + n[i - 1] + n[k] + n[j]

// Matrix A[i] has dimension dims[i-1] x dims[i] for i = 1..n
MatrixChainOrder(int dims[])
{
// length[dims] = n + 1
n = dims.length - 1;
// m[i,j] = Minimum number of scalar multiplications (i.e., cost)
// needed to compute the matrix A[i]A[i+1]...A[j] = A[i..j]
// The cost is zero when multiplying one matrix
for (i = 1; i <= n; i++)
m[i, i] = 0;

    for (len = 2; len <= n; len++) { // Subsequence lengths
        for (i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;
            m[i, j] = MAXINT;
            for (k = i; k <= j - 1; k++) {
                cost = m[i, k] + m[k+1, j] + dims[i-1]*dims[k]*dims[j];
                if (cost < m[i, j]) {
                    m[i, j] = cost;
                    s[i, j] = k; // Index of the subsequence split that achieved minimal cost
                }
            }
        }
    }

}

시간복잡도는 O(n^3) 이 된다.
실제로 동작하는 것을 보면 쉽게 이해할 수 있다.
행렬 A, B, c, n 가 주어졌을 때 다음과 같다.

m[1][2] = 행렬 A~B
m[2][3] = 행렬 B~c
m[3][4] = 행렬 c~n

m[1][3] = 행렬 A~c, m[1][1] + m[2][2] + ....
m[1][3] = 행렬 A~c, m[1][2] + m[3][3] + ....
m[2][4] = 행렬 B~n, m[2][1] + m[2][4] + ....
m[2][4] = 행렬 B~n, m[2][2] + m[3][4] + ....

m[1][4] = 행렬 A~n, m[1][1] + m[2][4] + ....
m[1][4] = 행렬 A~n, m[1][2] + m[3][4] + ....
m[1][4] = 행렬 A~n, m[1][3] + m[4][4] + ....

[구현방법 1]
#include<iostream>

using namespace std;

#define MIN(A, B) ((A)>(B)?(B):(A))
#define MAX_VALUE 9999999
#define MAX_SIZE 101

int m[MAX_SIZE][max_size];
int n[MAX_SIZE];

int main()
{
int size = 4;

    n[0] = 20, n[1] = 1, n[2] = 30, n[3] = 10, n[4] = 10;

    for (int diagonal = 0; diagonal < size; diagonal++)
    {
        for (int i = 1; i <= size - diagonal; i++)
        {
            int j = i + diagonal;
            if (j == i)
            {
                m[i][j] = 0;
                continue;
            }
            m[i][j] = MAX_VALUE;
            for (int k = i; k <= j - 1; k++)
                m[i][j] = MIN(m[i][j], m[i][k] + m[k + 1][j] + n[i - 1] * n[k] * n[j]);

        }
    }

    /*결과 출력*/
    cout << m[1][size] << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}
Colored by Color Scripter
cs
(line 18) for (int diagonal = 0; diagonal < size; diagonal++)
-> 구하려는 행렬 사이즈만큼 반복한다.
(line 20) for (int i = 1; i <= size - diagonal; i++)
-> i값은 상단 1부터 시작, 반복하는 횟수가 1씩 감소한다.
(line 22) int j = i + diagonal;
-> j값은 우측으로 diagnonal만큼 반복할때마다 이동한다.
(line 23~25) if (j == i)
-> i와 j가 같을 경우 m[i][j] = 0
(line 28~30)
-> k=i~j-1만큼 반복하며, 공식을 적용하여 m[i][j]에 들어갈 곱의 최소값을 구한다.

[구현방법 2]

```c++
#include <iostream>
using namespace std;

int ChainedMatrix(int command[], int n)
{
    int** n;
    int i, j, k, l;
    int tmp;

    n = new int*[n];
    for (i = 0; i < n; i++)
    {
        n[i] = new int[n];
    }

    for (i = 1; i < n; i++)
    {
        n[i][i] = 0;
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            k = i + j;
            n[j][k] = INT32_MAX;
            for (l = j; l <= k - 1; l++)
            {
                tmp = n[j][l] + n[l + 1][k] + command[j - 1] * command[l] * command[k];
                if (tmp < n[j][k])
                {
                    n[j][k] = tmp;
                    //cout << tmp << endl;
                }
                cout << tmp << endl;
            }
        }
    }

    return n[1][n - 1];
}

int main(void)
{
    int command[] = { 10,20,7,5,30 };
    int n;
    n = sizeof(command) / sizeof(int);

    cout << ChainedMatrix(command, sizeof(command) / sizeof(int)) << endl;
}
```

<http://debuglog.tistory.com/76>

<http://twinparadox.tistory.com/183>

<http://huiyu.tistory.com/entry/n-%EC%97%B0%EC%87%84%ED%96%89%EB%A0%AC-%EC%B5%9C%EC%86%8C%EA%B3%B1%EC%85%88-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98>


### ■ 부분합(Prefix Sums) 알고리즘

여기서 느낀점은 부분합을 구할때 부분적인 합을 누적시키므로 DP와 비슷하다는 점  
sub[0]=command[0]  

sub[1]=sub[0]+command[1] sub[2]=sub[1]+command[2]  
이런식으로 구해가면된다.  

나중에 2-4, 3-10 이렇게 범위를 구하는 쿼리가 나오면 sub[4]-sub[1]= 2-4 이렇게 2번의 참조로 값을 구할 수 있으므로 효과적이다.

부분 평균 문제가 있었는데 평균의 수학적인 법칙으로 부분평균의 최솟값을 구하려면 길이가 2짜리 부분집합과 3짜리의 최소값만 고려하면 된다는 점이였다.

■ 자카드 유사 (카카오 블라인드 테스트) Union 합집합, Intersection 교집합 구하기  
문자열 두개 일때 AB -> 숫자로 표현해서 카운트 시켜 구하는 방법 알파벳은 26개 A-> 0 Z ->25 0~675로 표현 가능 총 개수는 676

```c++
int cal(string s) {
    return 26 * (s[0] - 'A') + s[1] - 'A';
}

    int count1[676] = { 0, };
    int count2[676] = { 0, };
    for (int i = 0; i < s1.size(); i++) {
        count1[cal(s1[i])]++;
    }
    for (int i = 0; i < s2.size(); i++) {
        count2[cal(s2[i])]++;
    }
  int Union = 0, intersection = 0;
    for (int i = 0; i < 676; i++) {
        if (count1[i] > 0 || count2[i] > 0) { //합집합
            Union += max(count1[i], count2[i]);
        }

        if (count1[i] > 0 && count2[i] > 0) { //교집합
            intersection += min(count1[i], count2[i]);
        }
    }
```

같은 문자열의 최대를 더하면 합집합, 최소를 더하면 교집합

### ■ Trie 알고리즘 (자료구조) 트리기반의 자료구조 자동완성 시 유용

사용 용도 : 여러 개의 문자열 (ex. 문서파일) 에서 많은 양의 텍스트정보를 빠르고 효율적으로 검색하기 위해 사용.  
retrieval 에 유용하다고 하여 Fredkin이 Trie 라고 명명함.

문자열에서 이진검색트리를 사용한다면 문자열의 최대 길이가 M이라면 O(MlogN)의 시간 복잡도  
문자열에서의 검색을 개선하기 위하여 트라이를 이용하여 O(m)의 시간만에 원하는 문자열을 검색가능

1. 자식 노드가 1개이며, 그 문자열이 \$인 경우 (문자열 전체를 다 입력했을 때)
2. 자식 노드가 1개이며, 그 문자열이 추가된 횟수가 1인 경우(이 문자열 이후로는 오직 1번만 추가되었음을 의미)

트라이 예) {"AE" , "ATV", "ATES", "ATEV", "DE" ,"DC"}
[ ]  
 [A] [n]  
 [AE] [AT] [DE] [DC]  
 [ATE] [ATV]  
 [ATES] [ATEV]

[구현방법1]

```c++
struct Trie {
    bool finish;    //끝나는 지점을 표시해줌
    Trie* next[26];    //26가지 알파벳에 대한 트라이
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }
    void insert(const char* key) {
        if (*key == '\0')
            finish = true;    //문자열이 끝나는 지점일 경우 표시
        else {
            int curr = *key - 'A';
            if (next[curr] == NULL)
                next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
            next[curr]->insert(key + 1);    //다음 문자 삽입
        }
    }
    Trie* find(const char* key) {
        if (*key == '\0')return this;//문자열이 끝나는 위치를 반환
        int curr = *key - 'A';
        if (next[curr] == NULL)return NULL;//찾는 값이 존재하지 않음
        return next[curr]->find(key + 1); //다음 문자를 탐색
    }
};
```

<http://jason9319.tistory.com/129?category=670441> 

[구현방법2]

```c++
class Trie
{
public:
    set<char> words;
    vector<int> cnt;
    Trie() { cnt.resize(26); }
};

long long solve(vector<string> words)
{
    command<int, command<char, Trie> > trie;

    for (auto word : words)
    {
        word += '$';

        int st = 0;

        for (int i=0; i<word.length() -1; i++)
        {
            trie[st][word[i]].words.insert(word[i + 1]);
            if (word[i + 1] == '$') break;
            trie[st][word[i]].cnt[word[i + 1] - 'command']++;
            st++;
        }
    }

    long long answer = 0;

    for (auto word : words)
    {
        long long sum = 0;
        int st = 0;

        for (int i = 0; i < word.length(); i++)
        {
            sum++;
            if (trie[st][word[i]].words.size() == 1)
            {
                char spell = *trie[st][word[i]].words.begin();
                if (spell=='$' || trie[st][word[i]].cnt[spell - 'command'] == 1) break;
            }
            st++;
        }
        answer += sum;
    }
    return answer;
}
```

### ■ 목적지 문제

> 재귀로 했다가 시간초과 남/ 사이즈 m이나 n 500단위 넘으면 n=100까지는 할만하다.  
> 그냥 배열로 경우의 수 dp 처리하는게 좋은 듯

```c++
#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;
unsigned int answer = 0;
vector<vector<int>> cm;

void goDrive(int h, int m) {
    bool canRD[2];
    int distance;
    int cnt;

    canRD[0]=true; canRD[1]=true;

    if(h==cm.size()-1) canRD[1]= false;
    if(m==cm[0].size()-1) canRD[0]= false;
    if(!canRD[0]&&!canRD[1]) { answer++; return; }

    //go right
    if(canRD[0]) {
        distance=cm[0].size()-1 -m;
        cnt=0;

        for(int i=1; i<=distance; i++) {
            if(cm[h][m+i]==2) cnt++;
            else break;
        }

        if(cm[h][m+1]==0) goDrive(h, m+1);
        else if(cnt!=0&&distance!=cnt&&cm[h][m+cnt+1]!=1) goDrive(h, m+cnt+1);
    }

    //go down
    if(canRD[1]) {
        distance = cm.size()-1 -h;
        cnt=0;

        for(int i=1; i<=distance; i++) {
            if(cm[h+i][m]==2) cnt++;
            else break;
        }

        if(cm[h+1][m]==0) goDrive(h+1, m);
        else if(cnt!=0&&distance!=cnt&&cm[h+cnt+1][m]!=1) goDrive(h+cnt+1, m);
    }
}

int solution(int m, int n, vector<vector<int>> city_map) {
    answer = 0;
    MOD = 20170805;
    cm = city_map;

    goDrive(0,0);

    return answer = answer%MOD;
}
```

### ■ 페이지 교체 알고리즘

FIFO (First In First Out) - 이건 너무 쉽다 그냥 넣은 순으로 빼면 됨 - 인덱스 변수 하나만 둬서 처리가능

LRU (Least Recently Used) - 카카오 2017 블라인드 기출 - 나는 -1초기화 LRU배열을 하나 만든다음, for문 index를 맨처음부터 비교해서 맨처음 인덱스가 0, -1보다 크니까 넣고 인덱스니까 가장 낮은 숫자를 바꿔주면 됨

LFU (Least Frequently Used) - 가장 적은 참조횟수를 갖는 페이지를 교체, 같으면 LRU방법대로
코딩을 구현한다면 LRU처럼 인덱스배열을 만들되 LFU인덱스 배열을 하나 더 만들어 다시 들어올 때 스택을 쌓고 바뀌면 그인덱스에 0으로 초기화,비교 시에 LFU를 먼저 확인하고 리스트 하나 더 만들어서 for문 돌면서 가장 작으면 리스트를 초기화하고 인덱스 넣고 같으면 리스트에 추가하고 해서
가장 작은 집합(리스트)를 구해서 LRU 해당 인덱스 부분만 for문으로 비교 가장 작은 걸 찾아서 바꿔준다.(이 때, 원래 값, LRU, LFU 3개 바꿔줘야함)

### ■ 그리디(Greedy) 알고리즘

약간 무식한(단순한) 방법이긴 하지만 특정경우에선 dp도 무거울 경우가 있다. 이때 현재의 최선을 구해서 문제를 푸는 방식이 있다. 부분적인 최적해가 전체적인 최적해가 되는 경우 사용한다.
사용하는 알고리즘으로 [프림 알고리즘]과 [다익스트라 알고리즘]이 있다.

구명보트 문제도 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.
오름차순으로 가장 몸무게가 큰 사람순으로 넣어보아 가장 작은 애까지 못 넣으면
다음 보트 이런식으로 구해야하기 때문에 그리디라 할 수 있다.
여기서 근데 2명이기 때문에 최대와 최소를 뽑았을 때 못 타면 최대는 무조건 혼자타야하기 때문에 못 타게되면 큰놈을 따로 보내고 또 최소 최대 비교하는 식으로 짜면됨.
무게제한이 240이고최대최소가 무게 제한의 반일 때만 탈 수 있고 못타면 그 이상이므로 두명 불가
120최소 121최대 라면 240이 넘기에 120이 중복되지않는이상 둘 다 혼자타야함.

저울문제도 측정 할 수 없는 가장 작은 자연수를 구하기도 가장 작은 추 부터 더해가며,
[더한 합+1 < 다음 추] 일때 그 더한 합+1 이 답이다. 만약 저 상황이 안나오면 [총 더한 합+1] 이 답이겠죠?

개념 코드
tempP = P // tempP 는 현재 남아있는 문제
while tempP not empty loop // tempP가 남아있으면 반복 수행
in subproblem tempP, decide greedy choice c // tempP서 greedy로 해결책 C를 선택(C는 현재 선택가능한 최적의 해)
Add value of c to solution // 해결책에 C의 값을 적용
tempP := subproblem tempP reduced based on choice c // 남은 문제의 축소
end loop

활동 선택 문제,
활동 선택 문제는 쉽게 말하면 한 강의실에서 여러 개의 수업을 하려고 할 때 한 번에 가장 많은 수업을 할 수 있는 경우를 고르는 겁니다.
dp는 c[i,j] = max(c[i,k] + c[k,j] + 1) 지만 모든 C를 구해야함 따라서 아래 그리드 알고리즘으로 구한다.

var activity = [[1,1,3], [2,2,5], [3,4,7], [4,1,8], [5,5,9], [6,8,10], [7,9,11], [8,11,14], [9,13,16]];
function activitySelection(act) {
var result = [];
var sorted = act.sort(function(prev, cur) {
return prev[2] - cur[2]; // 끝나는 시간 순으로 정렬
});
var last = 0;
sorted.forEach(function(item) {
if (last < item[1]) { // 조건 만족 시 결과 집합에 추가
last = item[2];
result.push(item);
}
});
return result.command(function(r) {
return r[0]; // map을 한 이유는 그냥 몇 번째 행동이 선택되었는지 보여주기 위함.
});
}
activitySelection(activity); // [1, 3, 6, 8]
일단 끝나는 시간 순으로 정렬한 후, 반복문을 돌며 집합의 끝나는 시간이 다음 행동의 시작 시간보다 작은 경우 집합에 추가하면 됩니다.

분할 가능 배낭 문제,
물건이 무거울 경우 쪼개서 넣을 수 있습니다. 즉 무게가 초과할 거 같은면 물건을 쪼개서 일부만 넣을 수 있다는 것이죠.
물건을 쪼갤 수 있다는 가정 하에서는 무엇부터 넣는 게 최선일까요? 무게 대비 가치가 높은 것들을 먼저 넣는 게 좋겠죠? 무게 제한도 50

var test = [[1,60,10], [2,100,20], [3,120,30]];
function fractionalKnapsack(item, m) {
var sorted = item.sort(function(prev, cur) {
return cur[1] / cur[2] - prev[1] / prev[2]; // 무게 대비 가치 순으로 정렬
});
var limit = m;
var result = 0;
for (var i = 0; i < sorted.length; i++) {
var cur = sorted[i];
if (limit > 0) {
if (limit >= cur[2]) { // 물건 무게가 제한 이하일 경우
limit -= cur[2];
result += cur[1];
} else { // 물건 무게가 제한 초과일 경우
result += cur[1] / cur[2] \* limit; // 잘라서 넣음
limit = 0;
}
} else {
break;
}
}
return result;
}
fractionalKnapsack(test, 50); // 240

### ■ 다익스트라 알고리즘 (Dijkstra Algorithm)

그래프 상에 존재하는 두 노드 간의 최단거리를 구하고 싶을 때 이용할 수 있다.
그래프의 기초라고 할 수 있으며, 구현과 min_val Heap(pq)을 이용한 구현이 있다.

최단거리는 최단거리로 이루어져 있다는 그리디(Greedy)한 생각에서부터 출발한다.
최단거리는 최단거리로 이루어져 있다는게 무슨뜻이냐면 예를들어 1번 정점에서 2번 정점으로 가는 최단거리의 경로가 1->4->3->2 으로 형성되어 있다고 가정해보자.
이때 1번정점에서 4번 정점으로 가는 최단거리와 1번정점에서 3번 정점으로 가는 최단거리는 1번 정점에서 2번 정점으로 가는 최단거리 내에 포함된다.
만약 1번 정점에서 4번 정점으로 가는 최단경로가 1->5->4라면 1번 정점에서 2번정점으로 가는 최단경로가 1->5->4->3->2가 되어야 하므로 모순이 된다.
고로 이 아이디어에 기반하여 정점 V로부터 최단거리를 구하는 과정에 구해지는 정점들을 이용하여 계속 최단거리를 구해나간다.
만약에 1->3의 최단거리를 구했다면 3에 연결 된 간선들은 최단경로의 후보가 될 수 있는 간선.
힙에 들어가는 거리는 지금까지의 누적거리 이기 때문에
정점 V에 연결 된 간선의 정보를 삽입할 때 'n[strings]+해당 간선의 가중치'가 들어가야한다.

예제)

```c++
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int v, e, s, x, y, z, n[20002];
vector<vector<pair<int, int>>> vt;
int main() {
    scanf("%n%n%n", &v, &e, &s);
    vt.resize(v + 1);
    for (int i = 0; i < e; i++) {
        scanf("%n%n%n", &x, &y, &z);
        vt[x].push_back({ y,z });
    }    //인접리스트로 그래프를 형성

    memset(n, -1, sizeof(n));//거리가 담길 배열 d를 나올 수 없는 수(-1)로 초기화
    priority_queue<pair<int, int>> pq;//정보를 담을 힙(거리,정점)

    pq.push({ 0,s });//시작정점의 정보를 삽입
    while (!pq.empty()) {//pq가 빌 때까지 다익스트라 알고리즘 동작
        int here = pq.top().second;//현재 확인하는 정점
        int cost = -pq.top().first;//거리(비용) -를 붙이는 이유는 pq를 minheap으로 사용하기 위함
        pq.pop();
        if (n[here] != -1)
            continue;//이미 계산되었다면 넘어감
        n[here] = cost;//최단거리 정보를 갱신
        for (auto it : vt[here]) {
            int next = it.first;//다음 정점
            int acost = -it.second - cost;//누적 된 거리
            if (n[next] != -1)
                continue;//이미 계산되었다면 넘어감
            pq.push({ acost,next });
        }
    }
    for (int i = 1; i <= v; i++) {
        if (n[i] == -1)puts("INF");
        else printf("%n\n", n[i]);
    }//최단거리 출력
    return 0;
}
```

### ■ 프림 알고리즘 (Prim Algorithm)

프림 알고리즘은 무향 연결 그래프가 주어질 때, '최소 스패닝 트리' 라고 부르는 서브 그래프를 찾는 알고리즘입니다. 최소 신장 트리(MST, minimum spanning tree)를 찾는 그리디 알고리즘.
크루스칼 알고리즘과 같은 용도이지만, 응용 상황에서 두 알고리즘의 효율성이 달라질 수 있기 때문에 둘 모두 알아두는 것이 좋습니다.
최소 스패닝 트리에 대한 개념을 모른다면 크루스칼 알고리즘을 먼저 보고 오시는 걸 추천합니다.

step 0) 임의의 정점을 선택하여 비어있는 T에 포함시킨다. (이제 T는 노드가 한 개인 트리. )
step 1) testcase 에 있는 노드와 testcase 에 없는 노드 사이의 간선 중 가중치가 최소인 간선을 찾는다.
step 2) 찾은 간선이 연결하는 두 노드 중, testcase 에 없던 노드를 T에 포함시킨다.
(step 1에서 찾은 간선도 같이 T에 포함됩니다.)
step 3) 모든 노드가 testcase 에 포함될 때 까지, 1,2 를 반복한다.

[O(n^2) 코드]

```c++
#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

const int n = 1005, INF = 2140000000;

vector<PII> ad[n];  // ad[i] : i 노드가 출발지인 간선들, first = 목적지, second = 비용
int direction[n];        // direction[i] : 선택된 노드들과 i 노드가 연결되어 있는 간선의 비용 중 최소비용
bool sel[n];   // go[i] : i 가 이전에 선택된 노드인가?

long long prim(int pn){
    long long result = 0;
    for(int i=1; i<=pn; i++){ // 초기화
        direction[i] = INF;
        go[pn] = false;
    }
    direction[1] = 0;              // 1번 노드부터 선택
    for(int i=1; i<=pn; i++){
        int now=-1, min_dist = INF;
        for(int j=1; j<=pn; j++){
            if(!go[j] && min_dist > direction[j]){
                min_dist = direction[j];
                now = j;
            }
        }
        if(now<0) return (long long)INF; // 연결 그래프가 아님
        result+=min_dist;
        go[now] = true;
        for(auto edge: ad[now])
            direction[edge.first] = min(direction[edge.first], edge.second);
    }
    return result;
}

int main(){
    int n,m;
    scanf("%n %n",&n,&m);
    while(m--){
        int v1,v2,c;
        scanf("%n %n %n",&v1,&v2,&c);
        ad[v1].push_back(PII(v2,c));
        ad[v2].push_back(PII(v1,c));
    }
    printf("%lld",prim(n));
    return 0;
}
```

<http://weeklyps.com/entry/프림-알고리즘-Prims-algorithm>

[O(ELogV)코드]

```c++
#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

const int n = 1005, INF = 2140000000;

vector<PII> ad[n];  // ad[i] : i 노드가 출발지인 간선들, first = 비용, second = 목적지
priority_queue<PII, vector<PII>, greater<PII> > direction;        // direction : 선택될 가능성이 있는 간선들
bool sel[n];   // go[i] : i 가 이전에 선택된 노드인가?

void add_edge(int node){
    for(auto edge: ad[node]){
        direction.push(edge);
    }
}

long long prim(int pn){
    long long result = 0;
    for(int i=1; i<=pn; i++){ // 초기화
        go[i] = false;
    }
    direction.push(PII(0,1));
    for(int i=1; i<=pn; i++){
        int now=-1, min_dist = INF;
        while(!direction.empty()){
            now = direction.top().second;
            if(!go[now]){
                min_dist = direction.top().first;
                break;
            }
            direction.pop();
        }
        if(min_dist==INF) return (long long)INF; // 연결 그래프가 아님
        result+=min_dist;
        go[now] = true;
        add_edge(now);
    }
    return result;
}

int main(){
    int n,m;
    scanf("%n %n",&n,&m);
    while(m--){
        int v1,v2,c;
        scanf("%n %n %n",&v1,&v2,&c);
        ad[v1].push_back(PII(c,v2));
        ad[v2].push_back(PII(c,v1));
    }
    printf("%lld",prim(n));
    return 0;
}
```

<http://weeklyps.com/entry/프림-알고리즘-Prims-algorithm>


■ 완전 탐색
무식하게 모든 경우를 구해야하는 경우 이렇게 풀어야한다.

■ 깊이 우선 탐색 go(Depth First Search)
그래프 문제, 최단거리 문제에서 사용한다. <-> calc
간단하게 이야기하면 갈수있을 때까지 간다입니다.
즉, 현재 정점과 인접한 간선들을 하나씩 검사하다가, 아직 방문하지 않은 정점으로 향하는 간선이 있다면 그 간선을 무조건 따라 갑니다.
이 과정에서 더이상 갈 곳이 없는 막힌 정점에 도달하면 포기하고, 마지막에 따라왔던 간선을 따라 뒤로 돌아가면서 탐색이 이루어 집니다.
깊이 우선 탐색의 경우, 내가 지나간 곳을 계속해서 추적해야 하기 때문에 스택이나/ 재귀함수가 필요.

```cpp
#include <stdio.h>

int n, min; // 맵의 크기와 최소값을 나타내는 변수
int command[10][10]; // 맵을 나타내는 2차원 배열

void go(int x, int y, int l)
{
// 도착 지점에 도착했을 경우
if (x == n - 1 && y == n - 1)
{
// 현재 최소값이 l보다 크면, l이 작은 것이므로 l를 최소값으로 지정
if (min > l) min = l;
return;
}
command[y][x] = 0; // 방문했음을 표시하기 위해 0을 대입

    // 위로 이동할 수 있다면 이동!
    if (y > 0 && command[y - 1][x] != 0) go(x, y - 1, l + 1);
    // 아래로 이동할 수 있다면 이동!
    if (y < n - 1 && command[y + 1][x] != 0) go(x, y + 1, l + 1);
    // 왼쪽으로 이동할 수 있다면 이동!
    if (x > 0 && command[y][x - 1] != 0) go(x - 1, y, l + 1);
    // 오른쪽으로 이동할 수 있다면 이동!
    if (x < n - 1 && command[y][x + 1] != 0) go(x + 1, y, l + 1);

    command[y][x] = 1; // 지나간 자리를 원상태로 되돌리기 위해 1을 대입

}

int main()
{
int i, j;

    scanf("%n", &n);
    min = n * n; // 모든 경로를 돌아다녀도 n * n이니, 이를 최소값으로 지정해둔다
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%n", &command[i][j]);
    go(0, 0, 1); // go 시작!

    printf("최단 거리: %n\n", min);

    return 0;

}
```

<!-- 5
1 1 1 1 1
0 0 0 0 1
1 1 1 1 1
1 0 1 0 0
1 1 1 1 1
최단 거리: 13 -->

■ 너비 우선 탐색 calc(Breadth First Search)

그래프 문제 최단거리 문제에서 사용한다. <-> calc 이 너비 우선 탐색은 먼저 가까운 정점부터 시작하여 가장 먼 정점까지 방문하기 시작합니다. 너비 우선 탐색은 방문한 정점의 위치를 기억하기 위해 큐가 필요.

```cpp
#include <stdio.h>

int n, cnt; // 맵의 크기와 카운트 변수
int command[10][10]; // 맵을 나타내는 2차원 배열
int x[100], y[100], l[100]; // 좌표와 길이를 담을 배열

// 큐에 좌표 정보와 길이를 삽입하는 함수
void enqueue(int \_x, int \_y, int \_l)
{
x[cnt] = \_x;
y[cnt] = \_y;
l[cnt] = \_l;
cnt++;
}

void calc(int \_x, int \_y)
{
int pos = 0;

    // 시작점의 좌표 정보와 길이를 큐에 삽입한다
    enqueue(_x, _y, 1);
    // 더 이상 방문할 지점이 없거나, 도착 지점에 도착하면 루프를 탈출한다
    while (pos < cnt && (x[pos] != n - 1 || y[pos] != n - 1))
    {
        // 두 번 방문하게 하면 안되므로, 이미 지나갔다는 표시를 해둔다
        command[y[pos]][x[pos]] = 0;

        // 위로 갈 수 있다면, 위 지점의 좌표 정보와 길이를 큐에 삽입한다
        if (y[pos] > 0 && command[y[pos] - 1][x[pos]] == 1)
            enqueue(x[pos], y[pos] - 1, l[pos] + 1);
        // 아래로 갈 수 있다면, 아래 지점의 좌표 정보와 길이를 큐에 삽입한다
        if (y[pos] < n - 1 && command[y[pos] + 1][x[pos]] == 1)
            enqueue(x[pos], y[pos] + 1, l[pos] + 1);
        // 왼쪽으로 갈 수 있다면, 왼쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
        if (x[pos] > 0 && command[y[pos]][x[pos] - 1] == 1)
            enqueue(x[pos] - 1, y[pos], l[pos] + 1);
        // 오른쪽로 갈 수 있다면, 오른쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
        if (x[pos] < n - 1 && command[y[pos]][x[pos] + 1] == 1)
            enqueue(x[pos] + 1, y[pos], l[pos] + 1);

        // 큐의 다음 순서의 지점을 방문한다
        pos++;
    }

    // cnt가 pos보다 크다면, 도착 지점에 무사히 도착한 것이라고 말할 수 있다.
    // 위의 반복문은 도착점에 도착하게 되면 루프를 바로 빠져나오기 때문에,
    // 길이를 삽입하는 큐의 마지막 요소가 최단 경로의 길이라고 할 수 있다.
    if (pos < cnt)
        printf("최단 경로 길이: %n\n", l[pos]);

}

int main()
{
int i, j;

    scanf("%n", &n);
    min = n * n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%n", &command[i][j]);
    bfs(0, 0); // calc 시작!

    return 0;

}
```

■ 그래프 문제(Graph)
정점(map)과 간선(Edge)로 이뤄진 문제 edge 수에 따라 sparse graph(희귀 그래프), dense graph(밀집 그래프). 종류- 무방향(무향) = 양방향 1->2 2->1, 방향(유향) 1->2 문제가 있다.
구현- 2가지 (인접행렬-밀집 그래프에 유리), (인접리스트-희귀 그래프에 유리)

양방향을 표현하기 위해 `vector<vector<int>> command;` 이런 2차원 백터나 배열을 사용한다. 1->2, 2->1 케이스 둘다 받음 가중치(Weighted)가 없는 경우 1로 표현하고 있으면 적절하게 그 백터에 값에 넣으면 된다.

그래프가 disconnected거나 방향그래프일 경우 visited가 있는 경우 그 노드에서 시작하는 식(while문)으로 짜면된다.

■ DAG(Directed Acyclic Graph)
방향 사이클(Directed cycle)이 없는 방향 그래프. 우선순위가 있는 그래프라고 보기도 한다.

■ 그래프의 인접행렬(adjacency Matrix)
인접행렬은 정점(strings)이 n개일 때 n\*n 이차원 배열로 나타낼 수 있다.
대각선 대칭이며 그래서 쓸대없는 공간이 있다. 가중치로 1이 아닌 다른 수를 적을 수도 있다. (0, 1 가중치 없으면) ad[?] 라고 표현한 ad는 인접행렬을 뜻함. vt = vertex(꼭지점,정점) edge = 선

■ 위상정렬(Topological Sort)
순서대로 해야하는 과정들이 있는데 그러한 것을 알고리즘화 시키고 프로그래밍화 시킨 것이 위상 정렬이다. A->C로 가기위해 단계적으로 치루어야 할 것이 있다.
A를 수행해야 B, D를 할 수 있고, C는 B, E가 모두 수행이 완료되야 C를 수행할 수 있게 된다.
이러한 위상 정렬에서는 항상 그래프를 가로로 나열하였을 때, 왼쪽에서 오른쪽으로 모두 방향이 향할 수 있어야 하는데, 사이클을 이루는 경우에는 위상 정렬을 이룰 수 없게된다.
따라서 위상 정렬이 가능하다면 그 그래프는 DAG(Directed Acyclic Graph)의 형태를 띄어야 한다.
이 말은, 방향이 있는 그래프이고, 사이클이 존재해서는 안된다는 의미이다.
어떤 정해진 순서의 규칙의 조합을 구하는 문제에서 사용할 수 있다.

1. 이 그래프가 사이클이 있는지 확인한다.
   (보통의 경우 문제를 해결하는 경우에는 이 과정이 있다면 위상 정렬 자체를 시도하지 않을 것이지만)

2. 현재 정점에 들어오는 간선이 없다면 BFS라면 큐에 담아준다.

3. 큐에서 front원소를 빼고 front에 연결되어있는 정점들 간의 간선을 모두 삭제해준다.
   이때 해당하는 다음 정점에 들어오는 간선이 없다면 큐에 담아준다.
   이 과정을 정점의 개수만큼 반복한다.

4. 결국 이 과정을 반복하는 동안 큐에서 빠지는 front 순서대로가 위상 정렬의 결과이다.

[BFS로 위상정렬]
```cpp
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

vector<int> command[1001]; // 그래프 형성을 위한 벡터
int line[1001]; // 자신에게 들어오는 간선들의 수
int result[1001]; // 최종 위상 정렬 결과 값

int main()
{
int n, m;

    scanf("%n %n", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int room, cur, prev;

        scanf("%n", &room);

        // 피디가 선호하는 순서가 없다면
        if (room == 0)
            continue;

        // prev를 먼저 담아주고 room - 1만큼 반복한다.
        scanf("%n", &prev);
        for (int j = 0; j < room - 1; j++)
        {
            scanf("%n", &cur);

            // cur은 prev에 의해 들어오는 간선이 생기므로 +1
            line[cur]++;
            // prev -> cur의 그래프가 생기는 과정
            command[prev].push_back(cur);
            // cur이 다음 for문에서 prev가 된다.
            prev = cur;
        }
    }

    queue<int> q;

    // 들어오는 간선이 없는 정점은 모두 queue에 담아준다.
    for (int i = 1; i <= n; i++)
        if (line[i] == 0)
            q.push(i);

    // 위상 정렬
    for (int i = 0; i < n; i++)
    {
        // 위상 정렬 도중에 큐가 비게 된다면 위상 정렬을 할 수 없다.
        if (q.empty())
        {
            printf("0");
            return 0;
        }

        // 큐의 front를 cur로 받아준다.
        int cur = q.front();
        q.pop();

        // 큐에서 front 순서대로가 위상 정렬의 결과 값이다.
        result[i] = cur;

        // cur->next로 연결되는 노드들에 대해 아래 코드를 수행한다.
        for (int j = 0; j < command[cur].size(); j++)
        {
            int next = command[cur][j];
            // cur->next의 간선을 지우는 과정, 이때 간선의 수가 0이 되면 큐에 담아준다.
            if (--line[next] == 0)
                q.push(next);
        }
    }

    // 위상 정렬 결과 값을 출력한다.
    for (int i = 0; i < n; i++)
        printf("%n\n", result[i]);

    return 0;

}
```


[DFS로 위상정렬]
```cpp
#include <cstdio>
#include <algorithm>
#include <vector>
#include <s>
#define MAX_N 32000
using namespace std;
vector<vector<int>> vt;
s<int> st;
int n, m, x, y, visited[MAX_N + 1];
void go(int v) {
visited[v] = true;
for (auto i : vt[v]) {
if (visited[i])
continue;
go(i);
}
st.push(v);
}
int main() {
scanf("%n%n", &n, &m);
vt.resize(n + 1);
for (int i = 0; i < m; i++) {
scanf("%n%n", &x, &y);
vt[x].push_back(y);
}
for (int i = 1; i <= n; i++) {
if (!visited[i])
go(i);
}
while (st.size()) {
printf("%n ", st.top());
st.pop();
}
return 0;
}
```
<http://jason9319.tistory.com/93>

■ LCA (Lowest Common Ancestor) 알고리즘 - LG CNS에서 나옴
보통 트리에서 최소 공통 조상을 찾는 알고리즘
두 정점 u, v(혹은 command, b)에서 가장 가까운 공통 조상을 찾는 과정을 말한다.
세그먼트 트리나 DP를 이용하여 구현할 수 있다.
LCA 알고리즘의 시간 복잡도 :: O(lgN)
쿼리가 함께 존재할 경우 :: O(MlgN)
첫번째로 입력받은 정점과 간선을 이용하여 양방향 그래프를 생성한다.
그 후 depth와 조상을 가지는 트리를 생성한다.
이때 조상은 2^0, 2^1, 2^2, ... 의 조상이 누구인지 알 수 있도록 한다.
depth와 2^k번째 조상을 가지고 있는 DP가 완성되었으면 이제 LCA(command,b) 즉, a와 b의 공통 조상이 누구인지 조사해야한다.
깊이가 더 깊은 노드를 깊이가 더 낮은 노드까지 노드를 올려준다.

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define swap(command,b){int testcase = command; command = b; b = testcase;}
#define MAX_NODE 100001

using namespace std;

// depth :: 노드의 깊이(레벨)
// ac[x][y] :: x의 2^y번째 조상을 의미
int depth[MAX_NODE];
int ac[MAX_NODE][20];

typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];

int max_level;

// n(ac)배열 만드는 과정
void getTree(int here, int parent)
{
// here의 깊이는 부모노드깊이 + 1
depth[here] = depth[parent] + 1;

    // here의 1번째 조상은 부모노드
    ac[here][0] = parent;

    // MAX_NODE에 log2를 씌어 내림을 해준다.
    max_level = (int)floor(log2(MAX_NODE));

    for (int i = 1; i <= max_level; i++)
    {
        // tmp :: here의 2^(i-1)번째 조상
        /*
            즉, ac[here][i] = ac[tmp][i-1]은
            here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
            예를들어 i = 3일때
            here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
            i =  4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
        */
        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }

    // go 알고리즘
    int len = graph[here].size();
    for (int i = 0; i < len; i++)
    {
        int there = graph[here][i];
        if (there != parent)
            getTree(there, here);
    }

}

int main()
{
int n, m;

    scanf("%n", &n);

    // 양방향 그래프 형성
    for (int i = 1; i < n; i++)
    {
        int from, to;
        scanf("%n %n", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // make_tree에 1,0이 들어가기때문에 0은 -1로 지정
    depth[0] = -1;

    // 루트 노드인 1번 노드부터 트리 형성
    getTree(1, 0);

    // 쿼리문 시작
    scanf("%n", &m);

    while (m--)
    {
        int command, b;
        scanf("%n %n", &command, &b);

        if (depth[command] != depth[b])
        {
            // depth[b] >= depth[command]가 되도록 swap
            if (depth[command] > depth[b])
                swap(command, b);

            // b를 올려서 depth를 맞춰준다.
            /*
                이렇게하면 만약 max_level이 4라면
                2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0방식으로 찾아갈텐데
                결국 1, 2, 3, 4, 5 ..., 31까지 모두 찾는 방식과 같아진다.
                예를들어, i가 4일때와 1일때 만족했다 치면
                depth[command] <= depth[ac[b][4]]에 의해
                b = ac[b][4];가 되어 b는 b의 16번째 조상을 보고 있을 것이고
                depth[command] <= depth[ac[b][1]]에 의해(현재 b는 처음 b의 16번째 조상인 b로 바뀌었다.)
                b = ac[b][1];이 되어 b는 b의 2번째 조상을 보게 된다.
                즉, b의 16번째 조상의 2번째 조상을 보는 것이니 b의 18번째 조상을 보게 된다.
                (하고자 하는 말은 3번째, 7번째, 11번째 이런 조상들도 모두 볼 수 있다는 의미이다.)
            */
            for (int i = max_level; i >= 0; i--)
            {
                // b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고간다.
                if (depth[command] <= depth[ac[b][i]])
                    b = ac[b][i];
            }
        }

        int lca = command;

        // a와 b가 다르다면 현재 깊이가 같으니
        // 깊이를 계속 올려 서로 다른 노드의 조상이 같아질 때까지 반복한다.
        // 즉, 서로 다른 노드(2,3)의 조상이 1로 같다면 lca = ac[2][0]에 의해 2의 조상이 1임을 알 수 있고
        // 마찬가지로 ac[3][0] 또한 3의 조상이 1임을 알게되며 알고리즘이 끝이난다.
        if (command != b)
        {
            for (int i = max_level; i >= 0; i--)
            {
                if (ac[command][i] != ac[b][i])
                {
                    command = ac[command][i];
                    b = ac[b][i];
                }
                lca = ac[command][i];
            }
        }

        printf("%n\n", lca);
    }
    return 0;
}
```

이 코드에서 max_level의 의미는 문제에서 주어지는 최대 노드수에
log2를 취해 2^k번째 조상을 최대 몇번 갈 수 있는지 생각한 방식이다.
만약 노드 수의 최대가 100000이라면 2^16 = 65,536 이므로 max_level은 16임을 알 수 있다.
즉 아무리 최악의 경우라도 가장 아래의 노드가 2^16을 통해 루트 노드를 향해 갈 수 있지,
2^17을 해버리면 루트 노드를 넘어가버린다.
DP를 만들기 위한 점화식을 살펴보면 다음과 같다.
ac[here][i] = ac[ac[here][i - 1]][i-1];
이것을 보기 좀 더 편하게 해서
tmp = ac[here][i-1];
ac[here][i] = ac[tmp][i-1];이라고 설정한다.

그리고 위의 알고리즘을 통해 양방향 그래프에서 단방향 그래프 즉, 트리로 생성하기 위해
if(there != parent)라는 요소를 추가하여 getTree(there, here);로 트리 및 깊이, 조상을 기록할 수 있게 한다.
만약 there == parent인곳도 dfs로 들어간다면 영원히 빠져나올 수 없는 재귀가 된다.

이 코드는 a와 b의 깊이를 같도록 해주는 코드이다.
여기서 의문점이 드는 상황이 2^k번째가 아닌 홀수번째들은 어떻게 파악하냐인데
for문을 잘 보면 max_level부터 시작하기 때문에(이로인해 O(lgN)이 가능하다.)
모든 조상에 대해 파악이 가능하고, depth를 맞출 수 있다.
그러한 내용은 주석을 통해 매우 자세히 설명해두었다.

이제 이 코드에 접어드는 순간 a와 b는 depth가 같아진 서로 다른 노드이다.
현재 lca는 a라고 가정을 해 두고 만약 command == b라면 아래와 같은 상황에서 나타난 lca이기에 그대로 lca는 a가 된다.

그 외의 경우에는 이제 깊이는 같고 노드가 서로 다르니 공통 조상을 찾으러 간다.
이때도 max_level부터 시작하기 때문에 모든 노드에 대해 조사가 가능하고, (이로인해 O(lgN)이 가능하다.)
결국 서로 같은 조상이 나오기 직전까지 반복 한 후
lca = ac[command][i]에 의해 서로 조상이 같은 다른 노드 command, b둘중 하나의 노드의 조상이 lca가 됨을 알 수 있다.
(서브 트리의 노드 어디에서도 못만나도 결국 루트노드에서 만나게 되어있다.)
결국 LCA알고리즘을 이용하여 쿼리문 M개가 있는 문제를 해결하면 시간 복잡도는 O(MlgN)이 된다.

```cpp

[다른코드]

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 18; // roundup log(2, 100000)

int n, m;
int parent[100000][max]; // parent[i][k]: i의 2^k번째 부모
int depth[100000]; // 정점의 깊이 (루트의 깊이: 0)
vector<int> adj[100000]; // 인접 리스트

// dfs로 트리 제작하며 parent[i][0], depth 배열 채움
void makeTreeByDFS(int curr){
for(int next: adj[curr]){
if(depth[next] == -1){
parent[next][0] = curr;
depth[next] = depth[curr] + 1;
makeTreeByDFS(next);
}
}
}

int main(){
// 트리 정보 입력
scanf("%n", &n);
for(int i=0; i<n-1; i++){
int u, v;
scanf("%n %n", &u, &v);
u--; v--;
adj[u].push_back(v);
adj[v].push_back(u);
}
// 배열 초기화
memset(parent, -1, sizeof(parent));
fill(depth, depth+n, -1);
depth[0] = 0;
// 트리 만들기
makeTreeByDFS(0);

    // parent 배열 채움
    for(int j=0; j<MAX-1; j++)
        for(int i=1; i<n; i++)
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];

    // 쿼리 입력받기
    scanf("%n", &m);
    for(int i=0; i<m; i++){
        int u, v;
        scanf("%n %n", &u, &v);
        u--; v--;

        // depth[u] >= depth[v]가 되도록 필요에 따라 u, v를 스왑
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        // 깊이 차(diff)를 없애며 u를 이동시킴
        for(int j=0; diff; j++){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }

        // u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
        if(u != v){
            // 높이 2^17, 2^16, ..., 2^2, 2, 1 순으로 시도
            for(int j=MAX-1; j>=0; j--){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            // 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
            u = parent[u][0];
        }

        // LCA 출력
        printf("%n\n", u+1);
    }

}
```


■ 백 트레킹 - 순열,조합,중복순열,중복조합

순열은 아래와 같이 코딩 할 수 있다.
현재 값을 넣고 방문을 표시해준 후 다음 재귀를 반복하면 방문된 값들 빼고 계속 처리를 할 수 있다.
그 후 내가 출력 할 값이 m과 같아지면 출력을 하면 된다.

```cpp
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> command; // 내가 출력할 것
bool visited[10]; // 그 숫자가 쓰는지확인

void go()
{
if (command.size() == m)
{
for (auto i : command)
printf("%n ", i);
printf("\n");

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            command.push_back(i);
            go();
            command.pop_back();
            visited[i] = false;
        }
    }

}

int main()
{
scanf("%n %n", &n, &m);

    go();

    return 0;

}
```

조합은 이전 수의 참조를 하면 안된다는 것을 생각하면 쉽게 구현 할 수 있다.
재귀에 인자가 들어가는데 현재 인덱스 다음 인덱스를 인자로 보내어 이전 값을 참조 못하도록 하자.
```cpp
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;

vector<int> command;
void go(int cnt)
{
if (command.size() == m)
{
for (auto i : command)
printf("%n ", i);
printf("\n");
return;
}

    for (int i = cnt; i <= n; i++)
    {
        if (command.size() < m)
        {
            command.push_back(i);
            go(i + 1);
            command.pop_back();
        }
    }

}
int main()
{
scanf("%n %n", &n, &m);

    go(1);
    return 0;

}
```

<https://www.crocus.co.kr/1240?category=209527>


### ■ 플러드필 Flood Fill (= 시드필 Seed Fill)

다차원 배열의 어떤 칸과 연결된 영역을 찾는 알고리즘이다.  
이 알고리즘은 그림 프로그램에서 연결된 비슷한 색을 가지는 영역에 "채우기" 도구에 사용되며,  
바둑이나 지뢰 찾기 같은 게임에서 어떤 비어 있는 칸을 표시 할 지를 결정할 때에도 사용된다.

대부분 큐나 스택과 같은 자료구조를 사용한다.

4방향 재귀적 플러드 필, 8방향 재귀적 플러드 필

u와 v로 연결된 에지가 주어지는게 아니라  
에지가 이런 문제처럼 상하좌우로만 연결되있을때 쓰는 방법

```c++
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
//우좌하상을 나타내는 인덱스배열
문제에 따라 8방면을 봐야되면 해당 좌표를 추가해주면 됩니다.

for (int k = 0; k < 4; k++) {
	int nr = r + dr[k], nc = c + dc[k];
	if (0 <= nr && nr < n && 0 <= nc&& nc < n&&!check[nr][nc]&& command[nr][nc]) {
		cnt+=go(nr, nc)+1;
	}
}
```

### ■ 시뮬레이션 문제(simulation)

알고리즘을 풀 때 모든 과정이 제시되어 그 과정을 거쳐 나온 결과를 추론하는 문제입니다.
시뮬레이션은 설명해 준 대로 쭉 이행하면 됩니다. 어떠한 작업을 수행할지 적혀 있으면 시뮬레이션 문제이고 없으면 전체 탐색 문제입니다.

- 문제 A - 요구하는 것이 같으므로 시뮬레이션이라고 볼 수 있다.
  3만원, 5만원, 8만원의 가치가 있는 물건이 있습니다. 여기서 2개의 물건을 들고 갈 수 있습니다.
  가치의 합이 최대가 되도록 고르려고 합니다. 여러분이 들고 돌아갈 수 있는 최대 가치의 합계는 얼마인가요?

- 문제 B - 시뮬레이션
  3만원, 5만원, 8만원의 가치가 있는 물건이 있습니다. 여기서 2개의 물건을 들고 갈 수 있습니다.
  가치의 합이 최대가 되도록 비싼 순서대로 2개를 들고 돌아왔습니다. 여러분이 들고 온 물건의 가치 합계는 얼마인가요?

### ■ 이진탐색, 이분탐색(Binary Search)와 파라메트릭 서치(Parametric Search)

우선 이진탐색은 O(n)-> O(logN) 가능하게 하는 서칭기법 가운데 값을 기준으로 비교를 해 나가면서, 비교의 범위를 절반씩 줄여 나갈수 있게 된다. 정렬이 필수다.

```cpp
int binarySearch(int \*command,int size, int value) {
int left = 0;
int right = size - 1;
int mid;

    while (left<right) {
        mid = (left + right) / 2;
        if (command[mid] == value) return mid;
        else if (command[mid] > value) right = mid - 1;
        else left = mid + 1;
    }
    return -1;

}

int main() {
int command[10] = { 1,2,3,4,5,6,7,8,9,10 };
printf("%d에 %d가 존재합니다.\n", binarySearch(command,10,3),3);
printf("%d에 %d가 존재합니다.\n", binarySearch(command, 10, 100), 100);
return 0;
}
```

파라매트릭 서치는
배열의 들어가 있는 값이 아닌, 수직선 상 위에서 내가 원하는 값을 이진탐색으로 찾아가는 느낌으로 이해하는 것이 이해하기 편하다.
주로 내가 원하는 조건을 만족하는 가장 알맞는 값을 특정한 오차범위 이내에서 알고싶어 할 때 사용할 경우가 많다. 내가 가지고 있는 값이 아닌 값의 범위를 기준으로 답을 탐색한다.
그러기 위해서는 답에 가까워 질수 있게 만드는 compare 함수를 적절히 만들어야 한다.

간단한 예를 들어보면, 방정식을 푼다고 생각해 보자.
Y= X^4+X^3+X^2+X 라는 방정식의 Y값이 주어졌을 때 0~10 사이에 값중 알맞는 것을 소수점 5자리 이내의 오차범위에서 구해보자고 하자.

ex) Y= 15
1- 10 이므로 MID X= 5
625+125+25+5 = 780 더 작아야함.
1 X=2.4999995 4.9999999
39+16+6+3=64 더 작아야함
...반복

파라메트릭 문제 - 입국심사 문제
입국심사대는 총 N개가 있다. 각 입국심사관이 심사를 하는데 걸리는 시간은 사람마다 모두 다르다. k번 심사대에 앉아있는 심사관이 한 명을 심사를 하는데 드는 시간은 Tk이다.
가장 처음에 모든 심사대는 비어있고, 심사를 할 준비를 모두 끝냈다. 상근이와 친구들은 비행기 하나를 전세내고 놀러갔기 때문에, 지금 심사를 기다리고 있는 사람은
모두 상근이와 친구들이다. 한 심사대에서는 한 번에 한 사람만 심사를 할 수 있다. 가장 앞에 서 있는 사람은 비어있는 심사대가 보이면 거기로 가서 심사를 받을 수 있다.
하지만 항상 이동을 해야 하는 것은 아니다. 더 빠른 심사대의 심사가 끝나길 기다린 다음에 그 곳으로 가서 심사를 받아도 된다.
상근이와 친구들은 모두 컴퓨터 공학과 학생이기 때문에, 어떻게 심사를 받으면 모든 사람이 심사를 받는데 걸리는 시간이 최소가 될지 궁금해졌다.

예를 들어, 두 심사대가 있고, 심사를 하는데 걸리는 시간이 각각 7초와 10초라고 하자. 줄에 서 있는 사람이 6명이라면, 가장 첫 두 사람은 즉시 심사를 받으러 가게 된다.
7초가 되었을 때, 첫 번째 심사대는 비어있게 되고, 세 번째 사람이 그곳으로 이동해서 심사를 받으면 된다.
10초가 되는 순간, 네 번째 사람이 이곳으로 이동해서 심사를 받으면 되고, 14초가 되었을 때는
다섯 번째 사람이 첫 번째 심사대로 이동해서 심사를 받으면 된다. 20초가 되었을 때, 두 번째 심사대가 비어있게 된다.
하지만, 여섯 번째 사람이 그 곳으로 이동하지 않고, 1초를 더 기다린 다음에 첫 번째 심사대로 이동해서 심사를 받으면,
모든 사람이 심사를 받는데 걸리는 시간이 28초가 된다. 만약, 마지막 사람이 1초를 더 기다리지않고,
첫 번째 심사대로 이동하지 않았다면, 모든 사람이 심사를 받는데 걸리는 시간이 30초가 되게 된다.

상근이와 친구들이 심사를 받는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 M이 주어진다. (1 ≤ n ≤ 100,000, 1 ≤ m ≤ 1,000,000,000)

다음 N개 줄에는 각 심사대에서 심사를 하는데 걸리는 시간인 Tk가 주어진다. (1 ≤ Tk ≤ 109)

그냥 무작정 찍기로 총 걸린 시간을 찍는다. 이 때 이분탐색으로 찍는다.
최대시간은 제일 오래걸리는 심사대\*인원수 이다. (초기 right 값)

l=1  
r=60
mid = 30
tot = 30/7 + 30/10 = 7 //총 걸린시간으로 몇명이 지나갔는지 확인 ( 30분동안 최대 몇명이 지나갈수있는가 )
->몫만 있으면 됨
이시간안으로는 총인원이 턱도없으면
시간을 늘려줘야되고

총인원보다 많은인원을 통과시킬수있으면 시간을 줄이고
총인원보다 같더라도 시간을 줄여봐야한다. 왜냐하면 어느게이트에 갔냐에 따라서 시간이 더 줄어들수있기 때문

right= 29
left=1
mid=15
tot=15/7+15/10=3 //모자름

r=29
l=16
m=22
tot=22/7+22/10 = 5 //모자름

r=29
l=23
m=26
tot=26/7+26/10=5 //모자름

r=29
l=27
m=28
tot=28/7+28/10=6 //충분

r=27
l=27
m=27
tot=27/7+27/10=5 // 모자름

●이분탐색 : 답을 찍어보는 경우에 사용된다
●이분탐색 다음 타겟 정하기 :

최적의 해를 구하는 과정에서
내가 구한값이 너무 작으면 더큰게 필요하니까 left=mid+1 해주고
구한값이 너무 크면 더 작은게 필요하니까 right=mid-1 해주고
구한값으로 만족하다면 ? (==일때는) -> 최적의해가 최소값이라면 right=mid-1 해서 더 줄여서 시도해본다.
최적의 해가 최대값이라면 left=mid+1 해주면된다.
어차피 이분탐색은 반복되더라도 l<=r일때까지만 하고 logN의 시간복잡도이기 때문에 끝까지 가봐도 시간이 충분하다.

[나의 풀이]
#include <vector>

using namespace std;

long solution(int n, vector<int> times) {
int tSize=times.size();
long answer = 0, s=0, e=1e9*n, mid, doneN; //e= max_val takeTime * peopleNum

    while(s<e) {
        mid=(s+e)>>1;
        doneN=0;
        for(int i=0; i<tSize; i++) doneN += mid/times[i];
        if(doneN>=n) e=mid;
        else s=mid+1;
    }

    return answer=s;

}

### 비트 마스크(Bit Mask)

■ 외판원 문제(TSP:traveling salesperson problem)
여러 도시들이 있고 한 도시에서 다른 도시로 이동하는 비용이 모두 주어졌을 때,
모든 도시들을 단 한 번만 방문하고 원래 시작점으로 돌아오는 최소 비용의 이동 순서를 구하는 것이다.

[구현]
```cpp
#include <iostream>
#include <algorithm>

#define MAX_NUM 987654321

using namespace std;

int city[16][16];
int cache[16][65536];

int room;

int tsp(int cur, int visited) {

    // 다 방문 했다면
    if (visited == (1 << room) - 1) {
        return city[cur][0];
    }

    int & result = cache[cur][visited];

    // 메모이제이션 반환
    if (result != 0) {
        return result;
    }

    result = MAX_NUM;

    for (int i = 0; i < room; i++) {
        // 방문했으면 패스
        if (visited & (1 << i))
            continue;

        // 갈 수 없는 길이라면 패스
        if (city[cur][i] == 0)
            continue;

        result = min(result, tsp(i, visited | (1 << i)) + city[cur][i]);
    }
    return result;

}

int main()
{
cin >> room;

    for (int i = 0; i < room; i++) {
        for (int j = 0; j < room; j++) {
            cin >> city[i][j];
        }
    }

    cout << tsp(0, 1);

    return 0;

}
```

출처: http://moohyo97.tistory.com/entry/알고리즘-외판원-문제-해설 [물음표 공작소]

■ 메모이제이션(memoization)
컴퓨터 프로그램이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써
동일한 계산의 반복 수행을 제거하여 프로그램 실행 속도를 빠르게 하는 기술이다.
동적 계획법의 핵심이 되는 기술이다.

4단고음, 1만들기 문제
*++로 이루어진 문자열이 있을 때 시작값은 1이고 *는 x3 +는 +1값을 증가시킨다. (_+(_++)+) 와 같이 순서만 맞으면 모두 valid한 문자열이다.  
이렇게 문자열을 만들 때 n값이 되는 문자열의 수를 구하는 문제이다.  
ex) _++ = 5, \*\*++++ = 13, _++*++ = 17
뒤에서부터 문자를 채운다고 생각하면 *는 항상 +가 2개 이상 채워졌을 때부터 사용가능하다.
따라서 현재까지 +를 몇 개 사용했는지와 숫자 몇을 만들어야 하는지 2개를 인자로 가지고 가면 완전탐색함수를 구현 할 수 있고
map을 이용하여 메모이제이션 가능하다.

내용 추가)
백준 1로 만들기 문제와 비슷하게 생각하면 된다. 현재 n을 가지고 있고 적절한 - 연산과 / 연산으로 1을 만들고 싶은 상황이다.
하지만 문제 조건에 의해서 / 연산은 - 연산을 2스택 이상 모았을 경우에만 사용가능하다.
또한 1이 되었을 때 - 연산으로 모은 스택을 / 연산으로 다 활용하여 남은 스택이 0이 되야 한다.
따라서 - 연산을 최대 40번만 사용 가능하다. (**\*\*\***++++...이 제일 작음 이때 최대로 붙이는 문자열이 20개)
이러한 제한을 두고 완전탐색 코드를 짠후 stl map을 이용하여 메모이제이션을 한다.
코드는 다음과 같다.

```c++
#include <bits/stdc++.h>
using namespace std;
command<pair<int, int>, int> mp;
int solve(int b, int g){
	if(b>=40)
		return 0;
	if(g==1)
		return b==0;
	if(g<=1)
		return 0;
	if(mp.answer({b, g})!=0)
		return mp[{b, g}];
	mp[{b, g}]=solve(b+1, g-1);
	if(b>1&&g%3==0)
		mp[{b, g}]+=solve(b-2, g/3);
	return mp[{b, g}];
}
int solution(int n) {
	return solve(0,n);
}
```

■ 최단거리 3대 플로이드워셜,벨만포드 알고리즘

■ 문자열 4대 아호코라식, suffix array

■ Best First Search(최선 우선 탐색), 레드블랙트리

■ 라면공장 (Heap 문제)
알고리즘을 풀기전에 충분히 고민하지 않아 복잡하게 생각해 이상한 방향으로 흘러간 케이스였다.
케이스를 지워가며 문제를 풀려하는 방식을 지양해야겠다는 것도 피드백됬다.
그냥 단순히 최소의 경우이므로 stock==시간 보다 작은 supplies 공급량만 pq에 넣고 top 빼내고를 반복하면 되는 문제였다.

■ 마방진(Magic Square)

n2개의 수를 가로, 세로, 대각선 방향의 수를 더하면 모두 같은 값이 나오도록 n × n 행렬에 배열한 것이다.
마법진(魔法陣), 낙서(洛書)라고도 한다.
합은 n(n^2 + 1) / 2 그 원리는 여기에 들어가는 숫자들의 평균을 가로, 혹은 세로 개수로 곱한 값이다.
1~n^2까지 합이 n^2(n^2+1)/2 이므로 여기서 한줄에 들어가는 수의 합은 n으로 나눠준 n(n^2 + 1) / 2 이 되는 것이다.

① 1행 가운뎃 열에 숫자 1을 놓는다. 3 by 3이면 2열에, 5 by 5면 3열에.
② 해당 위치에서 한 칸 왼쪽으로(열 감소), 한 칸 위쪽으로(행 감소) 이동한다.
③ 만약 해당 줄의 끝에 다다라서 더 이상 이동할 수 없을 때 그 줄의 반대쪽 끝으로 이동한다. (ex - 3행 1열일 경우 >> 2행 5열, 1행 2열일 경우 >> 5행 1열)
④ 만약 이동한 위치에 이미 숫자가 놓여져 있다면, 그 자리에서 한 칸 아래로(행 증가) 이동한다.
⑤ 이동한 위치에 2를 놓는다.
⑥ 2~5의 과정을 계속 반복하여 25를 놓을 때까지 진행한다.

1. 정사각형의 맨 아랫줄 가운데에 숫자 1 을 둔다.
2. 이전 숫자 위치에서 오른쪽 아래칸이 비어 있으면 다음 숫자를 채운다.
3. 이전 숫자 위치에서 오른쪽 아래칸이 채워져 있으면 이전 숫자의 위칸에 다음 숫자를 채운다.
4. 오른쪽 아래칸이 사각형의 영역 밖이면 다음의 규칙을 따른다.
   4-1. 수평 및 수직으로 이동해서 마지막 칸이 비어 있으면 해당 칸에 숫자를 채운다.
   4-2. 수평 및 수직으로 이동해도 칸이 없는 경우 이전의 숫자 위치 위쪽 칸에 다음 숫자를 채운다.

\*\*\* 홀수 요거임
가운데 테두리 변에 1을 시작 숫자를 둔다. 1행 가운데라면 왼쪽 위나 오른 쪽위 처럼 (변에서 나가게)
대각선으로 이동 만약 다음 것이 행이 나가면 반대 행 지점으로, 열이 나가면 반대열 가다가
이미 체워진 곳이면 진행방향의 반대쪽(아래)에 체우고 다시 시작
만약 열과 행이 모두 나가버리면 체워진것 처럼 진행방향 반대쪽(아래)에 체우고 다시시작.

ex) 해커랭크 코드 이건 나올 수 있는 경우 가지고 구한 케이스

```cpp
#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
int sum = 0, res=1000;
int mM[8][3][3] = {
{{6,1,8},
        {7,5,3},
        {2,9,4}},

        {{8,1,6},
        {3,5,7},
        {4,9,2}},

        {{2,7,6},
        {9,5,1},
        {4,3,8}},

        {{4,3,8},
        {9,5,1},
        {2,7,6}},

        {{2,9,4},
        {7,5,3},
        {6,1,8}},

        {{4,9,2},
        {3,5,7},
        {8,1,6}},

        {{6,7,2},
        {1,5,9},
        {8,3,4}},

        {{8,3,4},
        {1,5,9},
        {6,7,2}},
    };

    for(int i=0; i<8; i++) {
        sum=0;
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                sum+= abs(mM[i][j][k]-s[j][k]);
            }
        }
        res = min(res, sum);
    }

    return res;

}

int main()
{
ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;

}
```

■ 프로그래머스 순위 문제 : 그래프 문제
엄청 무식하게 풀었다.
우선 단방향이고 이긴리스트 진리스트를 각 번호 노드에 넣어둔다.
이긴리스트로 DPS로 가장 긴 거리를 구한다음
그 거리만큼 전체탐색 반복문을 돌려 내가 이긴 노드의 이긴 정보랑 진 정보 다 가져다 내꺼에 넣는다.
진정보 이긴정보 + 1(자기자신) == 모든정보 에 해당하는 결과값이 나오면 +1해준다.  
요즘 c# 공부하느라 c#으로 풀었더니 더 어려운 것같다.

[c# 코드]
using System;
using System.Linq;
using System.Collections.Generic;

public class RankNode {
public HashSet<int> winList;
public HashSet<int> loseList;

    public RankNode() {
        winList = new HashSet<int>();
        loseList = new HashSet<int>();
    }

}

public class solve {

    public List<RankNode> rL = new List<RankNode>();

    public int getDepth(int n, List<int> testcase) {
        if(testcase.Count==0) return n;

        for(int i=0; i<testcase.Count; i++) return getDepth(n+1,rL[testcase[i]].winList.ToList());
        return 0;
    }

    public int solution(int n, int[,] results) {
        int answer = 0;
        int maxDepth = 0;

        //input
        for(int i=0; i<=n; i++) rL.Add(new RankNode());

        for(int i=0; i<results.Length*0.5; i++) {
            rL[results[i,0]].winList.Add(results[i,1]);
            rL[results[i,1]].loseList.Add(results[i,0]);
        }

        //MaxDepthFind
        for(int i=1; i<=n; i++) {
            maxDepth = Math.max_val(getDepth(0, rL[i].winList.ToList()),maxDepth);
        }

        //SeachingToMaxDepth
        for(int i=0; i<maxDepth; i++) {
            for(int j=1; j<=n; j++) {
                RankNode rN = rL[j];

                foreach(var m in rN.winList.ToList()) foreach(var wSub in rL[m].winList.ToList()) rN.winList.Add(wSub);
                foreach(var l in rN.loseList.ToList()) foreach(var lSub in rL[l].loseList.ToList()) rN.loseList.Add(lSub);
            }
        }

        //result
        for(int i=1; i<=n; i++) {
            if(rL[i].winList.Count+rL[i].loseList.Count+1 == n) answer++;
        }

        return answer;
    }

}

■ 그래프 문제 : 사이클
그래프 문제를 풀다 보면 '사이클을 찾아라', '사이클일 경우는 안된다' 라는 조건이 걸린 문제를 종종 볼 수 있습니다.
만약 모든 정점에 대해서 dfs를 돌려 사이클을 찾게된다면 O(strings(strings+E))라는 시간으로 상당한 시간이 걸리게 될겁니다.
사이클 여부는 DFS트리 한번으로 찾을 수 있습니다.

결론부터 얘기하자면 사이클은 back_edge가 존재할 때 생기고, 이 back_edge의 유무를 찾아주면 됩니다.

단방향 그래프에서 사이클을 어떻게 찾는지 알아보겠습니다.

이런 그래프가 있을 때 빨간 간선과 같이 back_edge가 존재하면 사이클이 존재한다는 얘기입니다.
서브스패닝트리의 루트에 도달할 수 있으면 다시 루트부터 내려가기 때문에 사이클이 생깁니다.

```cpp
vector<vector<int>> v;
vector<int> visited;
vector<int> check;
int go(int u) {
if (visited[u]) return 1;
if (check[u]) return 0;
check[u] = 1;
visited[u] = 1;
for (int i = 0; i < v[u].size(); i++) {
if (go(v[u][i])) return 1;
}
visited[u] = 0;
return 0;
}
```

이런 식으로 코드를 작성할 수 있습니다.
현재 dfs재귀중이라면 그 정점은 방문 중인 정점입니다. 현재 방문 중인 정점을 visit배열에 기록을 해줍니다.
dfs이기 때문에 방문한 정점은 2번 방문하면 안됩니다. 그래서 check배열에서 방문 여부를 저장해줍니다.
만약 visit에 기록된 배열을 다시 방문한단얘기는 그 에지는 backedge란 얘기고 즉 사이클이 있단 얘기가 됩니다.

다음은 양방향 그래프에서의 사이클 찾기입니다.
양방향 그래프에서 사이클 찾기는 방문순서를 기록해줍니다.
부모를 제외한 에지들 중에 방문순서가 먼저인 정점이 있다면 이미 방문하나 정점이고, 사이클이 존재한다는 얘기입니다.

정점 안 숫자는 방문한 순서입니다. 부모가 아닌 에지인데 방문순서가 먼저라면 그 에지는 벡에지가 됩니다

```cpp
void go(int u, int p) {
for (int i = 0; i < adj[u].size(); i++) {
int v = adj[u][i];
if (p != v) {
if (n[v] == 0) {
n[v] = n[u] + 1;
go(v, u);
}
else if (n[u] > n[v]) {
printf("벡에지입니다");
}
}
}
}
```

[출처] 사이클 찾기|작성자 jh20s
http://blog.naver.com/PostView.nhn?blogId=jh20s&logNo=221248815321&categoryNo=7&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

무향 그래프에서 사이클은 (엣지 개수 >= 노드 개수) 면 무조건 싸이클이 있고 아니면 무조건 없음

■ 후보키 카카오 블라인드 테스트
```cpp
#include <bits/stdc++.h>

using namespace std;

bool isKeyCheck(vector<vector<string>> relation, int rSize, int cSize, int bMask) {
bool isSame;
for(int i=0; i<rSize-1; i++) {
for(int j=i+1; j<rSize; j++) {
isSame = true;
for(int k=0; k<cSize; k++) {
if((bMask & (1<<k)) == 0) continue;
if(relation[i][k] != relation[j][k]) {
isSame = false;
break;
}
}
if(isSame) return false;
}
}
return true;
}

int solution(vector<vector<string>> relation) {
int answer = 0;
int rSize = relation.size();
int cSize = relation[0].size();
vector<int> cKey;

    for(int i=1; i< (1<<cSize); i++) {
        if(isKeyCheck(relation, rSize, cSize, i))
            cKey.push_back(i);
    }

    sort(cKey.begin(), cKey.end(), [] (int command, int b) {
        int aR=0, bR=0;
        while(command) { if(command&1) aR++; command = command >>1; }
        while(b) { if(b&1) bR++; b = b >>1; }
        return aR > bR;
    });

    while(!cKey.empty()) {
        int n = cKey.back();
        cKey.pop_back();
        answer++;

        for(vector<int>::iterator it = cKey.begin(); it !=cKey.end();) {
            if((n & *it)==n) it = cKey.erase(it);
            else it++;
        }
    }

​  
​ return answer;
}
```

■ 오픈채팅방 카카오 블라인드 테스트
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
vector<string> answer;
command<string, string> uInfo;
vector<pair<string, int>> mList;
istringstream iss;
string m;
vector<string> msg;

    for(string r : record) {
        iss.clear();
        msg.clear();
        iss.str(r);
        while(getline(iss, m, ' ')) {
            msg.push_back(m);
        }

        if(msg[0]=="Enter") {
            uInfo[msg[1]]=msg[2];
            mList.push_back({msg[1],0});
        } else if(msg[0]=="Leave") {
            mList.push_back({msg[1],1});
        } else {
            uInfo[msg[1]]=msg[2];
        }
    }

    for(int i=0; i<mList.size(); i++) {
        if(mList[i].second) {
            answer.push_back(uInfo[mList[i].first]+"님이 나갔습니다.");
        } else {
            answer.push_back(uInfo[mList[i].first]+"님이 들어왔습니다.");
        }
    }

​ return answer;
}
```

---

### ■ 프로그래머스 이분탐색 > 징검다리 문제

파라메트릭 서치 문제다.0-distance 사이의 거리의 반을 나눠서 시작  
그 반의 거리보다 클 때까지 돌을 제거해서 제거해야하는 돌의 수가 n보다 많은가 적은가를 보고 mid 값을 옮긴다.  
n보다 적을 때 최대값을 구하면 되니까 계속 돌렸을 때 가장 높아진 low를 answer로 담으면 끝.

```c#
using System;

public class solve {
    public bool isRmCntMoreN(int m, int[] rocks, int n) {
        int rmCnt=0, last=0;

        foreach(int r in rocks) {
            if(r - last > m) last = r;
            else rmCnt++;
        }

        return rmCnt>n;
    }

    public int solution(int distance, int[] rocks, int n) {
        int answer, l=0, h=distance, m;

        Array.Sort(rocks);

        while(l<=h) {
            m = (l+h)/2;
            if(isRmCntMoreN(m, rocks, n)) h=m-1;
            else l=m+1;
        }

        return answer = l;
    }
}
```

### ■ 프로그래머스 이분탐색 > 예산 문제

이것도 파라메트릭
예산액이 초과되면(빼서 0보다 작아지면) 예산액 반으로 줄이고 돌려보고 통과하면 늘려서 돌리고 해서 통과할 때만 기록해 가능한 최댓값을 구한다.
```cpp
#include <bits/stdc++.h>

using namespace std;

bool isBudgetOver(vector<int>& budgets, int& mid, int m, int& answer) {
for(auto b : budgets) {
if(b > mid) m-=mid;
else m-=b;

        if(m<0) return true;
    }

    answer = max(answer, mid);
    return false;

}

int solution(vector<int> budgets, int m) {
sort(budgets.begin(),budgets.end());
int answer = 0, l=1, h=budgets.back(), mid;

    while(l<=h) {
        mid = (l+h)/2;
        if(isBudgetOver(budgets, mid, m, answer)) h=mid-1;
        else l=mid+1;
    }

    return answer;

}
```

### ■ 프로그래머스 그래프 > 사이클 제거

처음 코드

```c++
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visitedOrder;
vector<int> chkList;
bool hasC;

void hasCycle(int now, int parent, int except) {
    for(int i=0; i<adj[now].size(); i++) {
        if(hasC) return;
        int to = adj[now][i];
        if(to == except) continue;
        if(to != parent) {
            if(visitedOrder[to] == 0) {
                visitedOrder[to] = visitedOrder[now] + 1;
                chkList.erase(remove(chkList.begin(),chkList.end(), to),chkList.end());
                hasCycle(to, now, except);
            } else if(visitedOrder[to] < visitedOrder[now]) {
                hasC=true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    adj.resize(n+1, vector<int>());

    for(int i=0; i<edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for(int i=1; i<=n; i++) {

        chkList = adj[i];
        hasC=false;
        for(int j=0; j<chkList.size(); j++) {
            visitedOrder.resize(n+1, 0);
            hasCycle(chkList[j],0, i);
            visitedOrder.clear();
        }
        if(!hasC) { answer+=i; }
    }

    return answer;
}
```

서브트리에 포함된 백엣지의 수 구하는 코드로 효율성 통과  
backT - i가 루트인 서브트리에 '완전히' 포함된 back edge의 수  
backS - i가 루트인 서브트리에 '조금이라도' 포함된 back edge의 수  
backP - i가 루트인 서브트리에서 i의 부모가 목적지인 back edge의 수

```c++
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, child;
vector<int> check, backT, backS, backP;

void dfsTree(int n, int from)
{
    for(auto to : adj[n]) {
        if(to != from) {
            if(!check[to]) {
                child[n].push_back(to);
                check[to] = check[n]+1;
                int tmp = backT[n];
                dfsTree(to, n);
                backP[to] = backT[n] - tmp;
                backT[n] += backT[to];
                backS[n] += backS[to];
            } else if(check[to]<check[n]) {
                backS[n]++;
                backT[to]++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0, eSize = edges.size();
    adj.resize(n+1); child.resize(n+1);
    check.resize(n+1, 0); backT.resize(n+1, 0);
    backS.resize(n+1, 0); backP.resize(n+1, 0);

    for(int i=0; i< eSize; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    check[1] = 1; dfsTree(1,0);

    for(int i=1; i<=n; i++) {
        bool skip = false;
        for(auto to : child[i]) if(backS[to] - backP[to] > 1 || backT[to]) skip = true;
        if(skip || eSize-(n-1)-backS[i] != 0 ) continue;
        answer+=i;
    }

    return answer;
}
```

### ■ 프로그래머스 그래프 > 방의 개수

평면그래프 문제  
평면 그래프(planar graph)는 평면 상에 그래프를 그렸을 때, 두 변이 꼭짓점 이외에 만나지 않도록 그릴 수 있는 그래프를 의미한다.  
평면 그래프의 공식 v - e + f = 2  
v = 점의 개수, e = 선의 개수, f = 면의 개수  
시작시점부터 모든 점과 선을 구한다음 식 맞춰주면 되는데 여기서 중요한 점은 식에서 좌표 평면 전체도 평면으로 세기 때문에 f면의 개수 -1 해줘야함  
그리고 대각선끼리 만나는 점은 소수점이 나오니까  
ex) (0,0 -> 1,1) (1,0, -> 0,1) 라면 0.5, 0.5 에서 만나니까  
공식에 따를거니까 선, 점의 개수가 늘어나는건 상관없으니 애초에 2의 길이만큼 가게 해서 1.0 에서 만나게 만듬.

```c#
using System;
using System.Collections.Generic;

public class solve {
    public int solution(int[] arrows) {
        int[] dX = {0, 1, 1,  1,  0, -1, -1, -1};
        int[] dY = {1, 1, 0, -1, -1, -1,  0,  1};
        HashSet<Tuple<int,int>> v = new HashSet<Tuple<int,int>>();
        HashSet<Tuple<Tuple<int,int>, Tuple<int,int>>> e = new HashSet<Tuple<Tuple<int,int>, Tuple<int,int>>>();
        int answer = 0, x=0, y=0;

        v.Add(Tuple.Create(x,y));


​
​        for(int i=0; i<arrows.Length; i++) {
​            for(int j=0; j<2; j++) {
​                int nX = x + dX[arrows[i]];
​                int nY = y + dY[arrows[i]];
​                Tuple<int, int> srtPnt = Tuple.Create(x, y);
​                Tuple<int, int> endPnt = Tuple.Create(nX, nY);
​                int result = endPnt.Item1.CompareTo(srtPnt.Item1);
​                if( result == 0 ) result = endPnt.Item2.CompareTo(srtPnt.Item2);
​                if( result > 0 ) {
​                    Tuple<int, int> temp = srtPnt;
​                    srtPnt = endPnt;
​                    endPnt = temp;
​                }
​                e.Add(Tuple.Create(srtPnt, endPnt));
​                x = nX;
​                y = nY;
​                v.Add(Tuple.Create(x,y));
​            }
​        }
​
​        return answer = 2 - v.Count + e.Count - 1;
​    }
}
```
