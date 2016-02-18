#include <cmath>
/*
(1)
まず、除数 j がN/2を超えればNを割りきらないから
計算をうち切れる
同様に、N/3までで十分である
この考えを反復し、√Nまでの整数で割れば良い
(2)
Nが2で割り切れなければ偶数で割り切れないから
√Nまでの奇数で割れば良い
(3)
さらに、3で割り切れなければ3の倍数で割り切れないから
2と3で割ってみて、以後
5,7,11,13,...
というふうに5に2と4を交互に増やして
√Nまでの奇数で割れば良い
*/
bool is_prime(unsigned long long n){
    if(n < 2) return false;
    if(n < 4) return true;
	if(n%2==0) return false;
	if(n%3==0) return false;
	unsigned long long j = 5;
	for(bool i = false; j<=sqrt(n);i=!i){
		if(n%j==0) return false;
		j += 2 + 2*i;
	}
	return true;
}
