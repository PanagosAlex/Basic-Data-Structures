class Triangle
{
    private:
        float xa,ya,xb,yb,xc,yc;
    public:
      Triangle();//
      Triangle (float,float,float,float,float,float);//

    bool SetXA(float);//
    bool SetYA(float);//
    bool SetXB(float);//
    bool SetYB(float);//
    bool SetXC(float);//
    bool SetYC(float);//

    float getXA();//
    float getYA();//
    float getXB();//
    float getYB();//
    float getXC();//
    float getYC();//

    float getAB();//
    float getAC();//
    float getBC();//

    float getA();//
    float getB();//
    float getC();//

    bool isIsopleurous();//
    bool isIsosceles();//
    bool isScalino();//

    bool isOrthogonio();
    bool isOxygonio();
    bool isAmvligonio();

    float getBase();//
    float getHeight();//
    float getArea();//
};