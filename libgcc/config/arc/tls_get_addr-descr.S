/* This file really belongs to uClibc, but is included here
   to facilitate linking it into shared libraries as needed.
   Licensed under the LGPL v2.1 or later.  */
/* This file contains some asm code that is needed once in each shared
   library for tls global dynamic descriptors.  */

	.section .bss
	.align 4
	.type __tlsmod, @object
	.size __tlsmod, 8
__tlsmod:
	.zero 8

	.balign 4
	.type __tls_get_gd_addr, @function
__tls_get_gd_addr:
	ld r9,[__ARC_RTP__,0] ; [rtp,offsetoff(tcbhead_t,dtv)] ; fetch dtv
	ld r11,[pcl,__tlsmod@pcl+4] ; __tlsmod.generation
	ld r12,[r9,4] ; generation
	ld r10,[pcl,__tlsmod@pcl]   ; __tlsmod.index
	brlo.d r12,r11,.Lrefresh_dtv
	ld_s r12,[r0,4] ; fetch DTPOFF
	ld.as r11,[r9, r10]

	add r0,r12,__ARC_RTP__
	add.f r0,r0,r11
	jcc [blink]
.Lrefresh_dtv:
	ld r0,[pcl,__tls_get_addr_rfresh_dtv@gotpc]
	push_s r1
	push_s r2
	j_s.d [r0]
	push_s r3
	.size __tls_get_gd_addr,.-__tls_get_gd_addr

	.balign 4
	.global __tls_get_gd_dispatch
	.protected __tls_get_gd_dispatch
	.type __tls_get_gd_dispatch, @function
__tls_get_gd_dispatch:
	add r12,pcl,__tlsmod@pcl
	st_s r0,[r12,0]
	st_s r1,[r12,4]
0:	j_s.d [blink]
	.short 0x2758,0x7000+(0b-__tls_get_gd_addr)*16 ; sub2 r0,pcl,u6
	.size __tls_get_gd_dispatch,.-__tls_get_gd_dispatch
