#if !defined(JKI_JACKIEFACADE_HPP)
#define JKI_JACKIEFACADE_HPP
/***************************************************************************
 *  Copyright (C) 2004 by David Rigel García García                        *
 *  info@NO-SPAMjackie3d.org                                               *
 *                                                                         *
 *  All rights reserved.                                                   *
 *                                                                         *
 *  Redistribution and use in source and binary forms, with or without     *
 *  modification, are permitted provided that the following conditions     *
 *  are met:                                                               *
 *                                                                         *
 *      o Redistributions of source code must retain the above copyright   *
 *        notice, this list of conditions and the following disclaimer.    *
 *      o Redistributions in binary form must reproduce the above          *
 *        copyright notice, this list of conditions and the following      *
 *        disclaimer in the documentation and other materials provided     *
 *        with the distribution.                                           *
 *      o None of the names of its contributors may be used to             *
 *        endorse or promote products derived from this software without   *
 *        specific prior written permission.                               *
 *                                                                         *
 *  THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     *
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. *
 *  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,      *
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED     *
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, *
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF  *
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 *  DAMAGE.                                                                *
 ***************************************************************************/

// Change this definition in case there's a namespace collision
//#define jki jki_37567395

// Data Types such as JtInt32, JtInt64, etc.
#include "jackieint.hpp"

namespace jki {  ///< JacKie Interface

/*! \file jackiefacade.hpp
 * \brief Jackie rendering engine external interface.
 *
 * Jackie has an API similar to that of RenderMAN ver 3.2.
 * We must keep it as implementation-independent as possible.
 * \warning Not thread safe! (neither RMAN is).
 */

// Tokens, Strings
typedef char *		JtToken;

// Radiometry
typedef JtFloat		JtSpectrum[3];

// Algebra
typedef JtFloat		JtVector[3];
typedef JtFloat		JtPoint[3];
typedef JtFloat		JtNormal[3];
typedef JtFloat		JtMatrix[4][4];
typedef JtFloat		JtBound[6];

// Opaque types
//typedef void*		JtPointer;
#define JtVoid		void
typedef JtInt32		JtObjectHandle;
typedef JtInt32		JtLightHandle;

// Predefined values
#define JI_INFINITY (10e38)
#define JI_EPSILON  (1.0e-10)
//#define JI_NULL     ((JtPointer)0)
#define JI_TRUE		((JtBoolean)1)
#define JI_FALSE	((JtBoolean)0)


// forward declaration
class JackieFacade;

/** @return a fresh new instance of #JackieFacade */
extern JackieFacade *NewInstance();

/**
 @author David Rigel García García
*/
class JackieFacade {
protected:
	JackieFacade();
public:
	friend JackieFacade *NewInstance();
	//static JackieFacade *NewInstance();
	virtual ~JackieFacade();
	// methods here...
	virtual JtToken	Declare(const JtToken name, const JtToken declaration)=0;
	virtual JtVoid	ParamValue(const JtToken name, const JtFloat *value)=0;
	virtual JtVoid	ParamValue(const JtToken name, const JtInt32 *value)=0;
	virtual JtVoid	ParamValue(const JtToken name, const JtInt64 *value)=0;
	virtual JtVoid	ParamValue(const JtToken name, const JtToken value)=0;
	virtual JtVoid	Begin(const JtToken name)=0;
	virtual JtVoid	End()=0;
	virtual JtVoid	FrameBegin(const JtInt32 frame)=0;
	virtual JtVoid	FrameEnd()=0;
	virtual JtVoid	WorldBegin()=0;
	virtual JtVoid	WorldEnd()=0;

	virtual JtVoid	Format(const JtInt32 xres, const JtInt32 yres, const JtFloat aspect)=0;
	//virtual JtVoid	FrameAspectRatio(const JtFloat aspect)=0;
	virtual JtVoid	ScreenWindow(const JtFloat x, const JtFloat y,
			const JtFloat bottom, const JtFloat top)=0;
	virtual JtVoid	CropWindow(const JtFloat xmin, const JtFloat xmax,
			const JtFloat ymin, const JtFloat ymax)=0;
	// has extra parameters
	virtual JtVoid	Projection(const JtToken type)=0;
	//virtual JtVoid	Clipping(const JtFloat hither, const JtFloat yon)=0;
	//virtual JtVoid	ClippingPlane(const JtFloat x, const JtFloat y, const JtFloat z,
	//		const JtFloat nx, const JtFloat ny, const JtFloat nz)=0;
	virtual JtVoid	Shutter(const JtToken type, const JtFloat min, const JtFloat max)=0;

	virtual JtVoid	PixelVariance(const JtFloat variation);
	//virtual JtVoid	PixelSamples(const JtFloat xsamples, const JtFloat ysamples)=0;
	virtual JtVoid	PixelFilter(const JtToken type, const JtFloat xwidth, const JtFloat ywidth)=0;
	//virtual JtVoid	Exposure(const JtFloat gain, const JtFloat gamma)=0;
	//virtual JtVoid	Imager(const JtToken name, const JtParmList parms)=0;
	//virtual JtVoid	Quantize(const JtToken name, const JtInt32 one,
	//		RtInt min, RtInt max, const JtFloat ampl)=0;
	//virtual JtVoid	Display(const JtToken name, const JtToken type, const JtToken mode,
	//		const JtParmList parms)=0;

	//virtual JtVoid	Hider(const JtToken type, const JtParmList parms)=0;
	virtual JtVoid	ColorSamples(const JtInt32 n, const JtFloat nRGB[], const JtFloat RGBn[])=0;
	//virtual JtVoid	RelativeDetail(const JtFloat relativedetail)=0;
	// has extra parameters
	virtual JtVoid	Option(const JtToken name)=0;

	virtual JtVoid	AttributeBegin()=0;
	virtual JtVoid	AttributeEnd()=0;
	virtual JtVoid	Color(const JtSpectrum color)=0;
	virtual JtVoid	Opacity(const JtSpectrum opacity)=0;
	//virtual JtVoid	TextureCoordinates(const JtFloat s1, const JtFloat t1,
	//		const JtFloat s2, const JtFloat t2,
	//		const JtFloat s3, const JtFloat t3,
	//		const JtFloat s4, const JtFloat t4)=0;

	//virtual JtLightHandle LightSource(const JtToken name, const JtParmList parms)=0;
	//virtual JtLightHandle	AreaLightSource(const JtToken name, const JtParmList parms)=0;

	//virtual JtVoid	Illuminate(JtLightHandle light, const JtBoolean onoff)=0;
	// has extra parameters
	virtual JtVoid	Surface(const JtToken type)=0;
	//virtual JtVoid	Atmosphere(const JtToken type, const JtParmList parms)=0;
	//virtual JtVoid	Interior(const JtToken type, const JtParmList parms)=0;
	//virtual JtVoid	Exterior(const JtToken type, const JtParmList parms)=0;
	//virtual JtVoid	ShadingRate(RtFloat size)=0;
	//virtual JtVoid	ShadingInterpolation(RtToken type)=0;
	virtual JtVoid	Matte(const JtBoolean onoff)=0;

	virtual JtVoid	Bound(const JtBound bound)=0;
	//virtual JtVoid	Detail(const JtBound bound)=0;
	//virtual JtVoid	DetailRange(....)=0;
	//virtual JtVoid	GeometricApproximation(....)=0;
	virtual JtVoid	Orientation(const JtToken orientation)=0;
	//virtual JtVoid	ReverseOrientation()=0;
	//virtual JtVoid	Sides(const JtInt32 sides)=0;

	virtual JtVoid	Identity()=0;
	virtual JtVoid	Transform(const JtMatrix transform)=0;
	virtual JtVoid	ConcatTransform(const JtMatrix transform)=0;
	virtual JtVoid	Perspective(const JtFloat fov)=0;
	virtual JtVoid	Translate(const JtFloat dx, const JtFloat dy, const JtFloat dz)=0;
	virtual JtVoid	Rotate(const JtFloat angle, const JtFloat dx,
			const JtFloat dy, const JtFloat dz)=0;
	virtual JtVoid	Scale(const JtFloat sx, const JtFloat sy, const JtFloat sz)=0;
	//virtual JtVoid	Skew(const JtFloat angle, const JtFloat dx1,
	//		const JtFloat dy1, const JtFloat dz1,
	//		const JtFloat dx2, const JtFloat dy2, const JtFloat dz2)=0;
	//virtual JtVoid	Deformation(const JtToken type, const JtParmList parms)=0;
	//virtual JtVoid	Displacement(const JtToken type, const JtParmList parms)=0;
	//virtual JtVoid	CoordinateSystem(const JtToken space)=0;
	//virtual JtVoid	CoordSysTransform(const JtToken space)=0;
	//		TransformPoints(....)=0;
	virtual JtVoid	TransformBegin()=0;
	virtual JtVoid	TransformEnd()=0;
	// has extra parameters
	virtual JtVoid	Attribute(const JtToken type)=0;
	// has extra parameters
	virtual JtVoid	Sphere(const JtFloat radius,
			const JtFloat zmin, const JtFloat zmax, const JtFloat tmax)=0;
	//...and many more...

	//virtual JtVoid	SolidBegin(const JtToken operation);
	//virtual JtVoid	SolidEnd();
	virtual JtObjectHandle ObjectBegin()=0;
	virtual JtVoid	ObjectEnd()=0;
	virtual JtVoid	ObjectInstance(const JtObjectHandle object)=0;
	virtual JtVoid	MotionBegin(const JtInt32 n, const JtFloat times[])=0;
	virtual JtVoid	MotionEnd()=0;

	//virtual JtVoid	MakeTexture(const JtToken inputfilename, const JtToken outputfilename,
	//		JkToken swrap, JkToken twrap, const JtToken filtertype,
	//		const JtFloat swidth, const JtFloat twidth, const JtParmList parms)=0;
	//virtual JtVoid	MakeBump(....)=0;
	//...other...

	//virtual JtVoid	ArchiveRecord(const JtToken type, const JtToken format,
	//		const JtParmList parms)=0;
	//virtual JtVoid	ReadArchive(const JtToken name, ....)=0;

	// Error handling is done using exceptions
};


} // end namespace

#endif // !defined(JKI_JACKIEFACADE_HPP)
