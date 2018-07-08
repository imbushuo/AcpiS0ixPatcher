#pragma once

#ifdef __CC_ARM
//
// Older RVCT ARM compilers don't fully support #pragma pack and require __packed
// as a prefix for the structure.
//
#define PACKED  __packed
#else
#define PACKED
#endif

/**
Returns a 16-bit signature built from 2 ASCII characters.

This macro returns a 16-bit value built from the two ASCII characters specified
by A and B.

@param  A    The first ASCII character.
@param  B    The second ASCII character.

@return A 16-bit value built from the two ASCII characters specified by A and B.

**/
#define SIGNATURE_16(A, B)        ((A) | (B << 8))

/**
Returns a 32-bit signature built from 4 ASCII characters.

This macro returns a 32-bit value built from the four ASCII characters specified
by A, B, C, and D.

@param  A    The first ASCII character.
@param  B    The second ASCII character.
@param  C    The third ASCII character.
@param  D    The fourth ASCII character.

@return A 32-bit value built from the two ASCII characters specified by A, B,
C and D.

**/
#define SIGNATURE_32(A, B, C, D)  (SIGNATURE_16 (A, B) | (SIGNATURE_16 (C, D) << 16))

/**
Returns a 64-bit signature built from 8 ASCII characters.

This macro returns a 64-bit value built from the eight ASCII characters specified
by A, B, C, D, E, F, G,and H.

@param  A    The first ASCII character.
@param  B    The second ASCII character.
@param  C    The third ASCII character.
@param  D    The fourth ASCII character.
@param  E    The fifth ASCII character.
@param  F    The sixth ASCII character.
@param  G    The seventh ASCII character.
@param  H    The eighth ASCII character.

@return A 64-bit value built from the two ASCII characters specified by A, B,
C, D, E, F, G and H.

**/
#define SIGNATURE_64(A, B, C, D, E, F, G, H) \
    (SIGNATURE_32 (A, B, C, D) | ((UINT64) (SIGNATURE_32 (E, F, G, H)) << 32))
