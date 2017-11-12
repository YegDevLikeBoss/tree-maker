#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define lim 1000

void error();
void use();

char inp[5];
const char
zro[5]={'\0', '\0', '\0', '\0', '\0'},
cmd1[5]="exit",
cmd2[5]="help",
cmd3[5]="arot",
cmd4[5]="anod";
int
mem[lim],
x[8],
y[8];


int main(int argc, char *argv[])
{
    int init, ch=0, nch=1, ch3=5, rootb=0, nv=0, nr=0, temp;
    int *third;
    for (init=0;init<lim-1;init++)
    {
        mem[init]=-998;
    }
    init=0;
    while (init==0)
    {
        printf(">>> ");
        int i=0, k=0, j;
        while(k==0)
        {
                inp[i] = getchar();
                if (inp[i]=='\n')
                {
                    inp[i]='\0';
                    k=1;
                }
                i++;
        }
        /*error(1);*/
        if (!strcmp(inp, cmd1))
            init=1;
            else if (!strcmp(inp, cmd2))
                use();
                else if (!strcmp(inp, cmd3))
                {
                    if (rootb==0)
                    {
                        printf("root value> ");
                        scanf("%d", &nv);
                        mem[ch]=0;
                        mem[nch]=nv;
                        ch+=3;
                        nch+=3;
                        rootb=1;
                        printf("***\nAdded root with value %d.\n***\n", nv);
                    }
                    else error(2);
                } else if (!strcmp(inp, cmd4))
                    {
                        int x=0;
                        printf("node value> ");
                        scanf("%d", &nv);
                        printf("parent node value> ");
                        scanf("%d", &nr);
                        for (temp=1;temp<lim-1;temp+=3)
                        {
                            if (mem[temp]==nr)
                            {
                                mem[ch]=mem[temp-1]+1;
                                mem[nch]=nv;
                                mem[ch3]=&mem[temp];
                                ch+=3;
                                nch+=3;
                                ch3+=3;
                                if (nv==nr)
                                {
                                    temp+=3; ch+=3; nch+=3; ch3+=3;
                                }
                                x=1;
                            }
                        }
                        if (x==0)
                            error(3);
                            else {
                            printf("***\nAdded node with value %d.\n***\n", nv);
                            x=0;
                        }
                    }
    }
    for (init=0;init<15;init+=3)
    {
        printf("%d\n", mem[init]);
        printf("%d\n", mem[init+1]);
        printf("%x\n", mem[init+2]);
    }
    return 1;
}

void error(int cs)
{
    switch (cs)
    {
        case 1:
        {
            printf("***\nERROR '%s' is not recognized as valid command.\n***\n", inp);
            use();
            break;
        }
        case 2:
        {
            printf("***\nERROR 'arot' could be only used once.\n***\n");
            break;
        }
        case 3:
        {
            printf("***\nERROR Couldn't find selected parent node.\n***\n");
            break;
        }
    }
}
void use()
{
    printf("***\nUse:\n'arot' for adding root\n'anod' for adding new node in root node\n'anpa' for adding new node with value with selected parent\n'ansi' for adding new node with selected sibling\n'show' to show tree\n'save' to save into selected text file\n'load' to load from selected text file\n'help' for help\n'exit' to exit program\n***\n");
}
