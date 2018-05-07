#!/usr/bin/env python  
  
from distutils.core import setup, Extension  
  
MOD = 'c_module'  
setup(name=MOD, ext_modules=[Extension(MOD, sources=['c_module.c'])]) 
