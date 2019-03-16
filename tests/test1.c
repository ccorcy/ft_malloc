int main()
{
int i;
char *addr;
i = 0;
while (i < 500)
{
addr = (char*)malloc(1024);
addr[0] = 42;
i++;
}
show_alloc_mem();
return (0);
}