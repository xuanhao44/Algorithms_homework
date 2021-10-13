#include <stdio.h>
#include <stdlib.h>
int main(){
    while(1){
        system("data.exe>data.in");
        system("others.exe<data.in>others.out");
        system("self.exe<data.in>self.out");
        if(system("fc others.out self.out")){
            printf("Find the difference!\nThe in and out file is in the repos.\n");
			return 0;
        }
    }
}
