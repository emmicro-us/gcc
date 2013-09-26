/* { dg-do compile } */
/* { dg-options "-mnodsp-packa" } */
/* { dg-do assemble } */
/* { dg-excess-errors "bad instruction" } */

int f (int i)
{
  __asm__("minidl %1, %1, %1" : "=r"(i) : "r"(i));
  return i;
}
