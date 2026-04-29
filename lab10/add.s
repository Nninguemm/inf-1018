.data


.text
.globl add

add:

    push %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movl $0, %r10d 

loop:
    cmpq $0, %rdi 
    je final_loop
    addl (%rdi),%r10d
    movq 8(%rdi), %rdi 
    jmp loop


final_loop:
    movl %r10d, %eax
    leave
    ret