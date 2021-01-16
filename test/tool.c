#include"tool.h"

int add(int x,int y){
    return x+y;
}
int sub(int x,int y){
    return x-y;
}
int mul(int x,int y){
    return x*y;
}
int div(int x,int y){
    if(y==0){
        return INT_MAX;
    }
    else return x/y;
}