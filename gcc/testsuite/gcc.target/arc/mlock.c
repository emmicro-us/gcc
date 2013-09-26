/* { dg-do compile } */
/* { dg-options "-mlock" } */
/* { dg-do assemble } */

int f (int i)
{
  __asm__("llock %1, %1" : "=r"(i) : "r"(i));
  return i;
}
