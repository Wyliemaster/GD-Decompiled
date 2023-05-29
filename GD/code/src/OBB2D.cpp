#include "../headers/includes.h"

void OBB2D::calculateOBBWithCenter(cocos2d::CCPoint center, float width, float height, float rotationAngle)
{

    m_obCenter = center;

    float cosAngle = cos(rotationAngle);
    float sinAngle = sin(rotationAngle);

    cocos2d::CCPoint horizontalAxis = cocos2d::CCPoint(cosAngle, sinAngle) * width * 0.5;
    cocos2d::CCPoint verticalAxis = cocos2d::CCPoint(-sinAngle, cosAngle) * height * 0.5;

    m_obVertexBottomLeft = center - horizontalAxis - verticalAxis;
    m_obVertexBottomRight = center + horizontalAxis - verticalAxis;
    m_obVertexTopRight = center + horizontalAxis + verticalAxis;
    m_obVertexTopLeft = center - horizontalAxis + verticalAxis;

    computeAxes();
    orderCorners();
}

// I have no idea if this is correct. Decompiler output was useless so i had to rely on the assembly
// and the assembly was an optimised mess
void OBB2D::computeAxes()
{
    m_obHorizontalDifference = m_obVertexBottomRight - m_obVertexBottomLeft;
    m_obVerticalDifference = m_obVertexTopLeft - m_obVertexBottomLeft;

    cocos2d::CCPoint xAxis = 1.0 / (m_obHorizontalDifference.x * m_obHorizontalDifference.x) + (m_obHorizontalDifference.y * m_obHorizontalDifference.y);
    cocos2d::CCPoint yAxis = 1.0 / (m_obVerticalDifference.x * m_obVerticalDifference.x) + (m_obVerticalDifference.y * m_obVerticalDifference.y);

    // We're using the BottomLeft vertex as the origin for the object
    m_obAxes = { xAxis * m_obVertexBottomLeft, yAxis * m_obVertexBottomLeft };
}