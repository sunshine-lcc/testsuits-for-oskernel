#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

#define __asm_syscall(...)             \
    __asm__ __volatile__("svc #0\n\t"   \
                         : "=r"(x0)    \
                         : __VA_ARGS__ \
                         : "memory");  \
    return x0;

static inline long __syscall0(long n)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0");
    __asm_syscall("r"(x7))
}

static inline long __syscall1(long n, long a)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0") = a;
    __asm_syscall("r"(x7), "0"(x0))
}

static inline long __syscall2(long n, long a, long b)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0") = a;
    register long x1 __asm__("x1") = b;
    __asm_syscall("r"(x7), "0"(x0), "r"(x1))
}

static inline long __syscall3(long n, long a, long b, long c)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0") = a;
    register long x1 __asm__("x1") = b;
    register long x2 __asm__("x2") = c;
    __asm_syscall("r"(x7), "0"(x0), "r"(x1), "r"(x2))
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0") = a;
    register long x1 __asm__("x1") = b;
    register long x2 __asm__("x2") = c;
    register long x3 __asm__("x3") = d;
    __asm_syscall("r"(x7), "0"(x0), "r"(x1), "r"(x2), "r"(x3))
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0") = a;
    register long x1 __asm__("x1") = b;
    register long x2 __asm__("x2") = c;
    register long x3 __asm__("x3") = d;
    register long x4 __asm__("x4") = e;
    __asm_syscall("r"(x7), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4))
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
    register long x7 __asm__("x7") = n;
    register long x0 __asm__("x0") = a;
    register long x1 __asm__("x1") = b;
    register long x2 __asm__("x2") = c;
    register long x3 __asm__("x3") = d;
    register long x4 __asm__("x4") = e;
    register long x5 __asm__("x5") = f;
    __asm_syscall("r"(x7), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5))
}

#define VDSO_USEFUL
/* We don't have a clock_gettime function.
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6" */

#define IPC_64 0
