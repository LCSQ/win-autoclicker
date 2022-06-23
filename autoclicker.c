#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define AUTOCLICKER_PAUSE 0
#define AUTOCLICKER_EXIT 1

bool autoclicker (int i, INPUT *inputs, int n); //i means click interval for autoclicker // INPUT array pointer //n means number of elements in INPUT array
int main(void)
{
        int i;
        //LMB array
        INPUT inputs[2] = {};
        //press LMB DOWN
        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        //release LMB
        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
        //
        printf("# Use PAUSE key to pause Autoclicker while running\n");
        printf("# Use F8 key to exit Autoclicker while running\n");
        while (1) {
          while (1) {
            printf("## Enter click interval in milliseconds (0 to exit):\n");
            scanf("%d", &i);
            //exit program if input is 0
            if (i == 0) {
              exit(1);      
            }
            else if (i < 0) {
              printf("## Enter a number that is higher than 0 and lower than 2147483647\n");
              continue;
            }
            else {
              break;
            }
         }
        //if autoclicker returns 1 exit program
        if (autoclicker(i, inputs, 2)) {
          exit(1);
        }
}

}
bool autoclicker (int i, INPUT *inputs, int n)
{
      while (1) {
      Sleep(i);     //click interval
      SendInput(n, inputs, sizeof(INPUT));
      //PAUSE button send PAUSE
      if(GetAsyncKeyState(VK_PAUSE)) {         
        return AUTOCLICKER_PAUSE; //
      }
      //F8 button send EXIT
      if(GetAsyncKeyState(VK_F8)) {
        return AUTOCLICKER_EXIT;
      }
    }
}