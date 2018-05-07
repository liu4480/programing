#include <python2.7/Python.h>

int add_func(int a, int b)
{
    return a + b;
}

static PyObject * _add_func(PyObject * self, PyObject * args)
{
    int _a, _b;
    int res;

    if(!PyArg_ParseTuple(args, "ii", &_a, &_b))
        return NULL;
    res = add_func(_a, _b);
    return PyLong_FromLong(res);
}

static PyMethodDef CModuleMethods[] = 
{
    {"add_func", _add_func, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initc_module(void)
{
    (void) Py_InitModule("c_module", CModuleMethods);
}
