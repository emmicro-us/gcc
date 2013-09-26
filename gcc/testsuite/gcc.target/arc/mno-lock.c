/* { dg-do compile } */
/* { dg-options "-mno-lock" } */
/* { dg-do assemble } */
/* { dg-excess-errors "bad instruction" } */

int f (int i)
{
  __asm__("llock %1, %1" : "=r"(i) : "r"(i));
  return i;
}
