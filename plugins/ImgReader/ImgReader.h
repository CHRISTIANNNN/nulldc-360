#pragma once
//bleh stupid windoze header
#include "nullDC/types.h"
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef char TCHAR;
typedef string wstring;
typedef long long __int64;

#define BUILD 0
#define MINOR 0
#define MAJOR 1
extern emu_info emu;
extern wchar emu_name[512];
struct _setts
{
	bool PatchRegion;
	bool LoadDefaultImage;
	wchar DefaultImage[512];
	wchar LastImage[512];
};

extern _setts irsettings;
void SaveSettings();