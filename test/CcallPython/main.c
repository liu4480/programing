#include <stdio.h>
#include "Python.h"
//#include <python/Python.h>

int function_from_python(int a, int b)
{
    Py_Initialize();

    int res;
    PyObject *pModule = NULL;
    PyObject *pFunc = NULL;
    PyObject *pArgs = NULL;
    PyObject *pResult = NULL;

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("print '---import sys---'");
    PyRun_SimpleString("sys.path.append('./')");

    if(!(pModule = PyImport_Import(PyString_FromString("python_called"))))
    {
        printf("get module failed!\n");
        exit(0);
    }

    if(!(pFunc=PyObject_GetAttrString(pModule, "add_func")))
    {
        printf("get func failed!\n");
        exit(0);
    }

    pArgs = Py_BuildValue("ii", a, b);
    pResult = PyObject_CallObject(pFunc, pArgs);

    res = PyInt_AsLong(pResult);

    if(pArgs)
        Py_DECREF(pArgs);
    if(pFunc)
        Py_DECREF(pFunc);
    if(pModule)
        Py_DECREF(pModule);
    Py_Finalize();

    return res;
}

int main()
{
    printf("C call python function\n");
    printf("%d\n", function_from_python(3, 5));
    return 0;
}
