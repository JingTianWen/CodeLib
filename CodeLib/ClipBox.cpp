#include "stdafx.h"
#include "ClipBox.h"

void useClipCorner(osg::Node *node, const osg::Vec3 &ps, const osg::Vec3 &pe, int cornerIndex)
{
	osg::Plane planeX(osg::Vec3d(pe.x() - ps.x(), 0, 0), ps);
	planeX.makeUnitLength();
	auto cpX = make_ref(new osg::ClipPlane);
	cpX->setClipPlane(planeX);
	cpX->setClipPlaneNum(cornerIndex * 3 + 0);
	node->getOrCreateStateSet()->setAttributeAndModes(
		cpX, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE | osg::StateAttribute::PROTECTED
	);

	osg::Plane planeY(osg::Vec3d(0, pe.y() - ps.y(), 0), ps);
	planeY.makeUnitLength();
	auto cpY = make_ref(new osg::ClipPlane);
	cpY->setClipPlane(planeY);
	cpY->setClipPlaneNum(cornerIndex * 3 + 1);
	node->getOrCreateStateSet()->setAttributeAndModes(
		cpY, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE | osg::StateAttribute::PROTECTED
	);

	osg::Plane planeZ(osg::Vec3d(0, 0, pe.z() - ps.z()), ps);
	planeZ.makeUnitLength();
	auto cpZ = make_ref(new osg::ClipPlane);
	cpZ->setClipPlane(planeZ);
	cpZ->setClipPlaneNum(cornerIndex * 3 + 2);
	node->getOrCreateStateSet()->setAttributeAndModes(
		cpZ, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE | osg::StateAttribute::PROTECTED
	);
}

void useClipBox(osg::Node* node, const osg::Vec3& p1, const osg::Vec3& p2)
{
	useClipCorner(node, p1, p2, 0);
	useClipCorner(node, p2, p1, 1);
}