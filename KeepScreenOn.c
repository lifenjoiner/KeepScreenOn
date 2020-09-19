/*
http://blog.csdn.net/zjerryj/article/details/4618485
http://msdn.microsoft.com/en-us/library/windows/desktop/ms724947(v=vs.85).aspx
http://msdn.microsoft.com/en-us/windows/desktop/aa373208(v=vs.85).aspx

MS:
The system automatically detects activities such as local keyboard or mouse input, 
server activity, and changing window focus. Activities that are not automatically 
detected include disk or CPU activity and video display.

Calling SetThreadExecutionState without ES_CONTINUOUS simply resets the idle timer;
to keep the display or system in the working state, the thread must call 
SetThreadExecutionState periodically.

To run properly on a power-managed computer, applications such as fax servers, 
answering machines, backup agents, and network management applications must use 
both ES_SYSTEM_REQUIRED and ES_CONTINUOUS when they process events. Multimedia 
applications, such as video players and presentation applications, must use 
ES_DISPLAY_REQUIRED when they display video for long periods of time without user 
input. Applications such as word processors, spreadsheets, browsers, and games do 
not need to call SetThreadExecutionState.

*/

/*
EXECUTION_STATE WINAPI SetThreadExecutionState(
  _In_  EXECUTION_STATE esFlags
);
found in winbase.h, Kernel32.dll

ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED
found in winnt.h
*/

#include <windows.h>
#include <stdio.h>

void ResetIdleState(void) {
    /* reset the display and system idle timer */
    //SetThreadExecutionState(ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);
    SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);
}

int main(int argc, char **argv) {
    printf("I will keep screen on while I am running~");
    while (1) {
        ResetIdleState();
        Sleep(10000);
    }
}
