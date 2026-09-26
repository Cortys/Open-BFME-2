// cl: /O1 /MD
// ?Rva006053AD@@YAXPAD@Z, retail 0x006053AD, 42 bytes.
// Trims a backslash path to its parent in place: scans to NUL then back to
// the last backslash and truncates there. No donor; honest address name.
// Evidence: sole caller is FilePathGate::allow 0x00600AE5; callees none.
void Rva006053AD(char *p)
{
    char *e = p;
    if (*p == 0)
        return;
    while (*e != 0)
        ++e;
    while (e > p) {
        if (*(e - 1) == '\\')
            break;
        --e;
    }
    if (e == p)
        return;
    *(e - 1) = 0;
}
