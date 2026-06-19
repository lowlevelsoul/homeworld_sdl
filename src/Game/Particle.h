/*=============================================================================
    Name    : particle.c
    Purpose : maintain and render particle systems

    Created 11/13/1997 by khent
    Copyright Relic Entertainment, Inc.  All rights reserved.
=============================================================================*/
#ifndef ___PARTICLE_H
#define ___PARTICLE_H

#include "tiPlatform.h"
#include "Color.h"
#include "Mesh.h"
#include "SpaceObj.h"
#include "texreg.h"
#include "Types.h"
#include "Vector.h"

TI_API void partFilter(bool_t on);

#ifdef HW_BUILD_FOR_DEBUGGING
#define PART_Debug
#define PART_Verbose    1
#else
#undef  PART_Debug
#define PART_Verbose    0
#endif

#define PART_NUM_ALTERNATES     128

#define PART_MONOSCALE          0x1
#define PART_ALPHA              0x2
#define PART_WORLDSPACE         0x4             //world space motion updating
#define PART_WORLDSPACEVELOCITY 0x8             //if the particle is in worldspace, use it's velocity in local space for heading

typedef enum {PART_POINTS, PART_CUBES, PART_LINES, PART_MESH, PART_BILLBOARD} particleType;

#define partTypeof(p)   ((pointSystem*)(p))->t
#define partNumberof(p) ((pointSystem*)(p))->n

#define PART_CYLINDER   1
#define PART_SPHERE     2

#define PART_SPECULAR        1
#define PART_STIPPLE         2
#define PART_NODEPTHWRITE    4
#define PART_ADDITIVE        8
#define PART_PSEUDOBILLBOARD 16
#define PART_TRUEBILLBOARD   32
#define PART_XYZSCALE        64
#define PART_NOCOLORSCHEME   0                  //particle has no definite color scheme

typedef char particleSystem;
typedef particleSystem *psysPtr;

#define PART_LOOPSTART  1
#define PART_LOOP       2

typedef struct
{
    trhandle    tex;        //== -1 if end, stay at last frame
    ubyte       uv[2][2];
#ifdef _X86_64
    ubyte       pad1[4];
#endif
    udword      flags;      //LOOPSTART = 1, LOOP = 2
#ifdef _X86_64
    udword       pad2;
#endif
} texAnim;

typedef struct
{
    meshdata* mesh;         //NULL = end of anim
    udword    flags;        //LOOPSTART = 1, LOOP = 2
} meshAnim;

//generic particle type.
//this is way too big
typedef struct
{
    //lifespan
    real32 lifespan;
    real32 waitspan;        //this decs before lifespan
    //velocity
    real32 velLOF;
    real32 velR;
    real32 deltaVelLOF;
    real32 deltaVelR;
    //position
    vector rvec;
    vector position;        //next to icolor, better for interleaved vertex lists
    //appearance
    real32 icolor[4];
    real32 deltaColor[4];
    real32 scale;
    real32 deltaScale;
    bool8  lit;
    real32 illum;
    real32 deltaIllum;
    //line-specifics
    real32 length;
    real32 deltaLength;
    //sprite-specifics
    trhandle tex;
    real32 rot;
    real32 deltaRot;

    //worldspace particle stuff
    //render only uses position, so only
    //creationhelper and updatesystem need this
    vector wVel;        //LOFvel + Rvel
    vector wAccel;      //LOFaccel + Rvel

    //color bias
    real32 bias[3];

    //animating sprite stuff
    void* tstruct;
    real32 rate;
    bool8 loop;
    real32 currentFrame;

    //mesh thingz
    real32 tumble[3];
    real32 deltaTumble[3];
    meshdata *mesh;
    real32 meshRate;
    void* mstruct;
    real32 meshFrame;
    real32 exponent;
    ubyte colorScheme;              //0-7 or PART_NOCOLORSCHEME if none
    sbyte loopCount;

    //flags
    udword flags;
} particle;

//common params to all particles in a point system
typedef struct
{
    particleType t;                 //common among all particle system types
    udword flags;
    bool8 isAlive;                  //so's this
    uword n;
    real32 lastUpdated;             //task time it was last updated
    real32 drag;
    real32 ang, angDelta;           //end of common data
} pointSystem;

//common params to all particles in a cube system
typedef struct
{
    particleType t;
    udword flags;
    bool8 isAlive;
    uword n;
    real32 lastUpdated;             //task time it was last updated
    real32 drag;
    real32 ang, angDelta;
} cubeSystem;

//common params to all particles in a line system
typedef struct
{
    particleType t;
    udword flags;
    bool8 isAlive;
    uword n;
    real32 lastUpdated;             //task time it was last updated
    real32 drag;
    real32 ang, angDelta;
} lineSystem;

//common params to all particles in a mesh system
typedef struct
{
    particleType t;
    udword flags;
    bool8 isAlive;
    uword n;
    real32 lastUpdated;             //task time it was last updated
    real32 drag;
    real32 ang, angDelta;
    trhandle tex;
    matrix* partMat;
    vector  partPos;
} meshSystem;

//common params to all particles in a billboarded texture system
typedef struct
{
    particleType t;
    udword flags;
    bool8 isAlive;
    uword n;
    real32 lastUpdated;             //task time it was last updated
    real32 drag;
    real32 ang, angDelta;
    //if a particle's own trhandle == 0, it grabs from the
    //global setting for the system (right here)
    trhandle tex;
    udword uv[2][2];
    vector position;
    vector lofvec;
    uword slices;
    matrix* partMat;
} billSystem;

extern matrix partEffectOwnerSystem;
extern vector partEffectOwnerPosition;
extern color  partEffectColor;
extern real32 partNLips;

//functions
TI_API void partStartup(void);
TI_API void partShutdown(void);

TI_API void partSetDefaults(void);
TI_API void partRenderSystem(psysPtr psys);
bool8 partUpdateSystem(psysPtr psys, real32 dt, vector* velvec);    //TRUE if system died, FALSE otherwise
TI_API psysPtr partCreateSystem(particleType t, udword n);
TI_API psysPtr partCreateSystemWithDelta(particleType t, udword n, udword delta);
TI_API psysPtr partCreateSphericalSystem(particleType t, udword n);
TI_API psysPtr partCreateSphericalSystemWithDelta(particleType t, udword n, udword delta);
TI_API udword partHeaderSize(psysPtr psys);

//system modifiers
TI_API void partModifyTumble(psysPtr psys, vector* t);
TI_API void partModifyDeltaTumble(psysPtr psys, vector* dt);
TI_API void partModifyExponent(psysPtr psys, real32 exponent);

TI_API void partModifyDrag(psysPtr psys, real32 d);
TI_API void partModifyMesh(psysPtr psys, meshdata *mesh);
TI_API void partModifyLighting(psysPtr psys, bool_t lit);
TI_API void partModifyIllum(psysPtr psys, real32 illum);
TI_API void partModifyDeltaIllum(psysPtr psys, real32 deltaIllum);
void partModifyTexture(psysPtr psys, trhandle tex,
                       udword u0, udword v0, udword u1, udword v1);
TI_API void partModifyScale(psysPtr psys, real32 s);
TI_API void partModifyDeltaScale(psysPtr psys, real32 d);
TI_API void partModifyDeltaLength(psysPtr psys, real32 d);
TI_API void partModifyLifespan(psysPtr psys, real32 l);
TI_API void partModifyLength(psysPtr psys, real32 l);
TI_API void partModifyVelLOF(psysPtr psys, real32 v);
TI_API void partModifyDeltaVelLOF(psysPtr psys, real32 d);
TI_API void partModifyVelR(psysPtr psys, real32 v);
TI_API void partModifyDeltaVelR(psysPtr psys, real32 d);
TI_API void partModifyDeltaColorC(psysPtr psys, color c);
TI_API void partModifyColorC(psysPtr psys, color c);
void partModifyColor(psysPtr psys,
                     real32 r, real32 g, real32 b, real32 a);
void partModifyDeltaColor(psysPtr psys,
                          real32 dr, real32 dg, real32 db, real32 da);
TI_API void partModifyColorBias(psysPtr psys, real32 rb, real32 gb, real32 bb);
TI_API void partModifyAddColor(psysPtr psys, color c);

//for billboard systems
TI_API void partModifyAnimation(psysPtr psys, void* tstruct);
TI_API void partModifyFramerate(psysPtr psys, real32 rate);
TI_API void partModifyLoopFlag(psysPtr psys, bool8 willLoop);
TI_API void partModifyBillPosition(psysPtr psys, vector* pos);

//flag modifiers
TI_API void partModifySpecular(psysPtr psys, bool_t spec);
TI_API void partModifyStipple(psysPtr psys, bool_t stip);
TI_API void partModifyNoDepthWrite(psysPtr psys, bool_t noWrite);
TI_API void partModifyAdditiveBlends(psysPtr psys, bool_t add);
TI_API void partModifyPseudoBillboard(psysPtr psys, bool_t bill);
TI_API void partModifyTrueBillboard(psysPtr psys, bool_t bill);
//0 - normal, 1 - additive, 2 - stipple
TI_API void partModifyAlphaMode(psysPtr psys, udword mode);
TI_API void partModifyColorScheme(psysPtr psys, sdword colorScheme);

//callbacks
//delta values are assumed to be + or - the given delta,
//unless the given is -ve which implies a strictly -ve delta

TI_API void partSetIsWorldspace(bool8 isWorldspace);
TI_API void partSetVelocityInWorldSpace(bool8 isLocalSpace);
TI_API void partSetWorldVel(vector* worldVel);

//these only make sense for billboard systems
TI_API void partSetAnimation(void* tstruct);
TI_API void partSetFramerate(real32 rate);
TI_API void partSetLoopFlag(bool8 willLoop);
TI_API void partSetStartFrame(udword frame);

TI_API void partSetCoordSys(matrix* mat);

void partSetSlices(udword s);       //for circles

void partSetPosition(vector *pos);  //used by PART_BILLBOARD systems

void partSetMeshdata(meshdata *m);  //used by PART_MESH systems
//used by PART_BILLBOARD systems
TI_API void partSetTrHandle(trhandle t, udword u0, udword v0, udword u1, udword v1);

//PART_MESH systems use this, vals are angles in radians (default 0,0,0)
TI_API void partSetTumble(real32 x, real32 y, real32 z);
TI_API void partSetTumbleDist(real32 dx, real32 dy, real32 dz);
void partSetDeltaTumble(real32 x, real32 y, real32 z);          //rads/s
TI_API void partSetDeltaTumbleDist(real32 dx, real32 dy, real32 dz);

TI_API void partSetExponent(real32 exponent);

//morphing stuff
TI_API void partSetMorph(void* mstruct);
TI_API void partSetMorphFramerate(real32 meshRate);
TI_API void partSetMorphLoopCount(sdword loopCount);
TI_API void partSetMeshStartFrame(real32 frame);
TI_API void partModifyMorph(psysPtr psys, void* mstruct);
TI_API void partModifyMorphFramerate(psysPtr psys, real32 meshRate);

TI_API void partSetDrag(real32 n);
TI_API void partSetXYZScale(real32 x, real32 y, real32 z);
void partSetScale(real32 n);        //scale refers to linewidth with PART_LINES
TI_API void partSetScaleDist(real32 d);
TI_API void partSetDeltaScale(real32 n);
TI_API void partSetDeltaScaleDist(real32 d);
void partSetOffsetLOF(real32 n);        //starting offset along lof
void partSetOffsetR(real32 n);          //starting offset along r
void partSetOffsetTheta(real32 n);      //ditto
void partSetOffsetArray(vector *offsets);//array of offset positions
void partSetDeltaLOF(real32 n);         //modifies offsetLOF (nothing to do with velocity)
TI_API void partSetDeltaLOFDist(real32 n);
TI_API void partSetDeltaR(real32 r, real32 t);
TI_API void partSetDeltaRDist(real32 r, real32 t);
void partSetVelLOF(real32 v);           //velocity along lof
void partSetVelLOFDist(real32 d);       //distribution of vel along lof
void partSetVelR(real32 v);             //velocity along r
void partSetVelRDist(real32 d);         //velRDist
void partSetDeltaVelLOF(real32 d);      //acceleration
TI_API void partSetDeltaVelLOFDist(real32 d);
TI_API void partSetDeltaVelR(real32 v);
TI_API void partSetDeltaVelRDist(real32 v);

//angles in radians
TI_API void partSetAng(real32 a);
TI_API void partSetAngDist(real32 d);
TI_API void partSetAngDelta(real32 d);
TI_API void partSetAngDeltaDist(real32 d);

TI_API void partSetColorA(real32 r, real32 g, real32 b, real32 a);
TI_API void partSetColor(real32 r, real32 g, real32 b);
TI_API void partSetColorDist(real32 r, real32 g, real32 b);
TI_API void partSetColorADist(real32 r, real32 g, real32 b, real32 a);
TI_API void partSetDeltaColor(real32 r, real32 g, real32 b);
TI_API void partSetDeltaColorDist(real32 r, real32 g, real32 b);
TI_API void partSetDeltaColorA(real32 r, real32 g, real32 b, real32 a);
TI_API void partSetDeltaColorADist(real32 r, real32 g, real32 b, real32 a);

TI_API void partSetLighting(bool_t l);
TI_API void partSetIllum(real32 n);
TI_API void partSetIllumDist(real32 n);
TI_API void partSetDeltaIllum(real32 n);
TI_API void partSetDeltaIllumDist(real32 n);
TI_API void partSetLifespan(real32 t);
TI_API void partSetLifespanDist(real32 d);
TI_API void partSetWaitspan(real32 t);
TI_API void partSetWaitspanDist(real32 d);

TI_API void partSetLength(real32 l);
TI_API void partSetLengthDist(real32 d);
TI_API void partSetDeltaLength(real32 d);
TI_API void partSetDeltaLengthDist(real32 d);

TI_API void partSetColorBias(real32 rb, real32 gb, real32 bb);
TI_API void partSetColorBiasDist(real32 drb, real32 dgb, real32 dbb);

TI_API void partSetSpecular(bool_t spec);
TI_API void partSetStipple(bool_t stip);
TI_API void partSetNoDepthWrite(bool_t noWrite);
TI_API void partSetAdditiveBlends(bool_t add);
TI_API void partSetPseudoBillboard(bool_t bill);
TI_API void partSetTrueBillboard(bool_t bill);
void partSetAlphaMode(udword mode);     //0 - normal, 1 - additive, 2 - stippled
TI_API void partSetColorScheme(sdword colorScheme);

void partCreateCallbackSet(void (*function)(sdword userValue, ubyte *userData), sdword userValue, ubyte *userData);

TI_API void partCircleSolid3(vector* centre, real32 radius, sdword nSlices, color c);

#endif
