/* Check that we use the ffs insn by checking assembler output. */
/* { dg-do compile } */
/* { dg-skip-if "Not available for ARCv1" { arc6xx || arc700 } } */
/* { dg-options "-O2 -mnorm" } */
/* { dg-final { scan-assembler "\tffs.*r0, r0" } } */
/* { dg-final { scan-assembler "\tffs.*r0, 16" } } */
int foo (int x)
{
  return __builtin_arc_ffs(x);
}

int bar (void)
{
  return __builtin_arc_ffs(0x10);
}
