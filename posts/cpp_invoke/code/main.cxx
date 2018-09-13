#include <cstdio>
#include <functional>

// int fn( int param ) { return param; }
// int (*fn_ptr)(int) = &fn;
// struct S {
//    int object_member = 5;
//    int mem_fn( int param ) { return param; }
//    int operator()( int param ) { return param; }
// };
// S s;
// S callable_struct;
// int (S::*mem_fn_ptr)(int) = &S::mem_fn;
// int S::*obj_mem_ptr = &S::object_member;
// auto lambda = []( int param ) { return param; };

// int main( int argc, char* argv[] ) {
//    printf( "%d\n", fn( 1 )              );  // free functions
//    printf( "%d\n", fn_ptr( 2 )          );  // free function pointers
//    printf( "%d\n", (s).mem_fn( 3 )      );  // member functions
//    printf( "%d\n", (s.*mem_fn_ptr)(4)   );  // member function pointers
//    printf( "%d\n", s.object_member      );  // object members
//    printf( "%d\n", s.*obj_mem_ptr + 1   );  // object member pointers
//    printf( "%d\n", callable_struct( 7 ) );  // overloaded call operator
//    printf( "%d\n", lambda( 8 )          );  // lambda
//    return 0;
// }



int foo( int param ) {
   return param;
}
struct S { int foo( int param ) { return param; } };
S s;

int main( int argc, char* argv[] ) {
   int a = 7;
   int& b = a;
   std::reference_wrapper<int> c = a;
   b = 8;
   printf( "%d\n", a );
   printf( "%d\n", (int&)c );
   printf( "%d\n", (int&)b );
   printf( "%d\n", std::invoke( foo, 6 ) );
   printf( "%d\n", std::invoke( &S::foo, s, 6 ) );
   return 0;
}
