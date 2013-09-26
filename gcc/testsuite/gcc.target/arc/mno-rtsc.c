/* { dg-do compile } */
/* { dg-options "-mno-rtsc" } */
/* { dg-do assemble } */
/* { dg-excess-errors "bad instruction" } */

int f (int i)
{
  __asm__("rtsc %1, %1" : "=r"(i) : "r"(i));
  return i;
}
