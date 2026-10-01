// cl: /O1 /arch:SSE /MD
// ?Rva000812E1Scale@@YAXPAM@Z @0x000812E1 67B
// Evidence: cdecl ret 1 arg ptr to 4 floats from caller 0x000812C4 push eax call pop ecx; movss mulss x4 by float at VA 0x00BC7078; unlock lane.
extern float g_00BC7078;
void __cdecl Rva000812E1Scale(float *v)
{
    float s = g_00BC7078;
    v[0] *= s;
    v[1] *= s;
    v[2] *= s;
    v[3] *= s;
}
