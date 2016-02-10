#define DEBUG_MODE
#include <iostream>
#include "manager.hpp"
#include "interface.hpp"
using std::cout;
using std::endl;
using namespace Interface;

int main() {
	// Zを用いてインスタンスを得る
	// インターフェースクラスはZのテンプレートパラメータで指定する
    auto&& a = Z<A>::get_instance();
    auto&& b = Z<B>::get_instance();

    // 同じくZを用いてインターフェースとして関数を得る
    auto&& func = Z<E>::get_interface();

    //　インターフェースを使い倒す
    cout << a.Calculate(1,2) << endl;
    cout << func(1,2) << endl;
    cout << b(2,3) << endl;

    // しかるべきタイミングでFinalizer()を呼び出して開放する
    // すべてのインターフェースオブジェクトが開放される
    Finalizer();
}