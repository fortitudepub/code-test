#include <stdio.h>
#include <stdint.h>

// 测试部分bitfield内存位置，因此所谓uint64_t只是语法糖而已...
#pragma pack(push, 1)
typedef union {
    struct  __attribute__((packed)) {
            uint64_t msg: 40;
    } route_label;
    struct __attribute__((packed)) {
            uint8_t a;
            uint32_t b;
    } other;
} u;
#pragma pack(pop)

int main()
{
        u ui;
        printf("size of u %d\n", sizeof(u));
        printf("size of u.route_label %d\n", sizeof(ui.route_label));
        printf("size of u.other %d\n", sizeof(ui.other));
}
