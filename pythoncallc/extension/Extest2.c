#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n)
{
    if (n < 2)
        return 1;
    else 
        return n*fact(n-1);
}

char * reverse(char * s)
{
    register char t, *p = s, *q = (s + (strlen(s)-1));
    while(p < q)
    {
        t = *p;
        *p++ = *q;
        *q-- = t;
    }
    return s;
}

int test()
{
    char s[BUFSIZ];
    printf("4!==%d\n", fact(4));
    printf("8!==%d\n", fact(8));
    printf("12!==%d\n", fact(12));
    strcpy(s, "abcdef");
    printf("reversing 'abcdef', we get '%s'\n", reverse(s));
    strcpy(s, "madam");
    printf("reversing 'madam', we get '%s'\n", reverse(s));
    return 0;
}

//包含Python的头文件
#include "Python.h"

//b、为每个模块的每一个函数增加一个型如PyObject* Module_func()的包装函数
static PyObject* Extest_fact(PyObject *self, PyObject *args)
{
    int num;
    if(!PyArg_ParseTuple(args, "i", &num))
        return NULL;

    return (PyObject*)Py_BuildValue("i", fact(num));
}

static PyObject* Extest_doppel(PyObject *self, PyObject *args)
{
    char *orig_str;
    char *dupe_str;
    PyObject *retval;

    if(!PyArg_ParseTuple(args, "%s", &orig_str))
        return NULL;

    retval = (PyObject*)Py_BuildValue("ss", orig_str, dupe_str=reverse(strdup(orig_str)));

    free(dupe_str);
    return retval;
}

static PyObject* Extest_test(PyObject *self, PyObject *args)
{
    test();
    return (PyObject*)Py_BuildValue("");
}

//c、为每个模块增加一个型如PyMethodDef ModuleMethods[]的数组
static PyMethodDef ExtestMethods[] =
{
    {"fact", Extest_fact, METH_VARARGS},
    {"doppel", Extest_doppel, METH_VARARGS},
    {"test", Extest_test, METH_VARARGS},
    {NULL, NULL},
};

//d、增加模块初始化函数void initModule()。
void initExtest()
{
    Py_InitModule("Extest", ExtestMethods);
}
