// { dg-options "-pedantic" }

void (*p)();

void f() {
  (void *)p;
}
