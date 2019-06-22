/*
 * ====================== chunkKey.cpp =======================
 *                          -- tpr --
 *                                        CREATE -- 2019.03.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 *    Chunk "id":  (int)w + (int)h
 * ----------------------------
 */
#include "chunkKey.h"

//-------------------- C --------------------//
#include <cmath>

//-------------------- Engine --------------------//
#include "tprAssert.h"
#include "sectionKey.h"


//#include "tprDebug.h"


/* ===========================================================
 *                get_chunkIdx_in_section
 * -----------------------------------------------------------
 * 获得 目标chunk 在其 section 中的 idx [left-bottom]
 * ------
 * param: _mpos -- 任意 mapent 的 mpos
 */
size_t get_chunkIdx_in_section( const IntVec2 &_anyMPos ){

    IntVec2 mposOff = anyMPos_2_chunkMPos(_anyMPos) - anyMPos_2_sectionMPos(_anyMPos);
        tprAssert( (mposOff.x>=0) && (mposOff.y>=0) ); //- tmp
    int w = std::abs(mposOff.x)/ENTS_PER_CHUNK;
    int h = std::abs(mposOff.y)/ENTS_PER_CHUNK;
        tprAssert( (w>=0) && (w<CHUNKS_PER_SECTION) &&
                (h>=0) && (h<CHUNKS_PER_SECTION) ); //- tmp
    return (size_t)(h*CHUNKS_PER_SECTION + w);
}
