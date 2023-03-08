// inserting into a vector
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}

//#include <iostream>
//#include <vector>

//#include "list/list.hpp"
//
//struct A
//{
//    A(int a_, int b_) : a(a_), b(b_) {}
//
//    int a;
//    double b;
//};
//
//int main()
//{
//    std::vector<A> v;
//    v.emplace_back(1, 2);
//
//    return 0;
//}

//#include <stdexcept>
//#include <iostream>
//
//// TODO: check
//struct X
//{
//    X() { throw std::runtime_error(""); }
//
//    // custom placement new
//    static void* operator new(std::size_t count, bool b)
//    {
//        std::cout << "custom placement new called, b = " << b << '\n';
//        void* ptr = ::operator new(count);
//        return ptr;
//    }
//
//    // custom placement delete
//    static void operator delete(void* ptr, bool b)
//    {
//        std::cout << "custom placement delete called, b = " << b << '\n';
//        ::operator delete(ptr);
//    }
//};
//
//int main()
//{
//    try
//    {
//        [[maybe_unused]] X* p1 = new (true) X;
//        std::cerr << "kek" << std::endl;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << std::endl;
//    }
//}