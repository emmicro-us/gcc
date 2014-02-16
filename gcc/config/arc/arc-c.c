/* Subroutines used for code generation on the Synopsys DesignWare ARC cpu.
   Copyright (C) 1994, 1995, 1997, 2004, 2007-2014
   Free Software Foundation, Inc.

   contributed by by Joern Rennecke <joern.rennecke@embecosm.com>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "hard-reg-set.h"
#include "c-family/c-common.h"

#define builtin_define(TXT) cpp_define (pfile, TXT)
#define builtin_assert(TXT) cpp_assert (pfile, TXT)

/* Names to predefine in the preprocessor for this target machine.  */
void
arc_cpu_cpp_builtins (cpp_reader* pfile)
{
  builtin_define ("__arc__");
  if (TARGET_A5)
    builtin_define ("__A5__");
  else if (TARGET_ARC600)
    {
      builtin_define ("__A6__");
      builtin_define ("__ARC600__");
    }
  else if (TARGET_ARC601)
    {
      builtin_define ("__ARC601__");
    }
  else if (TARGET_ARC700)
    {
      builtin_define ("__A7__");
      builtin_define ("__ARC700__");
    }
  if (TARGET_NORM)
    {
      builtin_define ("__ARC_NORM__");
      builtin_define ("__Xnorm");
    }
  if (TARGET_MUL64_SET)
    builtin_define ("__ARC_MUL64__");
  if (TARGET_MULMAC_32BY16_SET)
    builtin_define ("__ARC_MUL32BY16__");
  if (TARGET_SIMD_SET)
    builtin_define ("__ARC_SIMD__");
  if (TARGET_BARREL_SHIFTER)
    builtin_define ("__Xbarrel_shifter");
  builtin_assert ("cpu=arc");
  builtin_assert ("machine=arc");
  builtin_define (TARGET_BIG_ENDIAN ? "__BIG_ENDIAN__" : "__LITTLE_ENDIAN__");
  if (TARGET_BIG_ENDIAN)
    builtin_define ("__big_endian__");
  if ((unsigned)arc_tp_regno < FIRST_PSEUDO_REGISTER)
    builtin_define_with_value ("__ARC_RTP__", reg_names[arc_tp_regno], 0);
}
