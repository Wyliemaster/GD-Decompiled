#include "../headers/includes.h"

void OBB2D::calculateOBBWithCenter(cocos2d::CCPoint center, float width, float height, float rotationAngle)
{

    m_obCenter = center;

    float cosAngle = cos(rotationAngle);
    float sinAngle = sin(rotationAngle);

    cocos2d::CCPoint x = cocos2d::CCPoint(cosAngle, sinAngle) * width * 0.5;
    cocos2d::CCPoint y = cocos2d::CCPoint(-sinAngle, cosAngle) * height * 0.5;

    m_obVertexBottomLeft = center - x - y;
    m_obVertexBottomRight = center + x - y;
    m_obVertexTopRight = center + x + y;
    m_obVertexTopLeft = center - x + y;

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

bool OBB2D::init(cocos2d::CCPoint center, float width, float height, float rotationAngle)
{
    if (cocos2d::CCNode::init())
    {
        calculateOBBWithCenter(center, width, height, rotationAngle);
        return true;
    }
    return false;
}

cocos2d::CCRect OBB2D::getBoundingRect()
{
    float x_start = 0;
    float x_end = 0;
    float y_start = 0;
    float y_end = 0;

    // Member variables after this are also vertices. Treating this
    // as an array and making the first vertex the base.
    cocos2d::CCPoint* vertices = &m_obVertexBottomLeft;
    for (int i = 0; i < 4; i++)
    {
        cocos2d::CCPoint vertex = vertices[i];

        if (vertex.x > x_end)
        {
            x_end = vertex.x;
        }

        if (vertex.x >= x_start && x_start == 0.0f)
        {
            x_start = vertex.x;
        }
        else if (vertex.x < x_start)
        {
            x_start = vertex.x;
        }

        if (vertex.y > y_end)
        {
            y_end = vertex.y;
        }

        if (vertex.y >= y_start && y_start == 0.0f)
        {
            y_start = vertex.y;
        }
        else if (vertex.y < y_start)
        {
            y_start = vertex.y;
        }
    }

    return { x_start, y_start, x_end, y_end };
}

// Another weird one. Should be close enough?
bool OBB2D::overlaps1Way(OBB2D* other)
{
    for (int i = 0; i < 2; i++)
    {
        float origin = (this->m_obVertexBottomLeft.x * this->m_obAxes.x) + (other->m_obVertexBottomLeft.y * this->m_obAxes.y);

        float dot = (other->m_obVertexBottomLeft.x * this->m_obAxes.x) + (other->m_obVertexBottomLeft.y * this->m_obAxes.y);

        float min = dot;
        float max = dot;

        // Checking each corder to get a range for the dot prouct
        for (int c = 1; c < 4; c++)
        {
            cocos2d::CCPoint vertex = &other->m_obVertexBottomLeft[c];

            dot = (vertex.x * this->m_obAxes.x) + (vertex.y * this->m_obAxes.y);

            if (dot < min)
            {
                min = dot;
            }

            if (dot > max)
            {
                max = dot;
            }
        }

        if (min > origin + 1)
        {
            return false;
        }
        if (max < origin)
        {
            return false;
        }
        return true;
    }
}

bool OBB2D::overlaps(OBB2D* other)
{
    if (this->overlaps1Way(other))
    {
        return other->overlaps1Way(this);
    }
}

// Prolly one of the most confusing functions in this class
void OBB2D::orderCorners()
{
    cocos2d::CCPoint VertexStart = m_obVertexBottomLeft;
    cocos2d::CCPoint UnknownStackValue(0, 0);

    for (int i = 0; i < 4; i++)
    {
        float VertexStartY = m_obVertexBottomLeft[i].y;
        if (VertexStart.y <= UnknownStackValue.y)
        {
            if (m_obVertexBottomLeft.y >= VertexStart.y || m_obVertexBottomLeft.x < VertexStart.x)
            {
                VertexStart = m_obVertexBottomLeft[i];
            }
        }
        else
        {
            VertexStart = UnknownStackValue;
            m_obVertexBottomLeft[i] = VertexStart;
        }

    }
    // Head is too battered, will finish later
}