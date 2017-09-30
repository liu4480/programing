#! /usr/bin/python

def secret_function():
    return "secret key is 1234"

def function_creator():
    expr = raw_input("enter the function(in terms of x):")

    x=int(raw_input("enter a value of x:"))

    safe_dict['x'] = x
    y = eval(expr, {"__builtins__": None}, safe_dict)

    print("y={}".format(y))

if __name__ == "__main__":
    safe_list = ['acos', 'asin', 'atan', 'atan2', 'ceil', 'cos',
                 'cosh', 'degrees', 'e', 'exp', 'fabs', 'floor',
                 'fmod', 'frexp', 'hypot', 'ldexp', 'log', 'log10',
                 'modf', 'pi', 'pow', 'radians', 'sin', 'sinh', 'sqrt',
                 'tan', 'tanh']
    safe_dict = dict([(k, locals().get(k, None)) for k in safe_list])
    function_creator()
