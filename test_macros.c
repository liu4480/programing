// Last Update:2017-04-13 17:19:56
/**
 * @file test_macros.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2017-04-13
 */

#include<stdio.h>

int main(void)
{
    printf("OS:");
#if defined(__linux__)
    printf("linux\n");
#elif defined(__BSD__)
    printf("BSD\n");
#elif defined(__DARWIN__)
    printf("APPLE\n");
#elif defined(_WIN32) || defined(_WIN64)
    printf("windows\n");
#endif

    printf("Platform:");
#if defined(__i386__)
    printf("i386\n");
#elif defined(__x86_64__)
    printf("x86_64\n");
#elif defined(__IA64__)
    printf("IA64\n");
#elif defined(__ALPHA__)
    printf("ALPHA\n");
#elif defined(__POWERPC__)
    printf("POWERPC\n");
#endif

    printf("Endian:");
#if __BYTE_ORDER == __LITTLE_ENDIAN
    printf("Little endian\n");
#elif __BYTE_ORDER == __BIG_ENDIAN
    printf("Big endian\n");
#endif

    printf("Vendor:");
#if defined(__BORLANDC__)
    printf("Borland\n");
#elif defined(__VECTORC__)
    printf("Codeplay VectorC\n");
#elif defined(__DMC__)
    printf("Digital Mars\n");
#elif defined(__GNUC__)
    printf("Gnu\n");
#elif defined(__INTEL_COMPILER)
    printf("Intel\n");
#elif defined(_MSC_VER)
    printf("Microsoft\n");
#elif defined(__PATHSCALE__)
    printf("Pathscale\n");
#elif defined(__SYMANTECC__)
    printf("Symantec\n");
#elif defined(__WATCOMC__)
    printf("Watcom\n");
#endif
    return 0;
}
