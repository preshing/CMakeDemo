#ifdef _WIN32

#include <SDL.h>
#include "Context.h"

GLFuncTable glFuncTable;

//---------------------------------------------------------------------------
//  Fill in the glFuncTable function table on Win32
//  This lets us avoid having to link with opengl32.lib
//---------------------------------------------------------------------------
void GLFuncTable::initialize() {
#define GL_FUNC(retVal, name, args) { name = (retVal (GL_APIENTRY *)args) SDL_GL_GetProcAddress("gl" #name); assert(name); }
#include "Funcs.h"
#undef GL_FUNC
}

#endif // _WIN32
