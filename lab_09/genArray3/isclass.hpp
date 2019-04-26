#ifndef ISCLASS_HPP
#define ISCLASS_HPP

template <class T>
struct IsClass {
    template<class X> static char Test(int X::*);
    template<class X> static long Test(...);
    enum { Yes = sizeof(Test<T>(0)) == 1 };
    enum { No = !Yes };
};

#endif // ISCLASS_HPP
