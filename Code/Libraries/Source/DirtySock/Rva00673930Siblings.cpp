// cl: /DNDEBUG /MD /GX /Od /GZ /GS

// Three more bare tick-read op-table stubs of the shape retail holds at
// 0x00681790 (see commsrp.cpp): an /Od /GZ wrapper around the matched tick
// forwarder _Rva007FEA00 (0x0066AED0). The forced shape is a frame plus the
// call and the __RTC_CheckEsp probe, so these bytes are the source.

extern "C" {

void Rva007FEA00(void);

void Rva00673930(void)
{
	Rva007FEA00();
}

void Rva006832A0(void)
{
	Rva007FEA00();
}

void Rva00687940(void)
{
	Rva007FEA00();
}

}
