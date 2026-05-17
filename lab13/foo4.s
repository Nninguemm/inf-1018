/*
int foo (int x) {
  return x+1;
}
*/

.data

.text

.globl foo

foo: 
    pushq %rbp
    movq %rsp, %rbp

    call add
    leave
    ret