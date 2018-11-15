#include <stdio.h>   // declare functions for input and output
#include <stdlib.h>  // define EXIT_FAILURE and EXIT_SUCCESS
#include <string.h>  // for strcmp
#include <stdbool.h> // for Boolean type (true or false)

int countTrees(int v)
{
    if(v <= 1) return (1);
    int sum = 0;
    int left, right, root;
    for(root=1; root<=v;root++)
    {
        left = countTrees(root-1);
        right = countTrees(v - root);
        sum+=left*right;
    }
    return sum;
}
int main(int argc, char * * argv)
{ 
    int val = strtol(argv[1], NULL, 10);
    int valresult = 0;
    valresult = countTrees(val);
    printf("Number of trees: %d\n", valresult);
    return EXIT_SUCCESS;
}
