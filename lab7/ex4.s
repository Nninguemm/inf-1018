/*
#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/

.data
Sf: .string "soma = %d\n"
Array: .int 65, -105, 111, 34

.text
.globl  main
main:
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  
  movq    %r12, -16(%rbp)  


  movl $0, %ebx 
  movq $Array, %r12
  movq $0, %r13

L1:
  cmpl $4, %ebx
  jge L2
  movl %ebx, %edx
  imull $4, %edx
  movq %r12, %rcx
  addq %rdx, %rcx
  addl (%rcx), %r13d


  addl  $1, %ebx   
  jmp  L1          

L2:
  movq $Sf, %rdi   
  movl %r13d, %esi
  movl $0, %eax
  call  printf
  movq  $0, %rax
  movq  -16(%rbp), %r12
  movq  -8(%rbp), %rbx
  leave
  ret