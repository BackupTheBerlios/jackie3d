#if !defined(JACKIE_JACKIEFACADEDELEGATE_HPP)
#define JACKIE_JACKIEFACADEDELEGATE_HPP

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
#include "jackiefacade.hpp"

namespace jackie {

using namespace jki;

class JackieFacadeDelegate : public JackieFacade
{
private:
public:
	JackieFacadeDelegate();
	virtual ~JackieFacadeDelegate();
	virtual JtToken	Declare(const JtToken name, const JtToken declaration);
	virtual JtVoid	Begin(const JtToken name);
	virtual JtVoid	End();
	virtual JtVoid	FrameBegin(const JtInt32 frame);
	virtual JtVoid	FrameEnd();
	virtual JtVoid	WorldBegin();
	virtual JtVoid	WorldEnd();

	virtual JtVoid	Format(const JtInt32 xres, const JtInt32 yres, const JtFloat aspect);
	//virtual JtVoid	FrameAspectRatio(const JtFloat aspect);
	virtual JtVoid	ScreenWindow(const JtFloat x, const JtFloat y,
			const JtFloat bottom, const JtFloat top);
	virtual JtVoid	CropWindow(const JtFloat xmin, const JtFloat xmax,
			const JtFloat ymin, const JtFloat ymax);
	// has extra parameters
	virtual JtVoid	Projection(const JtToken type);
	//virtual JtVoid	Clipping(const JtFloat hither, const JtFloat yon);
	//virtual JtVoid	ClippingPlane(const JtFloat x, const JtFloat y, const JtFloat z,
	//		const JtFloat nx, const JtFloat ny, const JtFloat nz);
	virtual JtVoid	Shutter(const JtToken type, const JtFloat min, const JtFloat max);

	virtual JtVoid	PixelVariance(const JtFloat variation);
	//virtual JtVoid	PixelSamples(const JtFloat xsamples, const JtFloat ysamples);
	virtual JtVoid	PixelFilter(const JtToken type, const JtFloat xwidth, const JtFloat ywidth);
	//virtual JtVoid	Exposure(const JtFloat gain, const JtFloat gamma);
	//virtual JtVoid	Imager(const JtToken name);
	//virtual JtVoid	Quantize(const JtToken name, const JtInt32 one,
	//		RtInt min, RtInt max, const JtFloat ampl);
	//virtual JtVoid	Display(const JtToken name, const JtToken type, const JtToken mode,
	//		const JtParmList parms);

	//virtual JtVoid	Hider(const JtToken type);
	virtual JtVoid	ColorSamples(const JtInt32 n, const JtFloat nRGB[], const JtFloat RGBn[]);
	//virtual JtVoid	RelativeDetail(const JtFloat relativedetail);
	// has extra parameters
	virtual JtVoid	Option(const JtToken name);

	virtual JtVoid	AttributeBegin();
	virtual JtVoid	AttributeEnd();
	virtual JtVoid	Color(const JtSpectrum color);
	virtual JtVoid	Opacity(const JtSpectrum opacity);
	//virtual JtVoid	TextureCoordinates(const JtFloat s1, const JtFloat t1,
	//		const JtFloat s2, const JtFloat t2,
	//		const JtFloat s3, const JtFloat t3,
	//		const JtFloat s4, const JtFloat t4);

	// has extra parameters
	//virtual JtLightHandle LightSource(const JtToken name);
	// has extra parameters
	//virtual JtLightHandle	AreaLightSource(const JtToken name);

	//virtual JtVoid	Illuminate(JtLightHandle light, const JtBoolean onoff);
	// has extra parameters
	virtual JtVoid	Surface(const JtToken type);
	// has extra parameters
	//virtual JtVoid	Atmosphere(const JtToken type);
	// has extra parameters
	//virtual JtVoid	Interior(const JtToken type);
	// has extra parameters
	//virtual JtVoid	Exterior(const JtToken type);
	//virtual JtVoid	ShadingRate(RtFloat size);
	//virtual JtVoid	ShadingInterpolation(RtToken type);
	//virtual JtVoid	Matte(const JtBoolean onoff);

	//virtual JtVoid	Bound(const JtBound bound);
	//virtual JtVoid	Detail(const JtBound bound);
	//virtual JtVoid	DetailRange(....);
	//virtual JtVoid	GeometricApproximation(....);
	//virtual JtVoid	Orientation(const JtToken orientation);
	//virtual JtVoid	ReverseOrientation();
	//virtual JtVoid	Sides(const JtInt32 sides);

	virtual JtVoid	Identity();
	virtual JtVoid	Transform(const JtMatrix transform);
	virtual JtVoid	ConcatTransform(const JtMatrix transform);
	virtual JtVoid	Perspective(const JtFloat fov);
	virtual JtVoid	Translate(const JtFloat dx, const JtFloat dy, const JtFloat dz);
	virtual JtVoid	Rotate(const JtFloat angle, const JtFloat dx,
			const JtFloat dy, const JtFloat dz);
	virtual JtVoid	Scale(const JtFloat sx, const JtFloat sy, const JtFloat sz);
	//virtual JtVoid	Skew(const JtFloat angle, const JtFloat dx1,
	//		const JtFloat dy1, const JtFloat dz1,
	//		const JtFloat dx2, const JtFloat dy2, const JtFloat dz2);
	//virtual JtVoid	Deformation(const JtToken type);
	//virtual JtVoid	Displacement(const JtToken type);
	//virtual JtVoid	CoordinateSystem(const JtToken space);
	//virtual JtVoid	CoordSysTransform(const JtToken space);
	//		TransformPoints(....);
	virtual JtVoid	TransformBegin();
	virtual JtVoid	TransformEnd();

	// has extra parameters
	virtual JtVoid	Attribute(const JtToken type);

	// has extra parameters
	virtual JtVoid	Sphere(const JtFloat radius,
			const JtFloat zmin, const JtFloat zmax, const JtFloat tmax);
	//...and many more...

	//virtual JtVoid	SolidBegin(const JtToken operation);
	//virtual JtVoid	SolidEnd();
	virtual JtObjectHandle ObjectBegin();
	virtual JtVoid	ObjectEnd();
	virtual JtVoid	ObjectInstance(const JtObjectHandle object);
	virtual JtVoid	MotionBegin(const JtInt32 n, const JtFloat times[]);
	virtual JtVoid	MotionEnd();

	//virtual JtVoid	MakeTexture(const JtToken inputfilename, const JtToken outputfilename,
	//		JkToken swrap, JkToken twrap, const JtToken filtertype,
	//		const JtFloat swidth, const JtFloat twidth);
	//virtual JtVoid	MakeBump(....);
	//...other...

	//virtual JtVoid	ArchiveRecord(const JtToken type, const JtToken format,
	//		const JtParmList parms);
	//virtual JtVoid	ReadArchive(const JtToken name, ....);

	// Error handling is done using exceptions
};

} // end namespace jackie

#endif // !defined(JACKIE_JACKIEFACADEDELEGATE_HPP)

