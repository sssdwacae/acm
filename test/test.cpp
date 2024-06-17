#include<cstdlib>
#include<cstdio>
#include<ctime>

int main()
{
    for(int T=1;T<=1000;T++){
        system("E:\\ACMER\\test\\radnom.exe");
        double st=clock();
        system("E:\\ACMER\\test\\sol.exe");
        double ed=clock();
        system("E:\\ACMER\\test\\ans.exe");
        if(system("fc E:\\ACMER\\test\\ansout.txt E:\\ACMER\\test\\solout.txt")){
            puts("Wrong Answer");
            system("pause");
            return 0;
        }
        else{
            printf("Accepted , test# %i time: %0.1lfms\n",T,ed-st);
        }
    }
    printf("Accepted All!");
    system("pause");
    return 0;
}