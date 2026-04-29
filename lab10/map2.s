.data


.text

.globl map2


map2:

    pushq %rbp  
    movq %rsp, %rbp 
    subq $32, %rsp 


    movq %rdi, -8(%rbp) 
    movq %rsi, -16(%rbp)
    movl %edx, -20(%rbp)
    movl %ecx, -24(%rbp)

    movl $0, %ecx

loop:
    movl %ecx, -24(%rbp) 
    cmpl %edx, %ecx
    jge fim_loop

    movl %ecx, %r8d 
    imulq $4, %r8
    addq %rdi, %r8

    movl (%r8), %edi


    call f

    movq -8(%rbp), %rdi
    movq -16(%rbp), %rsi
    movl -20(%rbp), %edx
    movl -24(%rbp), %ecx


    movl %ecx, %r8d
    imulq $4, %r8
    addq %rsi, %r8
    movl %eax, (%r8)

    incl %ecx 

    jmp loop


fim_loop:
    leave 
    ret