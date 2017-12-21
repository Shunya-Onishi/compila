#include<stdio.h>
#include<string.h>

void boin(){

} 

void siin(){

}

int main(){
  char bun[1000];
  char c;
  printf("nyuryoku\n");
  
  fgets(bun, sizeof(bun), stdin);
  bun[strlen(bun)-1]='\0';

  printf("%s\n",bun);
  c = bun[1];
  printf("%s\n",c);
}
