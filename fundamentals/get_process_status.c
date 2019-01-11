#include<stdio.h>

int global_i;
int global_j=1;

void main()
{
int local_m;
int local_n=2;
printf("&globe_i=%p\n",&global_i);
printf("&globe_j=%p\n",&global_j);
printf("&local_m=%p\n",&local_m);
printf("&local_n=%p\n",&local_n);
while(1);
//使用ps aux查看所有进程，cat /proc/+进程号/maps查看。。。
}
