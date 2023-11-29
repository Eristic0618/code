// qsort����������͵�����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ������������
int cmp_int(const void *p1, const void *p2)
{
    return *((int *)p1) - *((int *)p2);
}

void test1()
{
    int arr1[10] = {2, 5, 3, 8, 7, 0, 9, 6, 1, 4};
    size_t sz = sizeof(arr1) / sizeof(arr1[0]);
    qsort(arr1, sz, sizeof(arr1[0]), cmp_int);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr1[i]);
    }
}

// ����ṹ��
struct Stu
{
    char name[20];
    int age;
};
// ����������
int cmp_stu_by_name(const void *p1, const void *p2)
{
    return strcmp(((struct Stu *)p1)->name, ((struct Stu *)p2)->name);
}
//����������
int cmp_stu_by_age(const void *p1, const void *p2)
{
    return ((struct Stu *)p1)->age - ((struct Stu *)p2)->age;
}

void test2()
{
    struct Stu arr2[] = {{"zhangsan", 18}, {"lisi", 24}, {"wangwu", 21}};
    size_t sz = sizeof(arr2) / sizeof(arr2[0]);
    // qsort(arr2, sz, sizeof(arr2[0]), cmp_stu_by_name);
    qsort(arr2, sz, sizeof(arr2[0]), cmp_stu_by_age);
    for (int i = 0; i < sz;i++)
    {
        printf("%s %d\n", arr2[i].name,arr2[i].age);
    }
}

int main()
{
    // test1();
    test2();
    return 0;
}