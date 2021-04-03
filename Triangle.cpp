#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle()
{
    xa = 0;
    ya = 0;
    xb = 0;
    yb = 0;
    xc = 0;
    yc = 0;
}

Triangle::Triangle(float a,float b,float c,float d,float e,float f)
{
    xa = a;
    ya = b;
    xb = c;
    yb = d;
    xc = e;
    yc = f;
}

bool Triangle::SetXA(float v)
{
    if (v>=0)
    {
        xa = v;
        return true;
    }
    return false;
}

bool Triangle::SetYA(float v)
{
    if (v>=0)
    {
        ya = v;
        return true;
    }
    return false;
}

bool Triangle::SetXB(float v)
{
    if (v>=0)
    {
        xb = v;
        return true;
    }
    return false;
}

bool Triangle::SetYB(float v)
{
    if (v>=0)
    {
        yb = v;
        return true;
    }
    return false;
}

bool Triangle::SetXC(float v)
{
    if (v>=0)
    {
        xc = v;
        return true;
    }
    return false;
}

bool Triangle::SetYC(float v)
{
    if (v>=0)
    {
        yc = v;
        return true;
    }
    return false;
}

float Triangle::getXA()
{
  return xa;
}

float Triangle::getYA()
{
  return ya;
}

float Triangle::getXB()
{
  return xb;
}

float Triangle::getYB()
{
  return yb;
}

float Triangle::getXC()
{
  return xc;
}

float Triangle::getYC()
{
  return yc;
}

float Triangle::getAB()
{
  float a,b,c,d,result;

  a=getXA();
  b=getYA();
  c=getXB();
  d=getYB();

  result = sqrt( pow((a-c),2) + pow((b-d),2) );
  return result;
}

float Triangle::getAC()
{
  float a,b,c,d,result;

  a=getXA();
  b=getYA();
  c=getXC();
  d=getYC();

  result = sqrt( pow((a-c),2) + pow((b-d),2) );
  return result;
}

float Triangle::getBC()
{
  float a,b,c,d,result;

  a=getXB();
  b=getYB();
  c=getXC();
  d=getYC();

  result = sqrt( pow((a-c),2) + pow((b-d),2) );
  return result;
}

float Triangle::getC()
{
  float a,b,c,cosA;

  a=getAB();
  b=getAC();
  c=getBC();

  cosA=(pow(a,2) - pow(b,2) - pow(c,2))/(-2*b*c);

  return acos(cosA);
}

float Triangle::getB()
{
  float a,b,c,cosB;

  a=getAB();
  b=getAC();
  c=getBC();

  cosB=(pow(b,2) - pow(c,2) - pow(a,2))/(-2*a*c);

  return acos(cosB);
}

float Triangle::getA()
{
  float a,b,c,cosC;

  a=getAB();
  b=getAC();
  c=getBC();

  cosC=(pow(c,2) - pow(b,2) - pow(a,2))/(-2*a*b);

  return acos(cosC);
}

bool Triangle::isIsopleurous()
{
  float a,b,c;

  a=getAB();
  b=getAC();
  c=getBC();

  if(a==b && b==c)
    return true;
  return false;
}

bool Triangle::isIsosceles()
{
  float a,b,c;

  a=getAB();
  b=getAC();
  c=getBC();

  if( (a==b && a!=c) || (a==c &&  a!=b) || (b==c &&  a!=b) )
    return true;
  return false;
}

bool Triangle::isScalino()
{
  float a,b,c;

  a=getAB();
  b=getAC();
  c=getBC();
  if( (a!=b) && (b!=c) && (c=!a) )
    return true;
  return false; 
}

bool Triangle::isOrthogonio()
{
  float a,b,c;

  a=getA()*180/3.14159265;
  b=getB()*180/3.14159265;
  c=getC()*180/3.14159265;

  if (a==90 || b==90 || c==90)
    return true;
  return false;
}

bool Triangle::isOxygonio()
{
  float a,b,c;

  a=getA()*180/3.14159265;
  b=getB()*180/3.14159265;
  c=getC()*180/3.14159265;

  if (a<90 && b<90 && c<90)
    return true;
  return false;
}

bool Triangle::isAmvligonio()
{
  float a,b,c;

  a=getA()*180/3.14159265;
  b=getB()*180/3.14159265;
  c=getC()*180/3.14159265;
  if (a>90 || b>90 || c>90)
    return true;
  return false;
}

float Triangle::getBase()
{
  return getAB();
}

float Triangle::getHeight()
{
  return ( getAC()*sin(getA()) );
}

float Triangle::getArea()
{
  return (getBase()*getHeight())/2;
}
