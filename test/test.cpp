#include<cstdlib>
#include<cstdio>
#include<ctime>

int main()
{
    for(int T=1;T<=10000;T++){
        system("E:\\ACMER\\test\\random.exe");
        double st=clock();
        system("E:\\ACMER\\test\\sol.exe");
        double ed=clock();
        system("E:\\ACMER\\test\\ans.exe");
        if(system("fc E:\\ACMER\\test\\in.txt E:\\ACMER\\test\\out.txt")){
            puts("Wrong Answer");
            system("pause");
            return 0;
        }
        else{
            printf("Accepted , test# %i time: %0.1lfms\n",T,ed-st);
        }
    }
    return 0;
}