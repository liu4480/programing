#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <bits/stdc++.h>

int linear_search(int arr[], int n, int x);

int binary_search(int arr[], int l, int r, int x);

int jump_search(int arr[], int n, int x);

int interpolation_search(int arr[], int n, int x);

int exponential_search(int arr[], int n, int x);

int ternary_search(int arr[], int l, int r, int x);

#endif
