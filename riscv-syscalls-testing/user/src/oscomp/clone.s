# __clone(func, stack, flags, arg, ptid, tls, ctid)
#           x0,    x1,    x2,  x3,   x4,  x5,   x6

# syscall(SYS_clone, flags, stack, ptid, tls, ctid)
#                x7     x0,    x1,   x2,  x3,   x4

.global __clone
.type  __clone, %function
__clone:
	# Save func and arg to stack
	add x1, x1, -16
	str x0, [x1, #0]
	str x3, [x1, #8]

	# Call SYS_clone
	mov x0, x2
	mov x2, x4
	mov x3, x5
	mov x4, x6
	ldr x8, =220
	svc #0

	cbz x0, 1f
	# Parent
	ret

	# Child
1:      ldr x1, [sp, #0]
	ldr x0, [sp, #8]
	blr x1

	# Exit
	ldr x8, =93
	svc #0
