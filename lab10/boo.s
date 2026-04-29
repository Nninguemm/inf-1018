.data


.text
.globl boo

boo:
    pushq %rbp
    movq %rsp, %rbp
    subq $16,%rsp
    movq %r12, -8(%rbp)
    movl %r13d, -12(%rbp) 

loop:
    movq %rdi, -16(%rbp)  
    cmpl $0, %esi
    je final_loop
    subl $1, %esi
    movl %esi, %r13d


    movq 4(%rdi), %r12

    movl (%rdi), %edi
    movl %edx, -20(%rbp)   
    mov %edx, %esi

    call f
    movq -16(%rbp), %rdi
    movl -20(%rbp), %edx   
    movl %eax, 4(%rdi)     
    addq $8, %rdi
    movl %r13d, %esi          
    jmp loop

 
final_loop:

    movq -8(%rbp), %r12
    movl -12(%rbp),%r13d
    leave
    ret
