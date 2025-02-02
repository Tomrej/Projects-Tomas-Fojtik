#include "dva.h"

#include <stdio.h>

int obvodctverec(int a)
        {
        return (4*a);
        }

int obsahctverec(int x)
        {
        return (x*x);
        }

int obvodobdelnik(int x, int y)
        {
        return (2*(x+y));
        }

int obsahobdelnik(int x, int y)
        {
        return (x*y);
        }

int obvodtrojuhelnik(int x, int y, int z)
        {
        return (x+y+z);
        }

int obsahtrojuhelnik(int x, int v)
        {
        return ((0.5*x)*v);
        }

int obvodkruh(int x)
        {
        return (2*3.14*x);
        }

int obsahkruh(int x)
        {
        return (3.14*x*x);
        }

int obvodlichobeznik(int x, int y, int z, int n)
        {
        return (x+y+z+n);
        }

int obsahlichobeznik(int x, int z, int v)
        {
        return (((x+z)*v)/2);
        }

void sestrojittrojuhelnik(int x, int y, int z)
        {

        if(x+y<=z){
                printf("nelze sestrojit\n");
        } else{
                printf("lze sestrojit\n");
        }
        return;

        }
