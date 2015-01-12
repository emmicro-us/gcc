<<<<<<< HEAD
// PR c++/58535

struct A
{
  template<int> virtual void foo(); // { dg-error "templates" }
=======
// PR c++/57352

struct x
{
  operator class {} ();  // { dg-error "types|expected" }
>>>>>>> upstream/master
};
