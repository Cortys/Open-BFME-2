// cl: /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/game/GameEngine/Include
// stlport

// Provenance: Open-BFME-1 game/GameEngine/Source/GameClient/VideoPlayerRemoveVideo.cpp
// (BFME1 byte-identical donor, b1 0x0081D2D0 -> 0x00689CE0).  The donor's
// relative "../../Include/GameClient/Video.h" resolves only inside the
// submodule, so the include is spelled from the BFME2 include root and the
// path is given on the cl line above; the body is unchanged.
#include "GameClient/Video.h"
#include <vector>

// Retail 0x0081CF40 uses the same global 28-byte Video table as the
// landed getVideo queries. The upstream removeVideo loop identifies the
// operation; BFME keeps this table globally rather than in the player.
// VideoPlayer vtable 0x0112CCC0 slot 16 (+0x40) points at this body.
// The existing VideoPlayer destructor installs that table; the neighboring
// slot 19 is the already matched VideoPlayer::getVideo(AsciiString).
extern _STL::vector<Video> Rva0130B19CVideoTable;

class VideoPlayer
{
public:
    virtual void removeVideo(Video *video);
};

void VideoPlayer::removeVideo(Video *video)
{
    for (_STL::vector<Video>::iterator it = Rva0130B19CVideoTable.begin();
         it != Rva0130B19CVideoTable.end(); ++it)
    {
        if (it->m_internalName.compare(video->m_internalName) == 0)
        {
            Rva0130B19CVideoTable.erase(it);
            return;
        }
    }
}
