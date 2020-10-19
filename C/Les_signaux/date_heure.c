
#include <signal.h>

void reveil( ) {
  system("date");
} 

int main() {
  signal(SIGALRM, &reveil);
  while(1) {
    alarm(5);
    pause();    
  }
} 
