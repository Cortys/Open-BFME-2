// ?getDayOfWeek@AptDate@@QAEHHHH@Z
// partial score=0.94 date=2026-09-27
// cl: /O2 /MD
// Banked near match: target getDayOfWeek6F4290+450; compiler emits454 bytes.
// Donor APT0.19.03 Xbox final supplies identity. Target floor thunk629940
// resolves through IAT BBA570 to msvcr71.dll!floor. Helper6F4080 is already
// recovered under ?isLeapYear@@YG_NH@Z; this helper spelling is donor-derived.
// Trial-only mappings: ?dateIsYearLeap@AptDate@@QAE_NH@Z ->6F4080;
// _floor ->629940. No new pins were landed for this partial.
// Remaining delta: stack temporaries and final arithmetic/register scheduling.
extern "C" double __cdecl floor(double);
extern "C" int __cdecl abs(int);
#pragma intrinsic(abs)
class AptDate {
public:
    bool dateIsYearLeap(int year);
    int getDayOfWeek(int year,int month,int day);
};
bool AptDate::dateIsYearLeap(int year)
{
    bool result = false;
    if (year % 4 == 0) {
        if (year % 100 != 0) return true;
        result = year % 400 == 0;
    }
    return result;
}
int AptDate::getDayOfWeek(int year,int month,int day)
{
    int century=year/100;
    int remainder=year%100;
    int anchor=month+1;
    int aCentury[4] = {3,2,0,5};
    int nCentury;
    if (century<19) nCentury=4-abs(century-19)%4;
    else nCentury=abs(century-19)%4;
    nCentury=aCentury[nCentury];
    int base=year-remainder;
    if (month==1) anchor=28+(dateIsYearLeap(year)?1:0);
    else if (month%2==0) {
        if (month==8) anchor=5;
        else if (month==4) anchor=9;
        else if (month==6) anchor=11;
        else if (month==10) anchor=7;
        else if (month==2) anchor=7;
        else if (month==0) anchor=31+(dateIsYearLeap(year)?1:0);
    }
    if (nCentury<0 || anchor<0) return -1;
    if (anchor>day) day=anchor-(anchor-day)%7+7;
    return (((int)floor((year-base)*0.25f)-base+nCentury+year)%7+(day-anchor)%7)%7;
}
