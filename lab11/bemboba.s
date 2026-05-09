/*
int bemboba (int num) {
  int local[4];
  int *a;
  int i;

  for (i=0,a=local;i<4;i++) {
    *a = num;
    a++;
  }
  return addl (local, 4);
}
    %r10d = 1
    %r11 = a
    local[4] = -16%rbp
*/

.data

.text

.globl bemboba

bemboba:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp


    movl $0, %r10d
    leaq -16(%rbp), %r11

Loop:

    cmpl $4, %r10d
    jge  final

    movl %edi, (%r11)
    addq $4, %r11
    incl %r10d

    jmp Loop


final:
    leaq -16(%rbp), %rdi
    movl $4, %esi
    call addl
    leave
    ret
