#pragma once
#include<iostream>
#include<string>

using namespace std;

class Body {
public:
    std::string name;

    bool isStatic = false;
      
    float mass = 1;
    
    float oneDivMass = 1;
    
    float impulseCoefficient = 1;
   
   /* Matrix4 inertia;
      
    Matrix4 inertiaInverse;*/
    
    float linearFrictionCoefficient = 0.3;
    
    /*RigidData datas[RDI_count];*/
};