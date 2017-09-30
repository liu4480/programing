#ifdef __cplusplus
extern "C"
{
#endif
    int printf(const char *format,...);
#ifdef __cplusplus
}
#endif
 
int main()
{
    printf("GeeksforGeeks");
#ifdef __cplusplus
    printf(" in C++\n");
#else
    printf(" in C\n");
#endif
    return 0;
}
