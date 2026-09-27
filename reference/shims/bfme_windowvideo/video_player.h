#pragma once
// TU-scoped BFME2 override of reference/open-bfme-1/.../GameClient/video_player.h for window_video_manager.cpp.
// BFME2 retail calls VideoStreamInterface through its vtable:
//   +0x1C close()            (WindowVideo dtor 0x53F10E, playMovie 0x53F63D failure path)
//   +0x38 attach(VideoBuffer*) -> bool (playMovie 0x53F69E)
//   +0x3C getVideoBuffer()   (WindowVideo::getVideoBuffer 0x53F0BF, setWindowState 0x53F06C, init 0x53F165)
// The remaining slot names are placeholders for the (still unmatched) update/playMovie bodies.
#include "ascii_string.h"
class VideoBuffer {
public:
	int allocate(unsigned int w, unsigned int h);
	void close(void);
	unsigned int width(void);
	unsigned int height(void);
};
class VideoStreamInterface {
public:
	virtual void streamSlot00( void ) = 0;
	virtual void update( void ) = 0;
	virtual int isFrameReady( void ) = 0;
	virtual void frameDecompress( void ) = 0;
	virtual void frameRender( VideoBuffer *buffer ) = 0;
	virtual void frameNext( void ) = 0;
	virtual int frameStep( int mode ) = 0;
	virtual void close( void ) = 0;
	virtual int frameIndex( void ) = 0;
	virtual unsigned int width( void ) = 0;
	virtual unsigned int height( void ) = 0;
	virtual void streamSlot11( void ) = 0;
	virtual void streamSlot12( void ) = 0;
	virtual void streamSlot13( void ) = 0;
	virtual bool attach( VideoBuffer *buffer ) = 0;
	virtual VideoBuffer *getVideoBuffer( void ) = 0;
};
class VideoPlayerInterface { public: VideoStreamInterface* open(AsciiString); VideoStreamInterface* load(AsciiString); };
extern VideoPlayerInterface* TheVideoPlayer;
