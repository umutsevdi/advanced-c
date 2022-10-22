# Bit Operations

## Bit Masks

A bit mask is a data that is used for bitwise operations. A mask can be used to set
multiple bits in a byte.

```c
#include <stdio.h>

int m_xor(int v) {
    return v ^ 0b111111111111111;
}

int m_and(int v) {
    return v & 0b111111111111111;
}

int main() {
    printf("%b\n", m_xor(0b11110000)); // 111111100001111
    printf("%b\n", m_and(0b11110000)); // 11110000
} ```

## Packaging Data Using Bit Manipulations

```xml
 ┌──────────────────────────────┐
 │ 0b 0 0 0 0 0 0 0 0 0 0 0 0 0 │
 └──────────────────────────────┘
      ^---------^ ^---^ ^-----^
        fn_index  type    arg
```

By combining these operators we can package complex data types.

```c
#define MASK 0xff
unsinged long color = 0xfff02ac12;
unsigned char blue, red, green;
red = color & MASK;
green = (color >> 8) & MASK;
blue = (color >> 16) & MASK;
```

## Bit Fields

A bit field allows you to specify the number of bits in which an int member of a
structure is stored.

```c
#include <stdio.h>

typedef struct packed_data {
  unsigned int id : 3;
  unsigned int s1 : 1;
  unsigned int s2 : 1;
  char code[8];
} p_data;

int main() {
  p_data p = {.id = 5, .s1 = 0, .s2 = 1, .code = "d_init"};
  printf("%d %d %d %s\n", p.id, p.s1, p.s2, p.code);
}
```
