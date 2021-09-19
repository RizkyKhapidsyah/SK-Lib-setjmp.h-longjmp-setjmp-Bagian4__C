#include <stdio.h>
#include <setjmp.h>
#include <stdnoreturn.h>
#include <conio.h>

jmp_buf jump_buffer;

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

noreturn void a(int count) {
    printf("a(%d) called\n", count);
    longjmp(jump_buffer, count + 1); // will return count+1 out of setjmp
}

int main(void) {
    volatile int count = 0; // local vars must be volatile for setjmp

    if (setjmp(jump_buffer) != 9) {
        a(count++);
    }
        
    _getch();
    return 0;
}