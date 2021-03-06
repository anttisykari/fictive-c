#include <stdio.h>

typedef long long int64;
typedef int int32;
//typedef int32 int;

#define PRINT_OFFSET(var, offset) \
	printf("data at %p: %p\n", &var + offset, (void *)*(&var + offset))

#define INFO() \
	PRINT_OFFSET(i, -12); \
	PRINT_OFFSET(i, -11); \
	PRINT_OFFSET(i, -10); \
	PRINT_OFFSET(i, -9); \
	PRINT_OFFSET(i, -8); \
	PRINT_OFFSET(i, -7); \
	PRINT_OFFSET(i, -6); \
	PRINT_OFFSET(i, -5); \
	PRINT_OFFSET(i, -4); \
	PRINT_OFFSET(i, -3); \
	PRINT_OFFSET(i, -2); \
	PRINT_OFFSET(i, -1); \
	printf("First argument is at:\n"); \
	PRINT_OFFSET(i, 0); \
	PRINT_OFFSET(i, 1); \
	PRINT_OFFSET(i, 2); \
	PRINT_OFFSET(i, 3); \
	PRINT_OFFSET(i, 4); \
	PRINT_OFFSET(i, 5); \
	PRINT_OFFSET(i, 6); \
	PRINT_OFFSET(i, 7); \
	PRINT_OFFSET(i, 8); \
	PRINT_OFFSET(i, 9); \
	PRINT_OFFSET(i, 10); \
	PRINT_OFFSET(i, 11); \
	PRINT_OFFSET(i, 12); \
 \
    asm( \
        "movq %%rsp, %0;" \
        "movq %%rbp, %1;" \
        "movq %%rax, %2;" \
        "movq %%rbx, %3;" \
        "movq %%rcx, %4;" \
        "movq %%rdx, %5;" \
        :"=r"(esp), "=r"(ebp), "=r"(eax), "=r"(ebx), "=r"(ecx), "=r"(edx) \
        ); \
 \
    printf("esp is: %p\n", esp); \
    printf("ebp is: %p\n", ebp); \
/*    printf("eax is: %p\n", eax); \
    printf("ebx is: %p\n", ebx); \
    printf("ecx is: %p\n", ecx); \
    printf("edx is: %p\n", edx); */ \
    printf("\n");

void* esp;
void* ebp;
void* eax;
void* ebx;
void* ecx;
void* edx;

int64 f(int64 i, int64 j, int64 k, ...) {
	int64 x = 0x1111111111111111;
	int64 y = 0x2222222222222222;
	int64 z = 0x3333333333333333;

	INFO();

	x = y = z = x;
	return 0x1111222233334444;
}

int main(int64 i, char* argv[]) {
	printf("main is at %p\n", main);
	printf("   f is at %p\n", f);
	int64 x = 0x1111000000000000;
	int64 y = 0x2222000000000000;
	int64 z = 0x3333000000000000;
	
	int64 result = f(1, 2, 3, 0xaaaaaaaa, 0xbbbbbbbb, 0xcccccccc);

	INFO();
	
	x = y = z = x;

	return result > 0;
}
