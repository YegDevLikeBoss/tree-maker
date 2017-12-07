#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define lim 1000

struct list
{
    int val;
    int *parent;
};

struct list ls[lim];

void error();
void use();
void gen();
void save();
void load();

char inp[5], snum[2100], nume[5];
const char
zro[5]={'\0', '\0', '\0', '\0', '\0'},
cmd1[5]="exit",
cmd2[5]="help",
cmd3[5]="arot",
cmd4[5]="anod",
cmd5[5]="ansi",
cmd6[5]="save",
cmd7[5]="load";
int
mem[lim],
x[8],
y[8];
int ctrl=0;

int main(int argc, char *argv[])
{
    int init, rootb=0, nodeb=0, nv=0, nr=0, ctemp;
    for (init=0;init<lim-1;init++)
    {
        mem[init]=-998;
    }
    init=0;
    while (init==0)
    {
        printf(">>> ");
        int i=0, k=0/*, j*/;
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
                        ls[ctrl].val=nv;
                        ctrl++;
                        rootb=1;
                        printf("***\nAdded root with value %d.\n***\n", nv);
                    }
                    else error(2);
                } else if (!strcmp(inp, cmd4))
                {
                    if (nodeb<2)
                    {
                        printf("node value> ");
                        scanf("%d", &nv);
                        printf("parent node value> ");
                        scanf("%d", &nr);

                        for (ctemp=0;ctemp<lim;ctemp++)
                        {
                            if (ls[ctemp].val==nr)
                            {
                                ls[ctrl].val=nv;
                                ls[ctrl].parent=&ls[ctemp].val;
                                ctrl++;
                            }
                        }


                    }
                    else error(5);
                } else if (!strcmp(inp, cmd6))
                {
                    save();
                } else if (!strcmp(inp, cmd7))
                {
                    load();
                }
                /*else*//* if (!strcmp(inp, cmd5))
                        {
                            int x=0, tst;
                            printf("node value> ");
                            scanf("%d", &nv);
                            printf("sibling node value> ");
                            scanf("%d", &nr);
                            for (temp=4;temp<lim-1;temp+=3)
                            {
                                if (mem[temp]==nr&&mem[temp-1]==)
                                {
                                    if (tst!=&mem[temp]){
                                    mem[ch+3]=mem[temp-1];
                                    mem[nch+3]=nv;
                                    mem[ch3+3]=&mem[temp];
                                    tst=&mem[nch];}
                                    ch+=3;
                                    nch+=3;
                                    ch3+=3;
                                    x=1;
                                }
                            }
                            if (x==0)
                                error(4);
                                else {
                                printf("***\nAdded node with value %d.\n***\n", nv);
                                x=0;
                            }
                        }*/
    }
    for (init=0;init<ctrl;init++)
    {
        /*sprintf(snum, " ",ls[init].val);*/

        /*strcat(snum, "\n");
        fputs(snum, fp);*/
        /*itoa(ls[init].val,nume,10);*/
        /*strcat(snum, nume);
        strcat(snum, "\n");
        puts(snum);*/
    }
    for (init=0;init<ctrl;init++)
    {
        printf("%d   ", ls[init].val);
        printf("%x\n", ls[init].parent);
    }
    /*printf("aaa%daaa", ex);*/
    printf("bbb%dbbb", ls[0].val);

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
        case 4:
        {
            printf("***\nERROR Couldn't find selected sibling node.\n***\n");
            break;
        }
        case 5:
        {
            printf("***\nERROR maximum 2 nodes allowed\n***\n");
            break;
        }
    }
}
void use()
{
    printf("***\nUse:\n'arot' for adding root\n'anod' for adding new node with value with selected parent\n'ansi' for adding new node with selected sibling\n'show' to show tree\n'save' to save into selected text file\n'load' to load from selected text file\n'help' for help\n'exit' to exit program\n***\n");
}
void save()
{
    FILE  *fp;
    int i;

    if((fp=fopen("data.dat", "wb"))==NULL)
    {
        printf("Error while opening file.\n");
        return;
    }

    for(i=0; i<ctrl; i++)
        if(ls[i].val)
            if(fwrite(&ls[i], sizeof(struct list), 1, fp)!=1)
                printf("Error while writing file.\n");

    fclose(fp);
}
void load()
{
    FILE  *fp;
    int i;

    if((fp=fopen("data.dat", "wb"))==NULL)
    {
        printf("Error while opening file.\n");
        return;
    }

    /*init_list();*/
    for(i=0; i<ctrl; i++)
        if(ls[i].val)
            if(fread(&ls[i], sizeof(struct list), 1, fp)!=1)
            {
                if(feof(fp)) break;
                    printf("Error while writing file.\n");
            }

    fclose(fp);
}
