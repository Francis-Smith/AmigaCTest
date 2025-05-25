#include "support/gcc8_c_support.h"
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <graphics/gfxbase.h>
#include <graphics/view.h>
#include <exec/execbase.h>
#include <graphics/gfxmacros.h>
#include <hardware/custom.h>
#include <hardware/dmabits.h>
#include <hardware/intbits.h>

#include "screen.hpp"
#include "screen2.hpp"

struct ExecBase *SysBase;
struct DosLibrary *DOSBase;

int main()
{
	warpmode(0);

	SysBase = *((struct ExecBase **)4UL);

	// used for printing
	DOSBase = (struct DosLibrary *)OpenLibrary((CONST_STRPTR) "dos.library", 0);
	if (!DOSBase)
		Exit(0);

	KPrintF("main");

	Delay(500);

	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		j += 1;
		j *= 5;
	}

	KPrintF("j=%d", j);

	Screen2 screen;
	screen.Init();
}