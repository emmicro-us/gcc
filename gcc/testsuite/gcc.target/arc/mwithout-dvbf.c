/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-do assemble } */
/* { dg-excess-errors "bad instruction" } */

int f (int i)
{
  __asm__("vbfdw %1, %1" : "=r"(i) : "r"(i));
  return i;
}
