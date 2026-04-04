/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 1;
    while (num <=10)
    {
        printf("%d", num*num);
        ++num;
    }
    return 0;
}
*/

.data
Sf: .string "%d\n"

.text
.globl  main
main:


  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  
  movq    %r12, -16(%rbp)  


  movl  $1, %ebx  

L1:
  cmpl  $10, %ebx  
  jg  L2            

  movl  %ebx, %eax  
  imull %eax, %eax  


  movq    $Sf, %rdi   
  movl    %eax, %esi  
  movl    $0, %eax
  call    printf


  addl  $1, %ebx   
  jmp  L1          

L2:
  movq  $0, %rax
  movq  -16(%rbp), %r12
  movq  -8(%rbp), %rbx
  leave
  ret