//Copyright (c) 2007-2008, Marton Anka
//
//Permission is hereby granted, free of charge, to any person obtaining a 
//copy of this software and associated documentation files (the "Software"), 
//to deal in the Software without restriction, including without limitation 
//the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//and/or sell copies of the Software, and to permit persons to whom the 
//Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included 
//in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
//OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
//THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
//FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
//IN THE SOFTWARE.

#ifdef _M_IX86
#define _M_IX86_X64
#elif defined _M_X64
#define _M_IX86_X64
#endif

struct HOOK_INFO
{
    PVOID *ppSystemFunction;    // pointer to pointer to function to be hooked
    PVOID pHookFunction;        // hook function
    ULONG extraInstrucions;     // additional instructions to be rewritten with OVERWRITE_BYTE
    ULONG bytesRewritten;       // number of bytes, overwritten with OVERWRITE_BYTE
    PVOID pFunBodyAfterJump;    // pointer to function body after jump
    BOOL bHookSetSuccessfully;  // hook setting status

    // allowed to be rewritten with MHOOK_OVERWRITE_BYTE range
    PVOID pAllowedForPatchRangeStart;
    PVOID pAllowedForPatchRangeEnd;

};

// cmake debug flag
#ifdef _DEBUG
#define MHOOK_OVERWRITE_BYTE 0xF4 // hlt
#else
#define MHOOK_OVERWRITE_BYTE 0xCC // int3
#endif

#define MHOOK_EXTRA_INSTRUCTIONS_MAX ULONG_MAX

// returns number of successfully set hooks
int Mhook_SetHookEx(HOOK_INFO* hooks, int hookCount);
BOOL Mhook_SetHook(PVOID *ppSystemFunction, PVOID pHookFunction);
int Mhook_UnhookEx(PVOID** hooks, int hookCount);
BOOL Mhook_Unhook(PVOID *ppHookedFunction);

// set hook on function with structure like this:
//      xor r8d, r8d        ; first instruction less then MHOOK_JMPSIZE
//      jmp [some addr]     ; second instruction common jump
BOOL Mhook_SetHookWithJump(PVOID *ppSystemFunction, PVOID pHookFunction);