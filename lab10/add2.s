.data


.text

.globl add2


add2:

    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movq %r12, -8(%rbp)
    movl $0, %r12d

loop:

    cmp $0, %rdi
    je final_loop

    
    addl (%rdi),%r12d
    movq 8(%rdi),%rdi
    call add2
    addl %eax,  %r12d
    movl %r12d, %eax
    movq -8(%rbp),%r12
    leave
    ret


final_loop:
    movl $0, %eax
    movq -8(%rbp),%r12
    leave
    ret