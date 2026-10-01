// cl: /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/game/GameEngine/Include
// stlport

// Provenance: Open-BFME-1 game/GameEngine/Source/GameClient/VideoPlayerAddVideo.cpp
// (BFME1 byte-identical donor, b1 0x0081CF50 -> 0x00689FD0).  The donor's
// relative "../../Include/GameClient/Video.h" resolves only inside the
// submodule, so the include is spelled from the BFME2 include root and the
// path is given on the cl line above; the body is unchanged.
#include "GameClient/Video.h"
#include <vector>

// Retail VideoPlayer vtable 0x0112CCC0 slot 15 (+0x3c) points here.
// INI::parseVideoDefinition at 0x000C3480 calls this slot with its 28-byte
// Video record. The global table is also used by removeVideo and getVideo.
extern _STL::vector<Video> Rva0130B19CVideoTable;

class VideoPlayer
{
public:
    virtual void addVideo(Video *video);
};

void VideoPlayer::addVideo(Video *video)
{
    for (_STL::vector<Video>::iterator it = Rva0130B19CVideoTable.begin();
         it != Rva0130B19CVideoTable.end(); ++it)
    {
        if (it->m_internalName.compare(video->m_internalName) == 0)
        {
            *it = *video;
            return;
        }
    }

    Rva0130B19CVideoTable.push_back(*video);
}
