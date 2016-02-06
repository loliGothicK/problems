#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
unsigned sq(unsigned const& x){
	return x*x;
}
int main(){
	array<unsigned,3> edge;
	for(auto&& e : edge)
		cin >> e;
	sort(edge.begin(),edge.end());
	cout << ( edge[2] > edge[0]+edge[1] ? -1 : sq(edge[2]) == sq(edge[0])+sq(edge[1]) ? 1 : 0 ) << endl;
}